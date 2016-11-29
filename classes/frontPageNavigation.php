<?php if (file_exists($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php')) require($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php'); ?><?php
class mosPageNav 
{
	/** @var int The record number to start dislpaying from */
	var $limitstart = null;
	/** @var int Number of rows to display per page */
	var $limit 		= null;
	/** @var int Total number of rows */
	var $total 		= null;
	/** @var form name of the requested page */
	var $form_name 	= null;

	function mosPageNav( $total, $limitstart, $limit, $form_name, $k='')
	{
		$this->total 		= (int) $total;
		$this->limitstart 	= (int) max( $limitstart, 0 );
		$this->limit 		= (int) max( floor($limit), 1 );
		$this->k 			= $k;
		$this->form_name 	= $form_name;
		if ($this->limit > $this->total) {
			$this->limitstart = 0;
		}
		if (($this->limit-1)*$this->limitstart > $this->total) {
			$this->limitstart -= $this->limitstart % $this->limit;
		}
	}

	/*** @return string The html for the limit # input box ***/
	function getLimitBox ()
	{
		$limits = array();

		// build the html select list
		
		$html .= "\n<input type=\"hidden\" name=\"limitstart\" value=\"$this->limitstart\" />";
		$html .= "\n<input type=\"hidden\" name=\"k\" value=\"$this->k\" />";
		return $html;
	}

	/*** Writes the html limit # input box ***/
	function writeLimitBox ()
	{
		echo mosPageNav::getLimitBox();
	}

	function writePagesCounter()
	{
		echo $this->getPagesCounter();
	}

	/*** @return string The html for the pages counter, eg, Results 1-10 of x ***/
	function getPagesCounter()
	{
		$html = '';
		$from_result = $this->limitstart+1;
		if ($this->limitstart + $this->limit < $this->total) {
			$to_result = $this->limitstart + $this->limit;
		} else {
			$to_result = $this->total;
		}
		if ($this->total > 0) {
			//$html .= "\nResults " . $from_result . " - " . $to_result . " of " . $this->total;
			$html .= "";
		} else {
			$html .= "";
		}
		return $html;
	}

	/*** Writes the html for the pages counter, eg, Results 1-10 of x ***/
	function writePagesLinks()
	{
		echo $this->getPagesLinks();
	}

	/*** @return string The html links for pages, eg, previous, next, 1 2 3 ... x ***/
	function getPagesLinks()
	{
		$html 				= '';
		$displayed_pages 	= 10;
		$total_pages 		= ceil( $this->total / $this->limit );
		$this_page 			= ceil( ($this->limitstart+1) / $this->limit );
		$start_loop 		= (floor(($this_page-1)/$displayed_pages))*$displayed_pages+1;
		if ($start_loop + $displayed_pages - 1 < $total_pages) {
			$stop_loop = $start_loop + $displayed_pages - 1;
		} else {
			$stop_loop = $total_pages;
		}
		if ($this_page > 1) {
			$page = ($this_page - 2) * $this->limit;
		$html .= "\n&nbsp;&nbsp;<a href='#prev' title='Previous page' onclick='javascript: document.".$this->form_name.".limitstart.value=$page; document.".$this->form_name.".submit();return false;'><img src='images/prev.png'>&nbsp;Prev</a>&nbsp;";
		} else {
			$html .= "<span class='pagenav'><font style='color:#CCCCCC'></font></span>";
		}

		for ($i=$start_loop; $i <= $stop_loop; $i++){
			$page = ($i - 1) * $this->limit;
			if ($i == $this_page) {
				$html .= "\n<span><font style='font-size:12px;background-color:#fff;border:1px solid #dfc7f4; color:#000;'>&nbsp;$i&nbsp;</font></span>&nbsp;";
			} else {
				$html .= "\n<a href='#$i' onclick='javascript: document.".$this->form_name.".limitstart.value=$page; document.".$this->form_name.".submit();return false;'>$i</a>&nbsp;";
			}
		}

		if ($this_page < $total_pages) {
			$page = $this_page * $this->limit;
			$end_page = ($total_pages-1) * $this->limit;
			$html .= "\n&nbsp;<a href='#next' title='Next page' onclick='javascript: document.".$this->form_name.".limitstart.value=$page; document.".$this->form_name.".submit();return false;'>Next&nbsp;<img src='images/next.png'></a>&nbsp;";

		} else {
			$html .= "\n<span class=\"pagenav\"><font style='color:#CCCCCC'></font></span>";
		}
		return $html;
	}

	function getListFooter()
	{
		global $limit;
		$display='';	
		if($this->getPagesCounter()=='No records found.'){
			$display='';
		}
				$html=' <div id="bottom-links">'.$this->getLimitBox().'<div class="paging_l"><span>'.$display.' '.$this->getPagesCounter().'</span></div><div class="paging_r">'.$this->getPagesLinks().'</div></div>';

		return $html;
	}
	
	/*** @param int The row index 
	@return int
	*/
	function rowNumber($i)
	{
		return $i + 1 + $this->limitstart;
	}
	/**
	* @param int The row index
	* @param string The task to fire
	* @param string The alt text for the icon
	* @return string
	*/
	function orderUpIcon( $i, $condition=true, $task='orderup', $alt='Move Up')
	{
		if (($i > 0 || ($i+$this->limitstart > 0)) && $condition) {
			return '<a href="#reorder" onClick="return listItemTask(\'cb'.$i.'\',\''.$task.'\')" title="'.$alt.'">
				<img src="images/uparrow.png" width="12" height="12" border="0" alt="'.$alt.'">
			</a>';
  		} else {
  			return '&nbsp;';
		}
	}
/**
* @param int The row index
* @param int The number of items in the list
* @param string The task to fire
* @param string The alt text for the icon
* @return string
*/
	function orderDownIcon( $i, $n, $condition=true, $task='orderdown', $alt='Move Down')
	{
		if (($i < $n-1 || $i+$this->limitstart < $this->total-1) && $condition) {
			return '<a href="#reorder" onClick="return listItemTask(\'cb'.$i.'\',\''.$task.'\')" title="'.$alt.'">
				<img src="images/downarrow.png" width="12" height="12" border="0" alt="'.$alt.'">
			</a>';
  		} else {
  			return '&nbsp;';
		}
	}

	/**
	 * @param int The row index
	 * @param string The task to fire
	 * @param string The alt text for the icon
	 * @return string
	 */
	function orderUpIcon2( $id, $order, $condition=true, $task='orderup', $alt='#')
	{
		// handling of default value
		if ($alt = '#') {
			$alt = 'Move Up';
		}

		if ($order == 0) {
			$img = 'uparrow0.png';
			$show = true;
		} else if ($order < 0) {
			$img = 'uparrow-1.png';
			$show = true;
		} else {
			$img = 'uparrow.png';
			$show = true;
		};
		if ($show) {
			$output = '<a href="#ordering" onClick="listItemTask(\'cb'.$id.'\',\'orderup\')" title="'. $alt .'">';
			$output .= '<img src="images/' . $img . '" width="12" height="12" border="0" alt="'. $alt .'" title="'. $alt .'" /></a>';

			return $output;
   		} else {
  			return '&nbsp;';
		}
	}

	/**
	 * @param int The row index
	 * @param int The number of items in the list
	 * @param string The task to fire
	 * @param string The alt text for the icon
	 * @return string
	 */
	function orderDownIcon2( $id, $order, $condition=true, $task='orderdown', $alt='#' ) {
		// handling of default value
		if ($alt = '#') {
			$alt = 'Move Down';
		}

		if ($order == 0) {
			$img = 'downarrow0.png';
			$show = true;
		} else if ($order < 0) {
			$img = 'downarrow-1.png';
			$show = true;
		} else {
			$img = 'downarrow.png';
			$show = true;
		};
		if ($show) {
			$output = '<a href="#ordering" onClick="listItemTask(\'cb'.$id.'\',\'orderdown\')" title="'. $alt .'">';
			$output .= '<img src="images/' . $img . '" width="12" height="12" border="0" alt="'. $alt .'" title="'. $alt .'" /></a>';

			return $output;
  		} else {
  			return '&nbsp;';
		}
	}

	/*** Sets the vars for the page navigation template ***/
	function setTemplateVars( &$tmpl, $name = 'admin-list-footer')
	{
		$tmpl->addVar( $name, 'PAGE_LINKS', $this->getPagesLinks() );
		$tmpl->addVar( $name, 'PAGE_LIST_OPTIONS', $this->getLimitBox() );
		$tmpl->addVar( $name, 'PAGE_COUNTER', $this->getPagesCounter() );
	}
}
?>