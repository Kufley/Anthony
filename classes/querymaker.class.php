<?php require_once("db.class.php");
class CLSQueryMaker
{
	var $db_last="";
	var $strHostLink;
	var $strUsername;
	var $strPassWord;
	var $strDatabaseName;
	var $mySql;	
	var $strErrorMessage;

	/**

		* CLSQueryMaker()			: Constructor of the class
		* 
		* @param $strpHost			: Host to connect
		* @param $strpUserName		: User name to connect
		* @param $strpUserName		: User name to connect	
		* @param $strpPassword		: User password to connect	
		* @param $strpDatabaseName	: Name of the database
		* @return 
	**/
		function CLSQueryMaker($strpHost, $strpUserName, $strpPassword, $strpDatabaseName){
			$this->strHostLink = $strpHost;
			$this->strUsername = $strpUserName;
			$this->strPassWord = $strpPassword;
			$this->strDatabaseName = $strpDatabaseName; 
			$this->mySql =  new CLSMySql($this->strHostLink, $this->strUsername, $this->strPassWord, $this->strDatabaseName);
		}

	/**
		 * mysqlSelect()     : make a mysql select
		 * @param $fields     : list of field to select
		 * @param $tables     : list names of the tables
		 * @param $where      : where condition
		 * @param $order_by   : fields to be ordered by
		 * @param $group_by   : fields to be groupered by
		 * @param $having     : having condition
		 * @param $limit      : limit clause
		 * @return 
	 */

		function mysqlSelect($fields,$tables,$where="",$order_by="",$group_by="",$having="",$limit="") {
			$sql="SELECT $fields FROM $tables ";
			if (!empty($where)) $sql.="WHERE $where ";  
			if (!empty($group_by)) $sql.="GROUP BY $group_by ";  
			if (!empty($order_by)) $sql.="ORDER BY $order_by ";  
			if (!empty($having)) $sql.="HAVING $having ";  
			if (!empty($limit)) $sql.="LIMIT $limit ";
			// this will echo the query in admin only
			//echo "<br>".$sql ;
			
			if(strstr($_SERVER['PHP_SELF'],'index.php'))
			{
				//echo "<br>".$sql; 
			}
			if(strstr($_SERVER['PHP_SELF'],'printing-publishing-services.php'))
			{
				//echo "<br>".$sql; 
			}
			if(strstr($_SERVER['PHP_SELF'],'contactus.php'))
			{
				//echo "<br>".$sql; 
			}
			if(strstr($_SERVER['PHP_SELF'],'search_results.php'))
			{
				//echo "<br>".$sql; 
			}
			if(strstr($_SERVER['PHP_SELF'],'artical.php'))
			{
				//echo "<br>".$sql; 
			}

			return $this->mysqlRawquery($sql);
		}

		/**
			 * mysqlInsert()				: make a mysql insert
			 * @param $table				: name of the table
			 * @param $liste_champs			: array of the field to insert
			 * @param $liste_valeur			: array of the valued of the field to insert
			 * @return 
		 */

		function mysqlInsert($table,$liste_champs,$liste_valeur,$debug=0) {
			$sql="INSERT INTO `$table` ";
			if (count($liste_champs)==count($liste_valeur)+1) // have to find next_id and insert in $liste_valeur
			array_unshift($liste_valeur,$this->mysqlNextIndex($liste_champs[0],$table));
			$temp1=implode("`,`",$liste_champs);
			$temp2=implode("','",$liste_valeur);
			$sql.="(`$temp1`) VALUES ('$temp2')";
			//echo $sql; die;
			if(strstr($_SERVER['PHP_SELF'],'resume_improvement1.php'))
			{
				//echo $sql;
				//die;
			}
			if($debug=="1"){}
//echo $sql; die();
			return $this->mysqlRawquery($sql);
		}
		
		/**
			 * mysqlUpdate()                  : make a mysql update
			 * @param $table				  : name of the table
			 * @param $liste_champs	          : array of the field to update
			 * @param $liste_valeur	          : array of the valued of the field to update
			 * @param $where				  : where condition
			 * @return 
		 */
		function mysqlUpdate($table,$liste_champs,$liste_valeur,$where,$ipid='') {
			if ($where!="") {
				$sql="UPDATE `$table` SET ";
				for ($i=0;$i<count($liste_champs);$i++)
					$sql.="`".$liste_champs[$i]."`='".$liste_valeur[$i]."'".(($i==count($liste_champs)-1)?"":" , ");
				  $sql.=" WHERE $where";
				//echo $sql."<br>";  die;
			if(strstr($_SERVER['PHP_SELF'],'cabadmin'))
			{
				//echo $sql; die;
			}
            if($ipid=="1"){  }
				return $this->mysqlRawquery($sql);
			}
		}
		
		function mysqlUpdateOneEntry($table,$liste_champs,$liste_valeur,$where,$ipid='') {
				$sql="UPDATE `$table` SET ";
				for ($i=0;$i<count($liste_champs);$i++)
					$sql.="`".$liste_champs[$i]."`='".$liste_valeur[$i]."'".(($i==count($liste_champs)-1)?"":" , ");
				return $this->mysqlRawquery($sql);
		}

		/**
			* mysqlDelete()			: make a mysql delete query
			* @param $table			    : name of the table
			* @param $where			    : where condition
			* @return 
		 */
		function mysqlDelete($table,$where) {
			if ($where!="") 
			{
				$sql="DELETE FROM `$table` WHERE ($where)";
			//	echo $sql; die;
				return $this->mysqlRawquery($sql);
			}
		}
		
		function mysqlTruncated($table) {
			$sql="TRUNCATE TABLE `$table`";
			//echo $sql; die;
			return $this->mysqlRawquery($sql);
		}

		
		/**
		 * mysqlRawquery()			: make a mysql query
		 * 
		 * @param $db_base			: database to access
		 * @param $query			: query to launch
		 * @return 
	 */
		function mysqlRawquery($query) {
			if(!$this->mySql->dbConnect()){
				$this->strErrorMessage = $this->mySql->getErrorMessage();
				return false;
			}else{
			}
			if(!$this->mySql->dbExecuteQuery($query)){					
				$this->strErrorMessage = $this->mySql->getErrorMessage();
				return false;
			}
			if (strtoupper(substr($query,0,6))=="SELECT"){
				$db_result=$this->mySql->dbFetchResult();
				return $db_result;
			}
			return true;
		}
	

	
		function mysqlAffected(){
			return $this->mySql->dbGetAffectedRows();
		}

		function mysqlCountRows(){
			return $this->mySql->dbGetNumRows();
		}

		
		//  Created by : Kushal Puri
		//   mysqlMultipleInsert()				: make a mysql insert multiple entries using single insert query
		//  to insert multiple values using one singe insert query
		//  e.g. INSERT INTO `tableName` (Field1,Field2) VALUES ('Value1','Value12'),('Value3','Value4'),('Value5','Value6');
		//  @param table ='table name' 
		//  @param liste_champs  = column names in  1 D array
		//  @param liste_valeur  = column values in 2d array
		
		function mysqlMultipleInsert($table,$liste_champs,$liste_valeur) {
			$i=0;
			$sql="INSERT INTO `$table` ";
			$temp1=implode(",",$liste_champs);
			$sql.="($temp1) VALUES ";			
			foreach($liste_valeur as $k=>$v) {
				$sql .= "('".implode("','",$v)."')";				
				$i++;
			  if(count($liste_valeur) > $i)
				$sql .= ",";
			}
			return $this->mysqlRawquery($sql);
		}

		

		/**
			 * mysqlNextIndex()		: find the most free little index of the table
			 * @param $index			: the name of the index column
			 * @param $table			: name of the table
			 * @return 
		 */

		function mysqlNextIndex($index,$table) {
			$tab=$this->mysqlRawquery("SELECT $index FROM $table ORDER BY $index DESC LIMIT 0,1");
			if (count($tab)==0)
				return 0;
			else
				return $tab[0][$index]+1;
		}


		/**

			 * mysqlSelectDiff()	: make a select a,b,c,d from table1 where (a not in select a from table2 where ())and/or()
			 * @param $db_base			: database to access
			 * @param $query_plus		: select of the lines we want
			 * @param $query_moins: !! select of the lines we don't want (!! 1 column only)
			 * @return
		 */

		function mysqlSelectDiff($query_plus,$query_moins) {

			$tab_plus=$this->mysqlRawquery($query_plus);

			if ($query_moins!="") {

				$tab_moins=$this->mysqlRawquery($query_moins);

				if (count($tab_moins)>0) {	

					$keys1=array_keys($tab_plus[0]);

					$keys2=array_keys($tab_moins[0]);

					for ($i=0,$res=array();$i<count($tab_plus);$i++) {

						for ($j=0,$find=false;$j<count($tab_moins);$j++)

							if ($tab_moins[$j][$keys2[0]]==$tab_plus[$i][$keys1[0]])

								$find=true;

						if (!$find)

							$res[]=$tab_plus[$i];

					}

					return $res;

				}

				else

					return $tab_plus;
			}

			else

				return $tab_plus;

		}

		/**

			 * mysqlSelectValue()
			 * @param $query      : la requete avec seuleument 1 colonne selectionn�!!
			 * @param $default    : default value to return if query return null result
			 * @return la valeur retourn� en ligne 0 de la requete.
	    */

		function mysqlSelectValue($query,$default="") {
			$tab=$this->mysqlRawquery($query." LIMIT 0,1");
			if (count($tab)==1) {
				$keys=array_keys($tab[0]);	
				return $tab[0][$keys[0]];
			}else{
				return $default;
			}
		}

		function mysqlFreeResult(){
			$this->mySql->dbFreeResult();
		}

		function mysqlLastId(){
			return $this->mySql->dbGetLastId();
		}

		function getErrorMessage(){
			return $this->strErrorMessage;
		}
}#Class Ends Here


