<script language="javascript" type="text/javascript">
//START - OPEN ALL POPUP JS//
	/*if(window.location.host=='server'){
		var DOC_ROOT=	"http://server/Anthony-wilson-rd/";
	}
	else if(window.location.host=='www.weightlosshappens.com' || window.location.host=='weightlosshappens.com'){
		var DOC_ROOT=	"http://weightlosshappens.com/";
	}
	else {
		 if (location.href.indexOf("www.") != -1)
			var DOC_ROOT=	"http://www.showprojects.net/projects/anthonywilsonrd/";
		 else
		 	var DOC_ROOT=	"http://showprojects.net/projects/anthonywilsonrd/";
		 	
	}*/
var DOC_ROOT=	"http://" + window.location.host + "/";//anthony/

	function adjustFadeWithDocHeightAndDataOnFadeHeight(dataDiv,fadeDiv){
		var dataDivH=$('#'+dataDiv).height()+100;
		var docH=$(document).height();
		if(dataDivH>=docH)
			$('#'+fadeDiv).css({'height':dataDivH+'px'});
	}
	
	function openPopup(fadeDiv,fadeZindex,fadeClass,dataDiv,dataDivZindex,dataClass,openPopupFor,ajaxFileName){
		var ajaxFile='popup_htmls.php';
		createDiv(fadeDiv,'fade',parseInt(fadeZindex),true,true,fadeClass);
		$('#'+fadeDiv).show();
	 	
		createDiv(dataDiv,'',parseInt(dataDivZindex),true,true,dataClass);
		$('#'+dataDiv).show();
	 	$('#'+dataDiv).html(pleaseWaitHtml('pleaseWaitHtml'));

        var WH=dGetScreenWH();
        //alert(WH.dWidth+'-'+WH.dHeight);
        var availW=WH.dWidth;
        $('#'+dataDiv).css('width', availW - 100 + 'px');


		dDisplayDivInCenter(dataDiv,0,0);	
		
		if(typeof ajaxFileName!='undefined')
			 ajaxFile=ajaxFileName;
//		alert(DOC_ROOT);
$.ajax(DOC_ROOT+'popup_manager/popup_htmls/'+ajaxFile, {data: {open_poup_for:openPopupFor}, dataType: 'html', success: function(data){
			$('#'+dataDiv).html(data);
    dDisplayDivInCenter(dataDiv,0,0);
    $('#'+dataDiv + ' .content').css('width', availW - 100 + 'px');
    adjustFadeWithDocHeightAndDataOnFadeHeight(dataDiv,fadeDiv);

}});
return;
		$.get(DOC_ROOT+'popup_manager/popup_htmls/'+ajaxFile,{open_poup_for:openPopupFor},function(data){
alert('received');
console.log(data);
			$('#'+dataDiv).html(data);
			dDisplayDivInCenter(dataDiv,0,0);
			adjustFadeWithDocHeightAndDataOnFadeHeight(dataDiv,fadeDiv);
		});
		
	}
	
	function closeOpenedPopup(closeAllDivs){
		
		var allDivs=closeAllDivs.split(',');
		for(var i=0;i<allDivs.length;i++){
			if($('#'+jQuery.trim(allDivs[i])).length)
				removeDiv(allDivs[i]);
		}
		if(typeof allDivs[2]!='undefined')
		 window.location = '#'+allDivs[2];
	}
	
</script>
