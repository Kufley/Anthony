<?php
// MAIN SIGNATURE FILE
// ISSUE 75
// COMPATIBLE WITH ZB Block 0.4.10a3 and up
// FROM HTTP://WWW.SPAMBOTSECURITY.COM
// COPYRIGHT 2008-2013 GNU/GPL V.2 BY MIKE H.

$zbbversion .= ' / 75';

// php 5.x fix
global $whyblockout, $ax ;

// overlooked variable generation, will be added to 0.4.10b

if(empty($requesturidec)){$requesturidec = urldecode($requesturi);}

$serialpost = substr(serialize($_POST), 0, 65535);

//New Super %25 stripping code added in 74a

$dblrequesturidec = '';
$dblrequesturidec = $requesturidec ;
while(substr_count($dblrequesturidec,'%25') > 0){
$dblrequesturidec=str_replace('%25','%',$dblrequesturidec);
}
$dblrequesturidec = urldecode($dblrequesturidec);
$dblrequesturidec = strtolower($dblrequesturidec); //74e fix

// Filescan Module. added in 72a .
// With much thanks to D. MacMathan, MickeyRoush, and my users,
// without whom I couldn't develop this fine software.

$zbfiledatcomplc = "";
$zbfiledatdec = "";
$zbfiledat = "";

// To turn off filescan, change one of the 1s to a 0 on the next line.

if ((!empty($_FILES)) && ("1" == "1")){

// Function by pal dot sch at gmx dot de, found at http://www.php.net/manual/en/function.array-search.php#109720
// recursive search for key in nested array, also search in objects!!
// returns: array with "values" for the searched "key"

function search_nested_arrays($array, $key){
    if(is_object($array))
        $array = (array)$array;
    // search for the key
    $result = array();
    foreach ($array as $k => $value) {
        if(is_array($value) || is_object($value)){
            $r = search_nested_arrays($value, $key);
            if(!is_null($r))
                array_push($result,$r);
        }
    }
    if(array_key_exists($key, $array))
        array_push($result,$array[$key]);
    if(count($result) > 0){
        // resolve nested arrays
        $result_plain = array();
        foreach ($result as $k => $value) {
            if(is_array($value))
                $result_plain = array_merge($result_plain,$value);
            else
                array_push($result_plain,$value);
        }
        return $result_plain;
    }
    return NULL;
}

$zbuploadarray = search_nested_arrays($_FILES, "tmp_name");

$zbulfna = search_nested_arrays($_FILES, "name");

foreach($zbulfna as $zbulk => $zbulfn) {
  $ax += rmatch($zbulfn,'.','File name attack. Nasty hot INSTA-BAN coming your way. (FILE-NAME-01). ');
  $ax += lmatch($zbulfn,'.','File name attack. Nasty hot INSTA-BAN coming your way. (FILE-NAME-02). ');
}

foreach($zbuploadarray as $zbuploadkey => $zbuploadfilename) {
  if($zbuploadfilename) {
    if(!(inmatch($zbuploadfilename,"://",""))){
      $zbfiledat = file_get_contents($zbuploadfilename) ;
   }
  } else {
   continue;
  }

// *File Scans

// ** SECTION 1: RAW filescans **

// UTF-7 Attack (covers +AFs-,+AF0-,+AGA-,+ACI-,+ADs-,+ADw-,+AD4-,+AHs-,+AH0-, U+003C, and U+003E)
$ax += regexmatch($zbfiledat,"(?:\+A(?:CI|D[sw4]|[FH][s0]|GA)-|U\+003[EC])","UTF-7 attack with dangerous UTF-7 entities in file (FILE-UTF-7). "); //73b

// XSS in File Attacks
$ax += regexmatch($zbfiledat,"(?:(?:\'|\"|\%2[27])[\s+]*on(?:blur|bounce|(?:cell|filter)?change|click|contextmenu|controlselect|copy|cut|data|dblclick|deactivate|drag|drop|error|finish|focus|help|key(?:down|press|up))[\s+]*(?:\'|\"|\%2[27]))","XSS attack (or similar Javascript exploit attempt) in file (FILE-XSS-01)). "); //73b
$ax += regexmatch($zbfiledat,"(?:[<]|\%3C|¼)[\s+]*(?:about|activex|applet|base(?:font)?|background|bgsound|blink|body|chrome|embed|i?frame(?:set)?|head|html?|i?layer|input|link|meta|object|script|src|style|title|xml)[\s+]*(?:[>]|\%3E|¾)","XSS attack (or similar Javascript exploit attempt) in file (FILE-XSS-02). "); //73b
$ax += inmatch($zbfiledat,"FilesMan","Hack Detection (FILE-0009). "); //72a

// ** SECTION 2: RAW -> URL decoded filescans **

$zbfiledat = urldecode($zbfiledat); //adjust scanning variable


// ** SECTION 3: RAW -> URL decoded -> Spaces Removed filescans **

$zbfiledat = str_replace(" ","",$zbfiledat); //adjust scanning variable


// ** SECTION 4: RAW -> URL decoded -> Spaces Removed -> Lowercased filescans **

$zbfiledat = strtolower($zbfiledat); //adjust scanning variable

$ax += inmatch($zbfiledat,"<?php","php program file upload not allowed (FILE-0001). "); //72a
$ax += inmatch($zbfiledat,"code(","php command in file (FILE-0002). "); //72a Catches most encodes, and decodes
$ax += inmatch($zbfiledat,'include(','php command in file (FILE-0003). '); //72a
$ax += inmatch($zbfiledat,"include'",'php command in file (FILE-0003.1). '); //72b
$ax += inmatch($zbfiledat,'include"','php command in file (FILE-0003.2). '); //72b
$ax += inmatch($zbfiledat,'include$','php command in file (FILE-0003.3). '); //74b
$ax += inmatch($zbfiledat,'include<','php command in file (FILE-0003.4). '); //74b
$ax += inmatch($zbfiledat,'require(','php command in file (FILE-0004). '); //72a
$ax += inmatch($zbfiledat,'require"','php command in file (FILE-0004.1). '); //72b
$ax += inmatch($zbfiledat,"require'",'php command in file (FILE-0004.2). '); //72b
$ax += inmatch($zbfiledat,'require$','php command in file (FILE-0004.3). '); //74b
$ax += inmatch($zbfiledat,'require<','php command in file (FILE-0004.4). '); //74b
$ax += inmatch($zbfiledat,'get_contents(','php command in file (FILE-0005). '); //72a
$ax += inmatch($zbfiledat,'eval(','php command in file (FILE-0006). '); //72a
$ax += inmatch($zbfiledat,'inflate(','php command in file (FILE-0007). '); //72a
$ax += inmatch($zbfiledat,'compress(','php command in file (FILE-0008). '); //72a
$ax += inmatch($zbfiledat,'assert(','php command in file (FILE-0010). '); //72b
$ax += regexmatch($zbfiledat,"apache_[a-z0-9_]{4,16}\(",'php function in file (FILE-0011). '); //73d
$ax += regexmatch($zbfiledat,"apc_[a-z0-9_]{3,16}\(",'php function in file (FILE-0012). '); //73d
$ax += regexmatch($zbfiledat,"curl_[a-z0-9_]{4,10}\(",'php function in file (FILE-0013). '); //73d
$ax += regexmatch($zbfiledat,"ftp_[a-z0-9_]{3,7}\(",'php function in file (FILE-0014). '); //73d
$ax += regexmatch($zbfiledat,"mysqli_[a-z0-9_]{4,9}\(",'php function in file (FILE-0015.0). '); //73d
$ax += regexmatch($zbfiledat,"mysqli::[a-z0-9_]{4,9}\(",'php function in file (FILE-0015.1). '); //73d
$ax += regexmatch($zbfiledat,"mysql_[a-z0-9_]{4,9}\(",'php function in file (FILE-0015.2). '); //73d
$ax += regexmatch($zbfiledat,"phpads_[a-z0-9_]{4,12}\(",'php function in file (FILE-0016). '); //73d
$ax += regexmatch($zbfiledat,"posix_[a-z0-9_]{4,19}\(",'php function in file (FILE-0017). '); //73d
$ax += regexmatch($zbfiledat,"proc_[a-z0-9_]{4,10}\(",'php function in file (FILE-0018). '); //73d
$ax += inmatch($zbfiledat,'parse_ini_file(','php function in file (FILE-0019). '); //72a
$ax += inmatch($zbfiledat,'symlink(','php function in file (FILE-0020). '); //72a
$ax += inmatch($zbfiledat,'passthru(','php command in file (FILE-0021). '); //72a
$ax += inmatch($zbfiledat,'system(','php command in file (FILE-0022). '); //72a
$ax += inmatch($zbfiledat,'exec(','php command in file (FILE-0023). '); //72a
$ax += inmatch($zbfiledat,'open(','php command in file (FILE-0024). '); //72a
$ax += inmatch($zbfiledat,'forcetype','core htaccess directive in file (FILE-0025). '); //72a
$ax += inmatch($zbfiledat,'sethandler','core htaccess directive in file (FILE-0026). '); //72a
$ax += inmatch($zbfiledat,'setinputfilter','core htaccess directive in file (FILE-0027). '); //72a
$ax += inmatch($zbfiledat,'addhandler','mod_mime htaccess directive in file (FILE-0028). '); //72a
$ax += inmatch($zbfiledat,'addtype','mod_mime htaccess directive in file (FILE-0029). '); //72a
$ax += inmatch($zbfiledat,'addinputfilter','mod_mime htaccess directive in file (FILE-0030). '); //72a
$ax += inmatch($zbfiledat,'rewriterule','mod_rewrite htaccess directive in file (FILE-0031). '); //72a
$ax += inmatch($zbfiledat,'rewritecond','mod_rewrite htaccess directive in file (FILE-0032). '); //72a
$ax += inmatch($zbfiledat,'execcgi','options htaccess directive in file (FILE-0033). '); //72a
$ax += inmatch($zbfiledat,'replace(','php command in file (FILE-0034). '); //72a
$ax += inmatch($zbfiledat,'echo(','php command in file (FILE-0035). '); //72a
$ax += inmatch($zbfiledat,'print(','php command in file (FILE-0036). '); //72a
$ax += inmatch($zbfiledat,'printf(','php command in file (FILE-0037). '); //72a
$ax += inmatch($zbfiledat,'print_r(','php command in file (FILE-0038). '); //72a
$ax += inmatch($zbfiledat,'$globals','php superglobal in file (FILE-0039). '); //72a
$ax += inmatch($zbfiledat,'$_get','php superglobal in file (FILE-0040). '); //72a
$ax += inmatch($zbfiledat,'$_post','php superglobal in file (FILE-0041). '); //72a
$ax += inmatch($zbfiledat,'$_files','php superglobal in file (FILE-0042). '); //72a
$ax += inmatch($zbfiledat,'$_server','php superglobal in file (FILE-0043). '); //72a
$ax += inmatch($zbfiledat,'$_request','php superglobal in file (FILE-0044). '); //72a
$ax += inmatch($zbfiledat,'$_session','php superglobal in file (FILE-0045). '); //72a
$ax += inmatch($zbfiledat,'$_cookie','php superglobal in file (FILE-0046). '); //72a
$ax += inmatch($zbfiledat,'$_env','php superglobal in file (FILE-0047). '); //72a
$ax += inmatch($zbfiledat,'$http_raw_post_data','php superglobal in file (FILE-0048). '); //72a
$ax += inmatch($zbfiledat,'hex2bin(','php command in file (FILE-0049). '); //72a
$ax += inmatch($zbfiledat,'function(','php command in file (FILE-0050). '); //72b
$ax += inmatch($zbfiledat,'unserialize(','php command in file (FILE-0051). '); //72b
$ax += inmatch($zbfiledat,'dotnet_load(','php command in file (FILE-0052). '); //72b
//$ax += inmatch($zbfiledat,'$_GET[','php command in file (FILE-0053). '); //72b 73b Removed, superset of (FILE-0040)
//$ax += inmatch($zbfiledat,'code(','php command in file (FILE-0052). '); //73d 74b Removed, redundant. Thanks Carbonize.
$ax += inmatch($zbfiledat,"'uploadedfile'","No probing allowed (FILE-0053). "); //73f
$ax += inmatch($zbfiledat,"'move_uploaded_file'","No probing allowed (FILE-0054). "); //73f
$ax += inmatch($zbfiledat,"'tmp_name'","No probing allowed (FILE-0055). "); //73f
$ax += inmatch($zbfiledat,'linkirc','Shell upload attempt (FILE-0057). '); //73f
$ax += inmatch($zbfiledat,'http_cmd','Shell upload attempt (FILE-0058). '); //74b
$ax += inmatch($zbfiledat,'http_sum','Shell upload attempt (FILE-0059). '); //74b
$ax += inmatch($zbfiledat,'@$_['.']=@!+_','Shell upload attempt (FILE-0060.0). '); //74e mod 75d
$ax += inmatch($zbfiledat,'$_['.'$__','Shell upload attempt (FILE-0060.1). '); //74e mod 75d

// ** SECTION 5: RAW -> URL decoded -> Spaces Removed -> Lower Cased -> All Whitespace Removed filescans. **

//$zbfiledat=preg_replace('/\s+/','',$zbfiledat); // activate when needed!
//$zbfiledat=preg_replace("/[^\x9\xA\xD\x20-\x7F]/",'',$zbfiledat);  // activate when needed!


 }
reset($_FILES);
$zbfiledat = null;
unset($zbfiledat);
}
// END Filescasn Module

// *Honeypot Trap

if (isset($zbhoneypot)){
if ($zbhoneypot == 1){
$ax += 1;
$whyblockout = $whyblockout . 'Fumble 100. Poor judgement. Your connection landed in a honeypot. You are banned and unable to parry. INSTA-BAN (DOO-FUS-001). '; 
}
}

// *Query Scans

$ax += inmatch($querydec,'*/','RFI attack/SQL injection (QU-001). ');
$ax += inmatch($querydec,'/*','RFI attack/SQL injection (QU-002). ');
$ax += inmatch($query,'%u','Injection (Unicode ASCII escaping) (QU-003). ');
$ax += inmatch($query,'%0','Injection (Unprintable ASCII escaping) (QU-004). ');
$ax += inmatch($query,'%1','Injection (Unprintable ASCII escaping) (QU-005). ');
$ax += inmatch($querydec,'result:+\\','SQLi (QU-006). '); //70c
$ax += rmatch($query,'%3b','RFI attack/SQL injection (QU-007). ');//70c
$ax += inmatch($query,'%250','RFI attack/SQL injection (Unprintable ASCII escaping) (QU-008). ');
$ax += inmatch($query,'%251','RFI attack/SQL injection (Unprintable ASCII escaping (QU-009). ');
$ax += inmatch($query,'%25u','RFI attack/SQL injection (Unicode ASCII escaping (QU-010). ');
if(!(inmatch($requesturi,'/ucp.php?mode=login',''))){
$ax += inmatch($query,'%2525','RFI attack/SQL injection (nested percents, level 1 e.g. %2525) (QU-011). '); //67a extended description
$ax += inmatch($query,'%25252525','RFI attack/SQL injection (nested percents, level 2 e.g. %25252525) (QU-012). '); //67a extended description
}
$ax += inmatch($query,'%2527',"RFI attack/SQL injection (nested percent and ' e.g. %2527) (QU-013). "); //67a extended description
$ax += inmatch($query,"'%20","RFI attack/SQL injection (') (QU-014). "); //70b 71d split/changed
$ax += inmatch($query,"%20'","RFI attack/SQL injection (') (QU-015). "); //70b 71d split/changed
$ax += inmatch($querydecsws,"'='","RFI attack/SQL injection (') (QU-016). "); //70b 71d split/changed
$ax += rmatch($query,'%253b','RFI attack/SQL injection (QU-017). ');//70c
if(!((defined('SMF')) || (lmatch($requesturi,'/admin/action_log.php','')))){$ax += (rmatch($querydec,';','RFI attack/SQL injection (some browser plugins like Linkification for Firefox may cause this) (QU-018). '));} //66f 71c 71 bypasses.
$ax += lmatch($querydec,';','RFI attack/SQL injection (QU-019). ');
$ax += inmatch($querydec,'jos_users','RFI attack/SQL injection (QU-020). ');
$ax += inmatch($query,'++++','SQL overflow attempt (QU-021). '); //66g Mod 71
$ax += inmatch($querydec,'concat_ws','RFI attack/SQL injection (QU-022). ');
$ax += inmatch($querydec,'concat(','RFI attack/SQL injection (QU-023). ');
$ax += (inmatch($querydec,'union','')) && (inmatch($querydec,'select','RFI attack/SQL injection (QU-024). '));
$ax += (inmatch($querydec,'where','')) && (inmatch($querydec,'from','')) && (inmatch($querydec,'select','RFI attack/SQL injection (QU-024.1). ')); //71
$ax += inmatch($querydec,'declare','RFI attack/SQL injection (QU-025). '); 
$ax += inmatch($querydec,'autoloadconfig','general CMS attack (QU-026). ');
$ax += inmatch($querydecsws,'include(','Command injection (QU-027). ');
$ax += inmatch($querydecsws,'include"','Command injection (QU-027.1). '); //72b
$ax += inmatch($querydecsws,"include'",'Command injection (QU-027.2). '); //72b
$ax += inmatch($querydecsws,'include$','Command injection (QU-027.3). '); //74b
$ax += inmatch($querydecsws,'include<','Command injection (QU-027.4). '); //74b
$ax += inmatch($querydecsws,'require(','Command injection (QU-028). '); //64 Oops! forgot this equivalent command till now.
$ax += inmatch($querydecsws,'require"','Command injection (QU-028.1). '); //72b
$ax += inmatch($querydecsws,"require'",'Command injection (QU-028.2). '); //72b
$ax += inmatch($querydecsws,'require$','Command injection (QU-028.3). '); //74b
$ax += inmatch($querydecsws,'require<','Command injection (QU-028.4). '); //74b
$ax += inmatch($querydecsws,'_once(','Command injection (QU-029). '); //67a
$ax += inmatch($querydecsws,"_once'",'Command injection (QU-029.1). '); //72b
$ax += inmatch($querydecsws,'_once"','Command injection (QU-029.2). '); //72b
$ax += inmatch($querydecsws,'_once$','Command injection (QU-029.3). '); //74b
$ax += inmatch($querydecsws,'_once<','Command injection (QU-029.4). '); //74b
$ax += inmatch($querydecsws,'eval(','Command injection (QU-030). '); //67a
$ax += inmatch($querydecsws,'assert(','Command injection (QU-030.1). '); //72b
$ax += inmatch($querydecsws,'code(','Command injection (QU-031). '); //67a
$ax += inmatch($querydecsws,'inflate(','Command injection (QU-032). '); //67a
$ax += inmatch($querydecsws,'thru(','Command injection (QU-033). '); //67c strengthened
$ax += inmatch($querydecsws,'echo(','Command injection (QU-034). '); //67a
$ax += inmatch($querydecsws,'system(','Command injection (QU-035). '); //67a
$ax += inmatch($querydecsws,'exec(','Command injection (QU-036). '); //67a
$ax += inmatch($querydecsws,'unction(','Command injection (QU-037). '); //67a
$ax += inmatch($querydecsws,'nt(','Command injection (QU-038). '); //67a
$ax += inmatch($querydecsws,'ex(','Command injection (QU-039). '); //67a
$ax += inmatch($querydecsws,'eregi(','Command injection (QU-040). '); //67a
$ax += inmatch($querydecsws,'if(','Command injection (QU-041). '); //67a
$ax += inmatch($querydecsws,'exists(','Command injection (QU-042). '); //67a
$ax += inmatch($querydecsws,'while(','Command injection (QU-043). '); //67a
$ax += inmatch($querydecsws,'start(','Command injection (QU-044). '); //67a
$ax += inmatch($querydecsws,'restore(','Command injection (QU-045). '); //67a
$ax += inmatch($querydecsws,'open(','Command injection (QU-046). '); //67a
$ax += inmatch($querydecsws,'contents(','Command injection (QU-047). '); //67a
$ax += inmatch($querydecsws,'escape(','Command injection (QU-048). '); //67a
$ax += inmatch($querydecsws,'write(','Command injection (QU-049). '); //67a
$ax += inmatch($querydecsws,'rot13(','Command injection (QU-050). '); //67c
$ax += inmatch($querydecsws,'plode(','Command injection (QU-051). '); //67c
$ax += inmatch($querydecsws,'ashes(','Command injection (QU-052). '); //67c
$ax += inmatch($querydecsws,'place(','Command injection (QU-053). '); //67c
$ax += inmatch($querydecsws,'puts(','Command injection (QU-055). '); //67c
$ax += inmatch($querydecsws,'read(','Command injection (QU-056). '); //67c
$ax += inmatch($querydecsws,'file(','Command injection (QU-057). '); //67c
$ax += inmatch($querydecsws,'able(','Command injection (QU-058). '); //67c
$ax += inmatch($querydecsws,'getc(','Command injection (QU-058). '); //67c
$ax += inmatch($querydecsws,'getcsv(','Command injection (QU-059). '); //67c
$ax += inmatch($querydecsws,'gets(','Command injection (QU-060). '); //67c
$ax += inmatch($querydecsws,'getss(','Command injection (QU-061). '); //67c
$ax += inmatch($querydecsws,'asc(','Command injection (QU-062). '); //70c
$ax += inmatch($querydecsws,'chr(','Command injection (QU-063). '); //70c
$ax += inmatch($querydecsws,'len(','Command injection (QU-064). '); //70c
$ax += inmatch($querydecsws,'length(','Command injection (QU-065). '); //70c
$ax += inmatch($querydec,'()','Command injection (QU-066). '); //70c Modified 73d
$ax += inmatch($querydecsws,"('')",'Command injection (QU-067). '); //70c
$ax += inmatch($querydecsws,'("")','Command injection (QU-068). '); //70c
$ax += inmatch($querydec,'$_get','General CMS/RFI attack (QU-069). ');
$ax += inmatch($querydecsws,'request[','General CMS/RFI attack (QU-070). '); //66j strengthened to remove whitespaces.
$ax += inmatch($querydec,'[itemid]','General CMS/RFI attack (QU-071). ');
$ax += inmatch($querydec,'[file]','General CMS attack (QU-072). ');
$ax += inmatch($querydec,'[r]','General CMS attack (QU-073). ');
$ax += inmatch($querydec,'[l]','General CMS attack (QU-074). ');
$ax += inmatch($querydec,'[w]','General CMS attack (QU-075). ');
$ax += inmatch($querydec,'[a]','General CMS attack (QU-076). ');
$ax += inmatch($querydec,'[src','General CMS attack (QU-077). ');
$ax += inmatch($querydec,'[localserverfile','General CMS attack (QU-078). ');
$ax += inmatch($querydec,'[classes','General CMS attack (QU-079). ');
$ax += inmatch($querydec,'[pth','General CMS attack (QU-080). ');
$ax += inmatch($querydec,'[lastrss_ap_enabled','General CMS attack (QU-081). ');
$ax += inmatch($querydec,'[loadfile','RFI attack/General CMS attack (QU-082). ');
$ax += inmatch($querydec,'[0,','General CMS attack (QU-083). ');
$ax += inmatch($querydec,'->','General CMS attack (QU-084). ');
$ax += inmatch($querydec,'page=-','general CMS attack (QU-085). ');
$ax += inmatch($querydec,'pagina=-','general CMS attack (QU-086). ');
$ax += inmatch($querydec,'onmousedown=','e107 CMS attack (QU-087). ');
$ax += rmatch($query,'%00','Null truncation attempt (QU-088). ');
$ax += rmatch($query,'%000','Null truncation attempt (QU-089). ');
$ax += rmatch($query,'%0000','Null truncation attempt (QU-090). ');
$ax += inmatch($querydecsws,'8585072011','QUERY CRASH ATTEMPT. Please do not use death number in URL (QU-091). '); //69c
$ax += inmatch($querydecsws,'amp;amp;amp;','Ampersand nesting obfuscation attempt MK3. INSTA-BAN (QU-092). '); //71e
$ax += inmatch($query,'amp%3bamp%3b','Ampersand nesting obfuscation attempt MK4. INSTA-BAN (QU-093). '); //71e
$ax += inmatch($querydecsws,'.php/login.php','login hack attempt (QU-094). '); //70a Modified 71
$ax += inmatch($querydec,'jot_users','RFI attack/SQL injection (QU-095). '); //70d
$ax += minmatch($query,'%27',2,'RFI attack/SQL injection probe (QU-096). '); //70e
$ax += minmatch($query,'%22',2,'RFI attack/SQL injection probe (QU-097). '); //70e
$ax += inmatch($query,'%61%6e%64','RFI attack/SQL injection probe (QU-098). '); //70e
$ax += inmatch($query,'%41%4e%44','RFI attack/SQL injection probe (QU-099). '); //70e
$ax += inmatch($querydec,'javascript:','Javascript hack (QU-102). '); //71a
$ax += inmatch($querydec,';javascript','Javascript hack (QU-103). '); //71a
if (!((inmatch($querydec,"&hilit=","")) || (inmatch($querydec,"&keyword=","")) || (lmatch($querydec,"keyword=","")) || (lmatch($querydec,"keywords=","")))){$ax += (rmatch($query,"+","Please remove space from end of URL (QU-207). "));} //71g //mod 71h 73a 74a
$ax += inmatch($querydec,'custompluginfile[]=','Prevalent hack to an unknown script (QU-239). '); //71h

if ($querydec != '?'){
  $ax += (rmatch($query,'?','Question mark at end of query. ')); //modified 71g
  if ($querydec == 'mode=login&redirect=./index.php?'){$ax -= 1;}
}

if ((inmatch($query,'%2525',''))&&(lmatch($querydec,'mode=login&redirect=./ucp.php?',''))){$ax -= 1;}
//if ((inmatch($query,'%25252525',''))&&(lmatch($querydec,'mode=login&redirect=./ucp.php?',''))){$ax -= 1;}

$ax += inmatch($query,'??','Badly formed query, must not have 2 question marks in a row (QU-104). ');
$ax += inmatch($querydec,'???','Badly formed query, must not have 3 question marks in a row even with escaping (QU-105). ');
$ax += inmatch($querydec,'(username','(username in query (QU-106). ');
$ax += inmatch($querydec,'password)','password) in query (QU-106). ');
if (!($zbwhitelisted)){$ax += inmatch($querydec,'http:','RFI (http) (QU-107). ');} //mod 73f
$ax += inmatch($querydec,'1http:','RFI (http) (QU-108). ');
if (!($zbwhitelisted)){$ax += inmatch($querydec,'https:','RFI (https) (QU-109). ');} //mod 73f
$ax += inmatch($querydec,'ftp:','RFI (ftp) (QU-110). ');
$ax += inmatch($querydec,'ftps:','RFI (ftps) (QU-111). ');
$ax += inmatch($querydec,'gopher:','RFI (gopher) (QU-112). ');
$ax += inmatch($querydec,'mms:','RFI (mms) (QU-113). ');
$ax += inmatch($querydec,'rtsp:','RFI (rtsp) (QU-114). ');
$ax += inmatch($querydec,'rtp:','RFI (rtp) (QU-115). ');
$ax += inmatch($querydec,'udp:','RFI (udp) (QU-116). ');
$ax += inmatch($querydec,'telnet:','RFI (telnet) (QU-117). ');
$ax += inmatch($querydec,'path]','Path hack (QU-118). ');
$ax += inmatch($querydec,'root]','Root hack (QU-119). ');
$ax += inmatch($querydecsws,'<script','http javascript (wedge end/script start) injection (QU-120). '); //71c strengthened
$ax += inmatch($querydecsws,'/script>','http javascript (wedge start/script end) injection (QU-121). '); //71c strengthened
$ax += inmatch($querydecsws,'<pre','preformated (wedge start) (QU-122). '); //71c 
$ax += inmatch($querydecsws,'/pre>','preformated (wedge end) (QU-123). '); //71c 
$ax += inmatch($querydecsws,'<body','Attempting to cause a new body to start (QU-124). '); //71c strengthened
$ax += inmatch($querydecsws,'<? ','Php Script Execution Attempt (QU-125). '); //71a changed 71c strengthened
$ax += inmatch($querydecsws,'<?php','Php Script Execution Attempt (QU-126). '); //71a split 71c strengthened
$ax += inmatch($querydec,'echo "','Execution Attempt (QU-127). '); //63a
$ax += inmatch($querydec,'=|','Execution Attempt (QU-129). '); //63a
$ax += inmatch($querydec,';|','Execution Attempt (QU-130). '); //63a
$ax += inmatch($querydec,'";','Execution Attempt (QU-131). '); //63a
$ax += inmatch($querydec,'|include','RFI Attempt (QU-132). '); //63a
$ax += inmatch($querydec,'|require','RFI Attempt (QU-133). '); //63a
$ax += inmatch($querydec,'php://','Global stream hack (QU-134). ');
$ax += inmatch($querydec,'_server[','Globvar hack (QU-135). ');
$ax += inmatch($querydec,'_get[','Globvar hack (QU-136). ');
$ax += inmatch($querydec,'_post[','Globvar hack (QU-137). ');
$ax += inmatch($querydec,'_files[','Globvar hack (QU-138). ');
$ax += inmatch($querydec,'_request[','Globvar hack (QU-139). ');
$ax += inmatch($querydec,'_env[','Globvar hack (QU-140). ');
$ax += inmatch($querydec,'_cookie[','Globvar hack (QU-141). ');
$ax += inmatch($querydec,'_session[','Globvar hack (QU-142). ');
$ax += inmatch($querydec,'argc','Globvar hack (QU-143). ');
$ax += inmatch($querydec,'argv','Globvar hack (QU-144). ');
$ax += inmatch($querydec,'globals[','Globvar hack (QU-145). ');
$ax += inmatch($querydec,'alert(','XSS attack obfuscation (QU-146). ');
if(lmatch($querydec,'+','')){$ax += rmatch($querydec,'+','XSS attack pre &postamble (QU-147). ');} //65c 
$ax += inmatch($querydec,'"sysadmin"','SQL injection SQL-01 (QU-148). ');
$ax += inmatch($querydec,"'sysadmin'",'SQL injection SQL-02 (QU-149). ');
$ax += inmatch($querydec,'@oler','SQL injection SQL-03 (QU-150). ');
$ax += inmatch($querydecsws,'(select','SQL injection SQL-04 Mk2 (QU-151). '); //69b modification
$ax += inmatch($querydec,'_priv','SQL injection SQL-05 (QU-152). ');
$ax += inmatch($querydec,'_schema','SQL injection SQL-06 (QU-153). '); //Pending removal 71b
$ax += inmatch($querydec,'_table','SQL injection SQL-07 (QU-154). ');
$ax += inmatch($querydec,'(select','SQL injection SQL-08 (QU-155). ');
$ax += inmatch($querydec,'(version','SQL injection SQL-09 (QU-156). ');
$ax += inmatch($querydec,'version)','SQL injection SQL-10 (QU-157). ');
//$ax += inmatch($querydec,'user)','SQL injection SQL-11 (QU-158). '); //removed 73b, too common.
//$ax += inmatch($querydec,'name)','SQL injection SQL-12 (QU-159). '); //removed 73b, too common.
$ax += inmatch($querydec,'(sql','SQL injection SQL-13 (QU-160). ');
$ax += inmatch($querydec,'@datadir','SQL injection SQL-14 (QU-161). ');
$ax += inmatch($querydec,'error(','SQL injection SQL-15 (QU-162). ');
$ax += inmatch($querydec,'member(','SQL injection SQL-16 (QU-163). ');
$ax += inmatch($querydec,'convert(','SQL injection SQL-17 (QU-164). ');
$ax += inmatch($querydec,'set(','SQL injection SQL-18 (QU-165). ');
$ax += inmatch($querydec,'sleep(','SQL injection SQL-19 (QU-166). ');
$ax += inmatch($querydec,'benchmark(','SQL injection SQL-20 (QU-167). ');
$ax += inmatch($querydecsws,'database(','SQL injection SQL-23 (QU-169). ');
$ax += inmatch($querydecsws,'system(','SQL injection SQL-24 (QU-170). ');
$ax += inmatch($querydecsws,'setting(','SQL injection SQL-25 (QU-171). ');
$ax += inmatch($querydecsws,'substr(','SQL injection SQL-26 (QU-172). ');
$ax += inmatch($querydec,'privilege_type','SQL injection SQL-27 (QU-173). ');
$ax += inmatch($querydec,'create user','SQL injection SQL-28 (QU-174). ');
$ax += inmatch($querydec,'drop user','SQL injection SQL-29 (QU-175). ');
$ax += inmatch($querydec,'grant all privileges on','SQL injection SQL-30 (QU-176). ');
$ax += inmatch($querydec,'sys.user','SQL injection SQL-31 (QU-177). ');
$ax += inmatch($querydec,'extproc','SQL injection SQL-32 (QU-178). ');
$ax += inmatch($querydec,'dbmsinfo','SQL injection SQL-33 (QU-179). ');
$ax += inmatch($querydec,'syscat','SQL injection SQL-34 (QU-180). ');
$ax += inmatch($querydec,'sysibm','SQL injection SQL-35 (QU-181). ');
$ax += inmatch($querydec,'dbinfo','SQL injection SQL-36 (QU-182). ');
$ax += inmatch($querydec,'systab','SQL injection SQL-37 (QU-183). ');
$ax += inmatch($querydec,'waitfor','SQL injection SQL-38 (QU-184). ');
$ax += inmatch($querydec,'bulk insert','SQL injection SQL-39 (QU-185). ');
$ax += inmatch($querydec,'drop table','SQL injection SQL-40 (QU-186). ');
$ax += inmatch($querydec,'create table','SQL injection SQL-41 (QU-187). ');
$ax += inmatch($querydec,'addlogin','SQL injection SQL-42 (QU-188). ');
$ax += inmatch($querydec,'droplogin','SQL injection SQL-43 (QU-189). ');
$ax += inmatch($querydec,'password_hash','SQL injection SQL-44 (QU-190). ');
$ax += inmatch($querydec,'mysql.user','SQL injection SQL-45 (QU-191). ');
$ax += inmatch($querydec,'show advanced options','SQL injection SQL-46 (QU-192). ');
$ax += inmatch($querydec,'xp_cmdshell','SQL injection SQL-47 (QU-193). ');
$ax += inmatch($querydec,'type_name','SQL injection SQL-48 (QU-194). ');
$ax += inmatch($requesturi,'.../','Directory traversal attack (QU-195). '); //63b mod 74a
$ax += inmatch($requesturi,'...%5C','Directory traversal attack (QU-196). '); //63b mod 74a
$ax += inmatch($querydec,'num_replies=77777','overflow hack (QU-197). '); //66m
$ax += inmatch($requesturi,'././','Directory traversal attack (QU-198). '); //69b
$ax += inmatch($requesturi,'.//.//','Directory traversal attack (QU-199). '); //69b
$ax += inmatch($requesturi,'..//..//','Directory traversal attack (QU-200). '); //69b
$ax += inmatch($querydec,'e107_user','SQL injection SQL-49 (QU-201). '); //69c
$ax += inmatch($querydec,'user_login','SQL injection SQL-50 (QU-202). '); //69c mod 70d
$ax += inmatch($querydec,'user_password','SQL injection SQL-51 (QU-203). '); //69c
$ax += inmatch($querydec,'user_hash','SQL injection SQL-52 (QU-204). '); //70d
$ax += inmatch($querydecsws,'path]=','Path hack (QU-205). '); //71e
$ax += inmatch($querydecsws,'src=http:','RFI (http) (QU-237). '); //71g
$ax += inmatch($querydec,'yeswecan','Oh noyoudont. (QU-238). '); //71g
$ax += inmatch($query,'+result:','SQL injection. SQL-53 (QU-240). '); //71 fixed 74c
$ax += regexmatch($querydec,'user_login,\w{4},user_(?:pass|email|activation_key)','WP injection hack (QU-241). '); //71
$ax += inmatch($query,',0x','SQL injection (QU-242). '); //71
$ax += minmatch($querydec,'`',1,'Backtick execution attempt detected (QU-243). '); //72b
$ax += inmatch($querydecsws,'function(','Command injection (QU-244). '); //72b
$ax += inmatch($querydecsws,'unserialize(','Command injection (QU-245). '); //72b
$ax += inmatch($querydecsws,'dotnet_load(','Command injection (QU-246). '); //72b
$ax += inmatch($querydecsws,'$_GET[','Command injection (QU-247). '); //72b
$ax += inmatch($querydecsws,'foreach(','Command injection (QU-248). '); //73a
$ax += inmatch($querydecsws,'array(','Command injection (QU-249). '); //73a
$ax += inmatch($querydecsws,'printf(','Command injection (QU-250). '); //73a
$ax += inmatch($querydecsws,'urlencode(','Command injection (QU-251). '); //73a
$ax += inmatch($querydecsws,'print_r(','Command injection (QU-252). '); //73a
$ax += lmatch($querydec,'-','PHP hack probing attempt. (QU-253). '); //73b
$ax += regexmatch($requesturi,'\?author=\d+','Phishing for a WordPress real username is NOT allowed (QU-254). '); //73d
//$ax += inmatch($query2,'//','Traversal Attack (QU-255). '); //73d Removed 73e
$ax += inmatch($lcrequesturi,'.htpa','No .ht file manipulation allowed. Use FTP (QU-256). '); //74a
$ax += inmatch($lcrequesturi,'.htac','No .ht file manipulation allowed. Use FTP (QU-257). '); //74a
$ax += inmatch($querydecsws,';drop','SQL vector XSS attack (QU-258). '); //74a
$ax += inmatch($querydecsws,';select','SQL vector XSS attack (QU-259). '); //74a
$ax += inmatch($querydecsws,';delete','SQL vector XSS attack (QU-260). '); //74a
$ax += inmatch($lcrequesturi,'setup.php','Generic CMS hijack/exploit (QU-261). '); //74a
if ((!($zbwhitelisted) && !(regexmatch($requesturi,"/wp-admin/(?:network/)?(?:plugin|theme)-install\.php",'')) && !(minmatch($requesturi,'install.php',1,'')))){$ax += inmatch($lcrequesturi,'install.php','Generic CMS hijack/exploit (QU-262). ');} //74b additional bypass and whitelisting added 75a. Added WordPress MU/MS 75b.
$ax += inmatch($query,"'+'",'SQL vector XSS attack (QU-263). '); //74a
$ax += inmatch($query,"`+`",'SQL vector XSS attack (QU-264). '); //74a
if ((lmatch($query,"'",'')) && (rmatch($query,"'",''))){$ax += 1; $whyblockout = $whyblockout . 'SQL injection (QU-265). ';} //74b
if ((lmatch($query,'"','')) && (rmatch($query,'"',''))){$ax += 1; $whyblockout = $whyblockout . 'SQL injection (QU-266). ';} //74b
$ax += inmatch($query,'settings.','SQL injection (QU-267). '); //74b
$ax += inmatch($querydecsws,'5889d40edd5da7597dfc6d1357d98696','Query error (QU-268.0). '); //74d
$ax += inmatch($querydecsws,'e9xmkgg5h6','Query error (QU-268.1). '); //74d
$ax += lmatch($querydecsws,'http','RFI attempt (QU-269.0). '); //74d
$ax += lmatch($querydecsws,'ftp','RFI attempt (QU-269.1). '); //74d
$ax += inmatch($querydecsws,'=data:,','Injection vector detected (QU-270). '); //74d
$ax += inmatch($query,';&','Injection vector detected (QU-271). '); //74d
$ax += inmatch($querydecsws,'=print-','Injection vector detected (QU-272). '); //74d
$ax += inmatch($querydecsws,'rwt(','Injection vector detected (QU-273). '); //74d
$ax += inmatch($querydecsws,'(this,','Injection vector detected (QU-274). '); //74d
$ax += inmatch($querydecsws,',"",','Injection vector detected (QU-275). '); //74d
$ax += inmatch($querydecsws,",'',",'Injection vector detected (QU-276). '); //74d
$ax += regexmatch($querydecsws,"(?:&\S=\S+){10,}",'Injection vector detected. INSTA-BAN (QU-277). '); //74d mod 75d
$ax += rmatch($dblrequesturidec,'==','Boolean in Query, hacking attempt (QU-278.0). '); //74d downgrade from insta-ban 75d
$ax += rmatch($dblrequesturidec,'!=','Boolean in Query, hacking attempt (QU-278.2). '); //74d downgrade from insta-ban 75d
$ax += rmatch($dblrequesturidec,'<','Boolean in Query, hacking attempt (QU-278.4). '); //74d downgrade from insta-ban 75d
$ax += rmatch($dblrequesturidec,'>','Boolean in Query, hacking attempt (QU-278.5). '); //74d downgrade from insta-ban 75d
$ax += rmatch($dblrequesturidec,'>=','Boolean in Query, hacking attempt (QU-278.6). '); //74d downgrade from insta-ban 75d
$ax += rmatch($dblrequesturidec,'<=','Boolean in Query, hacking attempt (QU-278.7). '); //74d downgrade from insta-ban 75d


// Some functions may interfere with admining We've placed them inside this IF. //62

if ($zbwhitelisted != 1){

  // May interfere with a special case on OS Commerce CMS, and styles installation
  // phpbb //66L fixed & 72b annotated.

  if (!((substr_count($querydec,'cpath=') == 1) && (substr_count($querydec,'path=') == 1))){
    $ax += inmatch($querydec,'path=','Path hack (QU-206). ');  
  }

  // *Nesting Attacks

  $ax += inmatch($querydec,'.jpg?','Nesting attack (QUN-001). ');
  $ax += inmatch($querydec,'.gif?','Nesting attack (QUN-002). ');
  $ax += inmatch($querydec,'.png?','Nesting attack (QUN-003). ');
  $ax += inmatch($querydec,'.css?','Nesting attack (QUN-004). ');
  $ax += inmatch($querydec,'.cfg?','Nesting attack (QUN-005). ');
  $ax += inmatch($querydec,'.js?','Nesting attack (QUN-006). ');
  $ax += inmatch($querydec,'.ico?','Nesting attack (QUN-007). ');
  $ax += inmatch($querydec,'.xsl?','Nesting attack (QUN-008). ');
  $ax += inmatch($querydec,'.xml?','Nesting attack (QUN-009). ');
  $ax += inmatch($querydec,'.gz?','Nesting attack (QUN-010). ');
  $ax += inmatch($querydec,'.tar?','Nesting attack (QUN-011). ');
  $ax += inmatch($querydec,'.zip?','Nesting attack (QUN-012). ');
  $ax += inmatch($querydec,'.txt?','Nesting attack (QUN-013). ');
  $ax += minmatch($querydec,'.php?',1,'Nesting attack (QUN-014). ');
  $ax += minmatch($querydec,'.php3?',1,'Nesting attack (QUN-015). ');
  $ax += minmatch($querydec,'.php4?',1,'Nesting attack (QUN-016). ');
  $ax += minmatch($querydec,'.php5?',1,'Nesting attack (QUN-017). ');
  $ax += minmatch($querydec,'.htm?',1,'Nesting attack (QUN-018). ');
  $ax += minmatch($querydec,'.html?',1,'Nesting attack (QUN-019). ');
  $ax += minmatch($querydec,'.asp?',1,'Nesting attack (QUN-020). ');
  $ax += minmatch($querydec,'file=',1,'Nesting attack (QUN-021). ');
  $ax += minmatch($querydec,'name=',2,'Nesting attack (QUN-022). ');
  $ax += minmatch($querydec,'page=',2,'Nesting attack (QUN-023). ');
  $ax += minmatch($querydec,'pagina=',1,'Nesting attack (QUN-024). ');
  $ax += minmatch($querydec,'mode=',2,'Nesting attack (QUN-025). ');
  $ax += minmatch($querydec,'highlight=',1,'Nesting attack (QUN-026). ');
  $ax += minmatch($querydec,'=PNphpBB2',1,'Nesting attack (QUN-027). ');

  $ax += inmatch($querydecsws,'/include/','Function directory access violation (QU-234). '); //71d
  $ax += inmatch($querydecsws,'/includes/','Function directory access violation (QU-235). '); //71d
  $ax += inmatch($querydecsws,'/inc/','Function directory access violation (QU-236). '); //71d
  $ax += inmatch($querydecsws,'/vault/','Function directory access violation (QU-237). '); //74b
  $ax += inmatch($querydecsws,'/install/','Function directory access violation (QU-238). '); //74b

}

//Search for a URL bypass. 

if (substr_count($querydec,'http:') == 1){
  if (substr_count(htmlspecialchars($requesturi),'/search.php?keywords=http%3A%2F%2F') == 1){
    if (substr_count($whyblockout,'RFI (http)') == 1){
      if (lmatch($querydec,'keywords=http://','URL search bypass. ')){
        $ax -= 1;
      }
    }
  }
}

// *User Agents

// bombs

$ax += inmatch($lcuseragentsws,'<? ','Php Script Execution Attempt (UAB-001). '); //71a split
$ax += inmatch($lcuseragentsws,'<?php','Php Script Break Attempt (UAB-002). '); //71a changed
$ax += inmatch($lcuseragentsws,'<pre ','Preformatted Execution Attempt (wedge start) (UAB-003). '); //71a split
$ax += inmatch($lcuseragentsws,'/pre>','Preformated Execution Attempt (wedge end) (UAB-004). '); //71a changed
$ax += inmatch($lcuseragentsws,'droptable','UASQLi 01 (UAB-005). '); //warning dangerous to modify caused accidental catch in previous version
$ax += inmatch($lcuseragent,' href','http url injection (UAB-006). ');
$ax += inmatch($lcuseragent,'iframe','iframe injection (UAB-007). ');
$ax += inmatch($lcuseragentsws,'%0','Unprintable Ascii User-Agent Hack, try a different browser (UAB-008). ');
$ax += inmatch($lcuseragentsws,'%1','Unprintable Ascii User-Agent Hack, try a different browser (UAB-009). ');
$ax += inmatch($lcuseragentsws,'%8','Extended Ascii Not Allowed in User-Agent Hack (UAB-010). ');
$ax += inmatch($lcuseragentsws,'%9','Extended Ascii Not Allowed in User-Agent Hack (UAB-011). ');
$ax += inmatch($lcuseragentsws,'%a','Extended Ascii Not Allowed in User-Agent Hack (UAB-012). ');
$ax += inmatch($lcuseragentsws,'%b','Extended Ascii Not Allowed in User-Agent Hack (UAB-013). ');
$ax += inmatch($lcuseragentsws,'%c','Extended Ascii Not Allowed in User-Agent Hack (UAB-014). ');
$ax += inmatch($lcuseragentsws,'%d','Extended Ascii Not Allowed in User-Agent Hack (UAB-015). ');
$ax += inmatch($lcuseragentsws,'%e','Extended Ascii Not Allowed in User-Agent Hack (UAB-016). ');
$ax += inmatch($lcuseragentsws,'%f','Extended Ascii Not Allowed in User-Agent Hack (UAB-017). ');
//$ax += inmatch($lcuseragentsws,'%A','Extended Ascii Not Allowed in User-Agent Hack (UAB-018). '); //Removed 73d, Redundant and errant.
//$ax += inmatch($lcuseragentsws,'%B','Extended Ascii Not Allowed in User-Agent Hack (UAB-019). '); //Removed 73d, Redundant and errant.
//$ax += inmatch($lcuseragentsws,'%C','Extended Ascii Not Allowed in User-Agent Hack (UAB-020). '); //Removed 73d, Redundant and errant.
//$ax += inmatch($lcuseragentsws,'%D','Extended Ascii Not Allowed in User-Agent Hack (UAB-021). '); //Removed 73d, Redundant and errant.
//$ax += inmatch($lcuseragentsws,'%E','Extended Ascii Not Allowed in User-Agent Hack (UAB-022). '); //Removed 73d, Redundant and errant.
//$ax += inmatch($lcuseragentsws,'%F','Extended Ascii Not Allowed in User-Agent Hack (UAB-023). '); //Removed 73d, Redundant and errant.
$ax += inmatch($lcuseragentsws,'<script','http javascript (wedge end/script start) injection (UAB-024). ');
$ax += inmatch($lcuseragentsws,'/script>','http javascript (wedge start/script end) injection (UAB-025). ');
$ax += inmatch($lcuseragentsws,'<a','Anchor hack INSTA-BAN (UAB-026). '); //74b mod to insta-ban
$ax += inmatch($lcuseragentsws,'/a>','Anchor hack INSTA-BAN (UAB-027). '); //74b mod to insta-ban
$ax += inmatch($lcuseragent,'[url=','Anchor hack (UAB-028). ');
$ax += inmatch($lcuseragentsws,'code(','UAEX 01 (UAB-029). '); //70a
$ax += inmatch($lcuseragentsws,'unction(','UAEX 02 (UAB-030). '); //70a
$ax += inmatch($lcuseragentsws,'nt(','UAEX 03 (UAB-031). '); //70a
$ax += inmatch($lcuseragentsws,'ex(','UAEX 04 (UAB-032). '); //70a
$ax += inmatch($lcuseragentsws,'eregi(','UAEX 05 (UAB-033). '); //70a
$ax += inmatch($lcuseragentsws,'if(','UAEX 06 (UAB-034). '); //70a
$ax += inmatch($lcuseragentsws,'exists(','UAEX 07 (UAB-035). '); //70a
$ax += inmatch($lcuseragentsws,'drop table','UAEX 08 (UAB-036). '); //70a
$ax += inmatch($lcuseragentsws,'while(','UAEX 09 (UAB-037). '); //70a
$ax += inmatch($lcuseragentsws,'start(','UAEX 10 (UAB-038). '); //70a
$ax += inmatch($lcuseragentsws,'restore(','UAEX 11 (UAB-039). '); //70a
$ax += inmatch($lcuseragentsws,'open(','UAEX 12 (UAB-040). '); //70a
$ax += inmatch($lcuseragentsws,'contents(','UAEX 13 (UAB-041). '); //70a
$ax += inmatch($lcuseragentsws,'escape(','UAEX 14 (UAB-042). '); //70a
$ax += inmatch($lcuseragentsws,'write(','UAEX 15 (UAB-043). '); //70a
$ax += inmatch($lcuseragentsws,'_once(','UAEX 16 (UAB-044). '); //70a
$ax += inmatch($lcuseragentsws,"_once'",'UAEX 16 (UAB-044.1). '); //72b
$ax += inmatch($lcuseragentsws,'_once"','UAEX 16 (UAB-044.2). '); //72b
$ax += inmatch($lcuseragentsws,'_once$','UAEX 16 (UAB-044.3). '); //74b
$ax += inmatch($lcuseragentsws,'_once<','UAEX 16 (UAB-044.4). '); //74b
$ax += inmatch($lcuseragentsws,'ereg(','UAEX 17 (UAB-045). '); //70a
$ax += inmatch($lcuseragentsws,'rot13(','UAEX 18 (UAB-046). '); //70a
$ax += inmatch($lcuseragentsws,'plode(','UAEX 19 (UAB-047). '); //70a
$ax += inmatch($lcuseragentsws,'ashes(','UAEX 20 (UAB-048). '); //70a
$ax += inmatch($lcuseragentsws,'place(','UAEX 21 (UAB-049). '); //70a
$ax += inmatch($lcuseragentsws,'puts(','UAEX 23 (UAB-050). '); //70a
$ax += inmatch($lcuseragentsws,'read(','UAEX 24 (UAB-051). '); //70a
$ax += inmatch($lcuseragentsws,'file(','UAEX 25 (UAB-052). '); //70a
$ax += inmatch($lcuseragentsws,'_table(','UAEX (UAB-053.0). '); //70a modified 72
$ax += inmatch($lcuseragentsws,'executable(','UAEX (UAB-053.1). '); //70a modified 72
$ax += inmatch($lcuseragentsws,'nable(','UAEX (UAB-053.2). '); //70a modified 72
$ax += inmatch($lcuseragentsws,'iable(','UAEX (UAB-053.3). '); //70a modified 72
$ax += inmatch($lcuseragentsws,'sable(','UAEX (UAB-053.4). '); //70a modified 72
$ax += inmatch($lcuseragentsws,'getc(','UAEX 27 (UAB-054). '); //70a
$ax += inmatch($lcuseragentsws,'getcsv(','UAEX 28 (UAB-055). '); //70a
$ax += inmatch($lcuseragentsws,'gets(','UAEX 29 (UAB-056). '); //70a
$ax += inmatch($lcuseragentsws,'getss(','UAEX 30 (UAB-057). '); //70a
$ax += inmatch($lcuseragentsws,'exec(','UAEX 31 (UAB-058). '); //70a
$ax += inmatch($lcuseragentsws,'gzinflate(','UAEX 32 (UAB-059). '); //70a
$ax += inmatch($lcuseragentsws,'thru(','UAEX 33 (UAB-060). '); //70a
$ax += inmatch($lcuseragentsws,'echo(','UAEX 34 (UAB-061). '); //70a
$ax += inmatch($lcuseragentsws,'system(','UAEX 35 (UAB-062). '); //70a
$ax += inmatch($lcuseragentsws,'include(','UAEX 36 (UAB-063). '); //70a
$ax += inmatch($lcuseragentsws,'include"','UAEX 36 (UAB-063.1). '); //72b
$ax += inmatch($lcuseragentsws,"include'",'UAEX 36 (UAB-063.2). '); //72b
$ax += inmatch($lcuseragentsws,'include$','UAEX 36 (UAB-063.3). '); //74b
$ax += inmatch($lcuseragentsws,'include<','UAEX 36 (UAB-063.4). '); //74b
$ax += inmatch($lcuseragentsws,'require(','UAEX 37 (UAB-064). '); //70a
$ax += inmatch($lcuseragentsws,'require"','UAEX 37 (UAB-064.1). '); //72b
$ax += inmatch($lcuseragentsws,"require'",'UAEX 37 (UAB-064.2). '); //72b
$ax += inmatch($lcuseragentsws,'require$','UAEX 37 (UAB-064.3). '); //74b
$ax += inmatch($lcuseragentsws,'require<','UAEX 37 (UAB-064.4). '); //74b
$ax += inmatch($lcuseragentsws,'asc(','UAEX 38 (UAB-065). '); //70c
$ax += inmatch($lcuseragentsws,'chr(','UAEX 39 (UAB-066). '); //70c
$ax += inmatch($lcuseragentsws,'len(','UAEX 40 (UAB-067). '); //70c
$ax += inmatch($lcuseragentsws,'length(','UAEX 41 (UAB-068). '); //70c
$ax += inmatch($lcuseragent,'()','UAEX 42 (UAB-069). '); //70d
$ax += inmatch($lcuseragent,"('')",'UAEX 43 (UAB-070). '); //70d
$ax += inmatch($lcuseragent,'("")','UAEX 44 (UAB-071). '); //70d
$ax += inmatch($lcuseragentsws,'database()','UASQLi 02 (UAB-072). '); //70d
$ax += inmatch($lcuseragentsws,'schema','UASQLi 03 (UAB-073). '); //70d
$ax += inmatch($lcuseragent,'select ','UASQLi 04 (UAB-074). '); //70d
$ax += minmatch($lcuseragent,'`',1,'Backtick execution attempt detected (UAB-075). '); //72b
$ax += inmatch($lcuseragentsws,'eval(','UAEX 34 (UAB-076). '); //72b
$ax += inmatch($lcuseragentsws,'assert(','UAEX 34 (UAB-077). '); //72b
$ax += inmatch($lcuseragentsws,'function(','UAEX 34 (UAB-078). '); //72b
$ax += inmatch($lcuseragentsws,'unserialize(','UAEX 45 (UAB-078). '); //72b
$ax += inmatch($lcuseragentsws,'dotnet_load(','UAEX 46 (UAB-079). '); //72b
$ax += inmatch($lcuseragentsws,'$_get[','Global detected (UAB-080). '); //72b fix 74d
$ax += inmatch($lcuseragentsws,'$_post[','Global detected (UAB-081). '); //74d
$ax += inmatch($lcuseragentsws,'$_server[','Global detected (UAB-082). '); //74d
$ax += inmatch($lcuseragentsws,'$_files[','Global detected (UAB-083). '); //74d
$ax += inmatch($lcuseragentsws,'$_request[','Global detected (UAB-084). '); //74d
$ax += inmatch($lcuseragentsws,'$_session[','Global detected (UAB-085). '); //74d
$ax += inmatch($lcuseragentsws,'$_env[','Global detected (UAB-086). '); //74d
$ax += inmatch($lcuseragentsws,'$_cookie[','Global detected (UAB-087). '); //74d
$ax += inmatch($lcuseragentsws,'xmlset_roodkcableoj28840ybtide','Hacking attempt INSTA-BAN (UAB-088). '); //75a


// other agents

$ax += regexmatch($useragent,"(?:[^a-z]|^)perl(?:[^a-z]|$)",'No known valid perl clients or spiders. Infected machine (UA-0001). '); //73b
$ax += regexmatch($useragent,"(?:[^a-z]|^)curl(?:[^a-z]|$)",'No known valid curl clients or spiders. Infected machine (UA-0002). '); //73b
$ax += lmatch($lcuseragent,'java','No known valid Java clients or spiders. Infected machine (UA-0003). '); //modified 71f and 72
$ax += inmatch($lcuseragent,'(java','No known valid Java clients or spiders. Infected machine (UA-0003.1). '); //74a
$ax += inmatch($lcuseragent,'tencenttraveler','Your computer is infected with Trojan Downloader tencenttraveler . Go to http://www.safer-networking.org and get Spybot Search & Destroy, clean your machine, then come back (UA-0005.0). ');
$ax += inmatch($lcuseragent,'qqdownload','Your computer is infected with Trojan Downloader QQDownload . Go to http://www.safer-networking.org and get Spybot Search & Destroy, clean your machine, then come back (UA-0005.1). ');
$ax += inmatch($lcuseragent,'ds_juicyaccess','Your computer is infected with Trojan Downloader ds_juicyaccess . Go to http://www.safer-networking.org and get Spybot Search & Destroy, clean your machine, then come back (UA-0006). ');
$ax += inmatch($lcuseragent,'qqpinyinsetup','Your computer is infected with Trojan Keylogger QQPinyinSetup . Go to http://www.safer-networking.org and get Spybot Search & Destroy, clean your machine, then come back (UA-0007). ');
$ax += inmatch($lcuseragent,'cncdialer','Your computer is infected with Trojan Dialer CNCDialer . Go to http://www.safer-networking.org and get Spybot Search & Destroy, clean your machine, then come back (UA-0008). ');
$ax += inmatch($lcuseragent,'foxy/1','Your computer is infected with Trojan Cloaker Foxy . Go to http://www.safer-networking.org and get Spybot Search & Destroy, clean your machine, then come back (UA-0009). ');
$ax += inmatch($lcuseragent,'desktopsmiley','Your computer is infected with Trojan Hijacker desktopsmiley . Go to http://www.safer-networking.org and get Spybot Search & Destroy, clean your machine, then come back (UA-0010). ');
$ax += inmatch($lcuseragent,'theworld)','Your computer is infected with Trojan Dropper TheWorld . Go to http://www.safer-networking.org and get Spybot Search & Destroy, clean your machine, then come back (UA-0011). ');
$ax += inmatch($lcuseragent,'360se)','Your computer is infected with Trojan Dropper 360SE . Go to http://www.safer-networking.org and get Spybot Search & Destroy, clean your machine, then come back (UA-0012). ');
$ax += inmatch($lcuseragent,'sicent','Your computer is infected with Trojan Remote Sicent . Go to http://www.safer-networking.org and get Spybot Search & Destroy, clean your machine, then come back (UA-0013.0). ');
$ax += inmatch($lcuseragent,'icafe','Your computer is infected with Trojan Remote icafe . Go to http://www.safer-networking.org and get Spybot Search & Destroy, clean your machine, then come back (UA-0013.1). ');
$ax += inmatch($lcuseragent,'msie 999.1','Invalid User Agent (UA-0014). ');
$ax += inmatch($lcuseragent,'asia','"asia" User agent. Invariably a bot (UA-0015). ');
$ax += inmatch($lcuseragent,'morfeus','hacktool "morfeus f**king scanner" (UA-0016). ');
$ax += inmatch($lcuseragent,'fuck','hacktool word. INSTA-BAN (UA-0017). ');
$ax += inmatch($lcuseragent,'casino','"casino" User agent. Invariably a bot. INSTA-BAN (UA-0018). ');
$ax += inmatch($lcuseragent,'sputnik','mail.ru suspected forum spamming bot (UA-0019). '); //mod 71
$ax += inmatch($lcuseragent,' obot','exploit scanning bot (UA-0020). '); 
$ax += inmatch($lcuseragent,'toata','Oddball bot (UA-0021). '); //70c
$ax += inmatch($lcuseragent,'dragostea','Oddball bot (UA-0022). '); //70c
$ax += inmatch($lcuseragent,'pentru','Oddball bot (UA-0023). '); //70c
$ax += inmatch($lcuseragent,'diavola','Oddball bot (UA-0024). '); //70c
$ax += inmatch($lcuseragent,'mj12bot','Use of MJ12 bot not authorized by website admin (UA-0025). '); 
$ax += inmatch($lcuseragent,'indy library','Robot Probe (modsecurity.org) (UA-0027). ');
$ax += inmatch($lcuseragent,'snoopy','Robot Probe (modsecurity.org) (UA-0028). ');
$ax += inmatch($lcuseragent,'download demon','Robot Probe (modsecurity.org) (UA-0030). ');
$ax += inmatch($lcuseragent,'libwww-pavuk','Robot Probe (modsecurity.org) (UA-0031). ');
$ax += inmatch($lcuseragent,'big brother','Robot Probe (modsecurity.org) (UA-0032). ');
$ax += inmatch($lcuseragent,'netants','Robot Probe (modsecurity.org) (UA-0033). ');
$ax += inmatch($lcuseragent,'autohttp','Robot Probe (modsecurity.org) (UA-0034). ');
$ax += inmatch($lcuseragent,'ecatch','Robot Probe (modsecurity.org) (UA-0035). ');
$ax += inmatch($lcuseragent,'deepnet','Robot Probe. INSTA-BAN (UA-0036). ');
$ax += inmatch($lcuseragent,'worio','Robot Probe. INSTA-BAN (UA-0037). ');
$ax += inmatch($lcuseragent,'mozillaxyz','Robot Probe (UA-0038). ');
$ax += inmatch($lcuseragent,'casper bot','Robot Probe. INSTA-BAN (UA-0039). ');
$ax += inmatch($lcuseragent,'dex bot','Robot Probe (UA-0040). ');
$ax += inmatch($lcuseragent,'kangen','Robot Probe (UA-0041). ');
$ax += inmatch($lcuseragent,'kmccrew','Robot Probe (UA-0042). ');
$ax += inmatch($lcuseragent,'sasqia','Robot Probe (UA-0043). ');
$ax += inmatch($lcuseragent,'sledink','Robot Probe (UA-0044). ');
$ax += inmatch($lcuseragent,'mama casper','Robot Probe. INSTA-BAN (UA-0045). ');
$ax += inmatch($lcuseragent,'planetwork','Robot Probe. INSTA-BAN (UA-0046). ');
$ax += inmatch($lcuseragent,'mama cyber','Robot Probe. INSTA-BAN (UA-0047). '); //62a
$ax += inmatch($lcuseragent,'xirio','Robot Probe (UA-0048). '); //69a
$ax += inmatch($lcuseragent,'whitehat','Robot Probe. INSTA-BAN (UA-0049). '); //69c
$ax += inmatch($lcuseragent,'aihitbot/','Robot Probe. INSTA-BAN (UA-0050). '); //69c
$ax += inmatch($lcuseragent,'zmeu','Robot Probe. INSTA-BAN (UA-0051). '); //69c
$ax += inmatch($lcuseragent,'moget','Japanese Robot Probe (UA-0052). '); //69c
$ax += inmatch($lcuseragent,'ichiro','Japanese Robot Probe (UA-0053). '); //69c
$ax += inmatch($lcuseragent,'yeti','Korean Robot Probe (UA-0054). '); //69c
$ax += inmatch($lcuseragent,'naver','Korean Robot Probe (UA-0055). '); //69c
$ax += inmatch($lcuseragent,'sogou','Chinese Robot Probe (UA-0056). '); //69c
$ax += inmatch($lcuseragent,'youdao','Chinese Robot Probe (UA-0057). '); //69c
$ax += inmatch($lcuseragent,'yodao','Chinese Robot Probe (UA-0058). '); //69c
$ax += inmatch($useragent,'MSIECrawler','Faked user agent. INSTA-BAN (UA-0059). '); //69c
$ax += inmatch($lcuseragent,'mozilla/0','Robot Probe. INSTA-BAN (UA-0060). '); //69c  //71f thanks Lucia!
$ax += inmatch($lcuseragent,'exabot',' very aggressive user agent (UA-0061). '); //69c
$ax += inmatch($lcuseragent,'soso','Chinese Robot Probe (UA-0062). '); //69c
$ax += inmatch($lcuseragent,'magpie','Snoop UA INSTA-BAN (UA-0063). '); //69c
$ax += inmatch($lcuseragent,'psbot','Image scraper (UA-0064). '); //69c
$ax += inmatch($lcuseragent,'socialsearcher','Bad bot (UA-0066). '); //69c
$ax += inmatch($lcuseragent,'lexxebot','Unknown bot (UA-0067). ');//69c
$ax += inmatch($lcuseragent,'xrumer','INSTA-BAN (UA-0068). ');//69c A user agent not worth an explanation.
$ax += inmatch($lcuseragent,'xpymep','INSTA-BAN (UA-0069). ');//69c A user agent not worth an explanation.
$ax += inmatch($lcuseragent,'shell_exec','Hack UA string (UA-0070). '); //69c.1
$ax += inmatch($lcuseragent,'if (','Hack UA string (UA-0071). '); //69c.1
$ax += inmatch($lcuseragent,'adwords','Refer Spammer UA (UA-0072). '); //69c.1
$ax += inmatch($lcuseragent,'allsubmitter','Spamtool UA (UA-0073). '); //69c.1
$ax += inmatch($lcuseragent,'anonymous','Proxy UA (UA-0074). '); //69c.1 mod 74d
$ax += inmatch($lcuseragent,'bsalsa','bsalsa user agent not allowed (UA-0076). '); //69c.1 mod 70a
$ax += inmatch($lcuseragent,'ecollector','Email Havester UA (UA-0077). '); //69c.1
$ax += inmatch($lcuseragent,'email siphon','Email Havester UA (UA-0079). '); //69c.1
$ax += inmatch($lcuseragent,'emailcollector','Email Havester UA (UA-0080). '); //69c.1
$ax += inmatch($useragent,'internet explorer/','Hack Tool UA (UA-0082). '); //69c.1
$ax += inmatch($lcuseragent,'microsoft url','Email Havester UA (UA-0083). '); //69c.1
$ax += inmatch($lcuseragent,'webbot','Obvious bot UA (UA-0084). '); //69c.1
$ax += inmatch($lcuseragent,'webcapture','Scraper UA (UA-0085). '); //69c.1
$ax += inmatch($lcuseragent,'wordpress ha','Hack Tool UA (UA-0086). '); //69c.1
$ax += inmatch($lcuseragent,'http://lycosa.se','Spammer (UA-0087). '); //69c.1
$ax += inmatch($lcuseragent,'acme.spider','Bot UA (UA-0088). '); //69c.1
$ax += inmatch($lcuseragent,'bad-neighborhood','Link dropper UA (UA-0090). '); //69c.1
$ax += inmatch($lcuseragent,'blogbot','Bot UA (UA-0091). '); //69c.1
$ax += inmatch($lcuseragent,'cyberpatrol','Bot UA (UA-0092). '); //69c.1
//$ax += lmatch($lcuseragent,'da','Abusive downloader UA (UA-0093). '); //69c.1 Removed 71 final
$ax += inmatch($lcuseragent,'datacha','Bot UA (UA-0094). '); //69c.1
$ax += inmatch($lcuseragent,'dex bot search','Bot UA (UA-0095). '); //69c.1
$ax += inmatch($lcuseragent,'digger','Email havester UA (UA-0096). '); //69c.1
$ax += inmatch($lcuseragent,'evaal','Scraper UA (UA-0098). '); //69c.1
$ax += inmatch($lcuseragent,'findlinks','Botnet UA (UA-0099). '); //69c.1
$ax += inmatch($lcuseragent,'http://www.mozilla/','Abusive UA (UA-0100). '); //69c.1
$ax += inmatch($lcuseragent,'isc systems','Email havester UA (UA-0101). '); //69c.1
$ax += inmatch($lcuseragent,'lwp','Bot UA (UA-0102). '); //69c.1
if((inmatch($lcuseragent,'xblwp7','')) && (inmatch($whyblockout,'(UA-0102)','')) && ($ax == 1)){ $ax -= 1; $whyblockout = $whyblockout . 'Windows Phone 7 bypass (BYP-UA-0102)' ;} //75a

//if (!($zbwhitelisted)){$ax += lmatch($lcuseragent,'microsoft-webdav','Bot UA (UA-0104). ');} //69c.1 - 70c mod - 71g dropped
$ax += inmatch($lcuseragent,'movable Type','Bot UA (UA-0105). '); //69c.1
$ax += inmatch($lcuseragent,'movabletype/3.3','Bot UA (UA-0106). '); //69c.1
//$ax += lmatch($lcuseragent,'mozilla ','Bot UA (UA-0107). '); //69c.1 //REMOVED 71g
$ax += inmatch($lcuseragent,'mozilla/0.','Bot UA (UA-0108). '); //69c.1
$ax += inmatch($lcuseragent,'mozilla/1.','Bot UA (UA-0109). '); //69c.1
$ax += inmatch($lcuseragent,'mozilla 4.0','Bot UA (UA-0110). '); //69c.1
$ax += inmatch($lcuseragent,'mozilla/2.0 (compatible; ask/teoma)','Bot UA (UA-0111). '); //69c.1
$ax += inmatch($lcuseragent,'mozilla/3.0 (compatible;)','Bot UA (UA-0112). '); //69c.1
$ax += inmatch($lcuseragent,'mozilla/4.0 (compatible; ics 1.2.105)','Bot UA (UA-0113). '); //69c.1
$ax += inmatch($lcuseragent,'mozilla/4.0+(compatible;+','Bot UA (UA-0114). '); //69c.1
$ax += inmatch($lcuseragent,'mozilla/4.76 [ru] (x11; U; sunos 5.7 sun4u)','Bot UA (UA-0115). '); //69c.1
$ax += inmatch($lcuseragent,'mozilla/5.0 (000000000;',"Malformed user agent possibly caused by anti-malware application. Please adjust your anti-malware application's User Agent identification settings, then come back. (UA-0116). "); //69c.1 mod 73e
$ax += inmatch($lcuseragent,'mozilla/picgrabber','Scraper UA (UA-0117). '); //69c.1
$ax += lmatch($lcuseragent,'msie','Bot UA (UA-0118). '); //69c.1
$ax += inmatch($lcuseragent,'nicebot','Bot UA (UA-0119). '); //69c.1
$ax += inmatch($lcuseragent,'obot','Bot UA (UA-0120). '); //69c.1
$ax += inmatch($lcuseragent,'offline navigator','Abusive downloader UA (UA-0121). '); //69c.1
$ax += inmatch($lcuseragent,'psycheclone','Email harvester UA (UA-0123). '); //69c.1
$ax += inmatch($lcuseragent,'smileseotools','Bot UA (UA-0124). '); //69c.1
$ax += inmatch($lcuseragent,'smile seo tools','Bot UA (UA-0125). '); //69c.1
$ax += inmatch($lcuseragent,'test','Fake UA (UA-0126). '); //69c.1
$ax += inmatch($lcuseragent,'user-agent','Fake UA (UA-0127). '); //69c.1
$ax += inmatch($lcuseragent,'webripper','Scraper UA (UA-0128). '); //69c.1
$ax += inmatch($lcuseragent,'email','General email harvester detection (UA-0130). '); //69c.1
$ax += inmatch($lcuseragent,'root','Got root? Get lost!. INSTA-BAN (UA-0131). '); //70c
$ax += inmatch($lcuseragent,'r00t','Got root? Get lost!. INSTA-BAN (UA-0132). '); //70c
$ax += inmatch($lcuseragent,'gootkit','Gootkit auto-rooter scanner Trojan. INSTA-BAN (UA-0133). '); //70c
$ax += inmatch($lcuseragent,'bootkit','Gootkit knockoff auto-rooter scanner Trojan. INSTA-BAN (UA-0134). '); //70d
$ax += inmatch($lcuseragent,' mra ','Suspected spamtool mail.ru agent (UA-0135). '); //70e
//$ax += inmatch($lcuseragent,'ahrefs','Bandwidth eating research bot (UA-0136). '); //70e Superset of SPD-104. Removed.
$ax += inmatch($lcuseragent,'mozilla/4.0 (compatible; msie 6.0; windows xp)','Bad UA (UA-0137). '); //71d
$ax += lmatch($lcuseragent,'bot','Bot UA (UA-0138). '); //71f
$ax += inmatch($lcuseragent,'alphaserver','Bad UA (UA-0139). '); //71f
$ax += inmatch($lcuseragent,'fhscan','Hacktool (UA-0140). '); //71h
$ax += inmatch($lcuseragent,'mail.ru','Mail does not work through http. (UA-0141). '); //71h
$ax += rmatch($useragent,'YI','Suspected hacktool (UA-0142). '); //71
$ax += rmatch($useragent,'YE','Suspected hacktool (UA-0142.1). '); //72a
$ax += inmatch($lcuseragent,'intelium','Hostile probe. (UA-0143). '); //71
$ax += inmatch($lcuseragent,'start.exe','Spambot. (UA-0144). '); //71
$ax += inmatch($lcuseragent,'ie 5.5 compatible browser','Unknown Scanner/Probe Attempt. (UA-0145). '); //71
$ax += inmatch($lcuseragent,'ns8/0.9.6','Probe. (UA-0146). '); //71
$ax += inmatch($lcuseragent,'mrie8pack','Known abusive user-agent (UA-0148). '); //71
$ax += inmatch($lcuseragent,'(build 5339)','Known abusive user-agent (UA-0149). '); //71
$ax += inmatch($lcuseragent,'windows seven)','Fake versioning (UA-0150). '); //71
$ax += inmatch($lcuseragent,'ips-agent','Fake verisign domain-sniper bot (UA-0151). '); //71
$ax += inmatch($lcuseragent,'u01-2','Hostile Bot (UA-0152). '); //71
//$ax += inmatch($lcuseragent,'edition campaign','Spambot (UA-0153). '); //71 removed 73d
$ax += inmatch($lcuseragent,'edition yx','Spambot (UA-0154). '); //71
//$ax += inmatch($useragent,'msn OptimizedIE8','Spambot (UA-0155). '); //71 REMOVED-FALSING
$ax += inmatch($lcuseragent,'ruru)','Spambot (UA-0156). '); //71
$ax += inmatch($lcuseragent,'seokicks','SEO tool (UA-0157). '); //71
$ax += inmatch($lcuseragent,'pogs/2.0','Potentially hostile scanner/probe (UA-0158). '); //71
$ax += inmatch($lcuseragent,'patchone','Potentially hostile scanner/probe (UA-0159). '); //71
$ax += lmatch($useragent,'B55','Vulnerability Scanner (UA-0160). '); //71 mod 75b
$ax += inmatch($lcuseragent,'photon/','Probe (UA-0161). '); //72a
$ax += inmatch($lcuseragent,'cybeye','Probe seen during attack (UA-0162). '); //72a
$ax += inmatch($lcuseragent,'webmastercoffee','WebmasterCoffee SEO tool (UA-0163). '); //72b
$ax += inmatch($lcuseragent,'seohunt','4SEOHunt bot SEO tool (UA-0164). '); //72b
$ax += inmatch($lcuseragent,'simbar','Your computer is infected with Trojan Remote SIMBAR. Go to http://www.safer-networking.org and get Spybot Search & Destroy, clean your machine, then come back (UA-0165). '); //72b
$ax += inmatch($lcuseragent,'hotbar','Your computer is infected with Trojan Spy HOTBAR . Go to http://www.safer-networking.org and get Spybot Search & Destroy, clean your machine, then come back (UA-0166). '); //72b
$ax += inmatch($lcuseragent,'bork-edition','You are running a severely outdated version of Opera which matches a hackbot or spambot profile. Please update before you return (UA-0167.0). '); //72b
$ax += inmatch($lcuseragent,'opera/0.','You are running a severely outdated version of Opera which matches a hackbot or spambot profile. Please update before you return (UA-0168.1). '); //72b
$ax += inmatch($lcuseragent,'opera/1.','You are running a severely outdated version of Opera which matches a hackbot or spambot profile. Please update before you return (UA-0168.2). '); //72b
$ax += inmatch($lcuseragent,'opera/2.','You are running a severely outdated version of Opera which matches a hackbot or spambot profile. Please update before you return (UA-0168.3). '); //72b
$ax += inmatch($lcuseragent,'opera/3.','You are running a severely outdated version of Opera which matches a hackbot or spambot profile. Please update before you return (UA-0168.4). '); //72b
$ax += inmatch($lcuseragent,'opera/4.','You are running a severely outdated version of Opera which matches a hackbot or spambot profile. Please update before you return (UA-0168.5). '); //72b
$ax += inmatch($lcuseragent,'opera/5.','You are running a severely outdated version of Opera which matches a hackbot or spambot profile. Please update before you return (UA-0168.6). '); //72b
$ax += inmatch($lcuseragent,'opera/6.','You are running a severely outdated version of Opera which matches a hackbot or spambot profile. Please update before you return (UA-0168.7). '); //72b
$ax += inmatch($lcuseragent,'opera/7.','You are running a severely outdated version of Opera which matches a hackbot or spambot profile. Please update before you return (UA-0168.8). '); //72b
$ax += inmatch($lcuseragent,'opera/8.','You are running a severely outdated version of Opera which matches a hackbot or spambot profile. Please update before you return (UA-0168.9). '); //72b
$ax += inmatch($lcuseragent,'msie 0.','You are running a severely outdated version of Internet Explorer which matches a hackbot or spambot profile. Please update before you return (UA-0169.0). '); //72b
$ax += inmatch($lcuseragent,'msie 1.','You are running a severely outdated version of Internet Explorer which matches a hackbot or spambot profile. Please update before you return (UA-0169.1). '); //72b
$ax += inmatch($lcuseragent,'msie 2.','You are running a severely outdated version of Internet Explorer which matches a hackbot or spambot profile. Please update before you return (UA-0169.2). '); //72b
$ax += inmatch($lcuseragent,'msie 3.','You are running a severely outdated version of Internet Explorer which matches a hackbot or spambot profile. Please update before you return (UA-0169.3). '); //72b
$ax += inmatch($lcuseragent,'msie 4.','You are running a severely outdated version of Internet Explorer which matches a hackbot or spambot profile. Please update before you return (UA-0169.4). '); //72b
$ax += inmatch($lcuseragent,'msie 5.','You are running a severely outdated version of Internet Explorer which matches a hackbot or spambot profile. Please update before you return (UA-0169.5). '); //72b
$ax += inmatch($lcuseragent,'firefox/0.','You are running a severely outdated version of Firefox which matches a hackbot or spambot profile. Please update before you return (UA-0170.0). '); //72b
$ax += inmatch($lcuseragent,'firefox/1.','You are running a severely outdated version of Firefox which matches a hackbot or spambot profile. Please update before you return (UA-0170.1). '); //72b
$ax += inmatch($lcuseragent,'firefox/2.','You are running a severely outdated version of Firefox which matches a hackbot or spambot profile. Please update before you return (UA-0170.2). '); //72b
$ax += inmatch($lcuseragent,'firefox/3.0.','You are running a severely outdated version of Firefox which matches a hackbot or spambot profile. Please update before you return (UA-0170.3). '); //72b
$ax += inmatch($lcuseragent,'firefox/3.1.','You are running a severely outdated version of Firefox which matches a hackbot or spambot profile. Please update before you return (UA-0170.4). '); //72b
//$ax += inmatch($lcuseragent,'firefox/3.5.','You are running a severely outdated version of Firefox which matches a hackbot or spambot profile. Please update before you return (UA-0170.5). '); //72b 73b Temp removed, due to Multiple PEBKACs, in reserve till later.
//$ax += inmatch($lcuseragent,'firefox/4.','You are running a severely outdated version of Firefox which matches a hackbot or spambot profile. Please update before you return (UA-0170.6). '); //72b 73b Temp removed, due to Multiple PEBKACs, in reserve till later.
//$ax += inmatch($lcuseragent,'firefox/5.','You are running a severely outdated version of Firefox which matches a hackbot or spambot profile. Please update before you return (UA-0170.7). '); //72b 73b Temp removed, due to Multiple PEBKACs, in reserve till later.
//$ax += inmatch($lcuseragent,'firefox/6.','You are running a severely outdated version of Firefox which matches a hackbot or spambot profile. Please update before you return (UA-0170.8). '); //72b 73c Temp removed, due to Multiple PEBKACs, in reserve till later. Thanks Google for not fixing your +1 bot.
//$ax += inmatch($lcuseragent,'firefox/7.','You are running a severely outdated version of Firefox which matches a hackbot or spambot profile. Please update before you return (UA-0170.9). '); //72b 73b Temp removed, due to Multiple PEBKACs, in reserve till later.
//$ax += inmatch($lcuseragent,'firefox/8.','You are running a severely outdated version of Firefox which matches a hackbot or spambot profile. Please update before you return (UA-0170.10). '); //72b 73b Temp removed, due to Multiple PEBKACs, in reserve till later.
$ax += inmatch($lcuseragent,'flipboard','Flipboard Proxy service, scrapes content, strips your ads (UA-0171). '); //72b
$ax += inmatch($lcuseragent,'genieo','You are blocked due to heavy malware infection. Please get Malwarebytes anti-malware free ( http://www.malwarebytes.org/products/malwarebytes_free/ ), clean your computer, and return (UA-0172). '); //73a changed description 73f
$ax += inmatch($lcuseragent,'parsijoo','parsijoo, strange and abusive Iranobot (UA-0173). '); //73a
$ax += inmatch($lcuseragent,'tweetmeme','Tweetmeme bot (FAKE) (UA-0174). '); //73b
$ax += inmatch($lcuseragent,'.seo','SEO detection (UA-0175.0). '); //73b
if (!((inmatch($lcuseragent,'www.vbseo.com','')) || ($zbwhitelisted))){$ax += inmatch($lcuseragent,'seo','SEO detection (UA-0175.1). ');} //73b modified 74c
$ax += inmatch($lcuseragent,'seo/','SEO detection (UA-175.2). '); //73b
$ax += inmatch($lcuseragent,'/seo','SEO detection (UA-175.3). '); //73b
$ax += inmatch($lcuseragent,'scrape','SEO detection (UA-176). '); //73b
$ax += inmatch($lcuseragent,'profiler','SEO detection (UA-0177). '); //73b
$ax += inmatch($lcuseragent,'smut',"We don't like smutty user-agents like mysmutsearch (UA-0178). "); //73b
$ax += inmatch($lcuseragent,'@gmail','Gmail account in user-agent is a sign of non-beneficial robot activity (UA-0179). '); //73c
$ax += inmatch($lcuseragent,'gimme60',"gimme60... You don't like bots on your site, and neither do we (UA-0180). "); //73d
$ax += inmatch($lcuseragent,'moreover','moreover feed fetcher, company engages in SEO keyword analysis/exploitation (UA-0181). '); //73d
$ax += inmatch($lcuseragent,'linkcheck','SEO spam detection (UA-0182). '); //73f
$ax += inmatch($lcuseragent,'link check','SEO spam detection (UA-0183). '); //73f
$ax += inmatch($lcuseragent,'riddler','Suspected port and vulnerability scanner. (UA-0184). '); //73f
$ax += inmatch($lcuseragent,'php /','Strange bot detected (UA-0185). '); //74a Please note, official PHP UA has no space between p and /
$ax += inmatch($lcuseragent,'abtasty','Spamvertised product(UA-0186). '); //74a
if ($lcuseragent == '-'){$ax += 1; $whyblockout = $whyblockout . 'Bad useragent (UA-0187)';} //74a
$ax += inmatch($lcuseragent,'zibber','Claims to honor, even pulls robots.txt, then ignores it (UA-0188). '); //74a
$ax += inmatch($lcuseragent,'awcheck','AwcheckBot, Ignores robots.txt (WOT), and is used for SEO keyword analyss (UA-0189). '); //74a
$ax += inmatch($lcuseragent,'captch','Captcha cracker detection (UA-0190). '); //74b
$ax += inmatch($lcuseragent,'blogsnowbot','Orphaned bot, does not pull robots.txt (UA-0191). '); //74b
$ax += inmatch($lcuseragent,'dataprovider','SEO detection (UA-0192). '); //74b
$ax += inmatch($lcuseragent,'oodlebot','Keyword scraping bot that does not pull robots.txt (UA-0193). '); //74b
$ax += inmatch($lcuseragent,'httpclient','No known clients in your class (UA-0194). '); //74b
$ax += inmatch($lcuseragent,'webmoney','WebMoney Advisor is banned (UA-0195). '); //74b
$ax += inmatch($lcuseragent,'synapse','Apache Synapse is banned due to abuse potential from other sites (UA-0196). '); //74c
$ax += inmatch($lcuseragent,'visaduhoc','Use of visaduhoc not authorized by website admin (UA-0197). '); //74c
$ax += inmatch($lcuseragent,'watchmouse','Use of watchmouse not authorized by website admin (UA-0198). '); //74c
$ax += inmatch($lcuseragent,'urlappendbot','Use of url append bot not authorized by website admin (UA-0199). '); //74c
$ax += inmatch($lcuseragent,'screener','Use of screener not authorized by website admin (UA-0200). '); //74c
$ax += inmatch($lcuseragent,'winhttp','Use of winhttp not authorized by website admin (UA-0201). '); //74c
$ax += inmatch($lcuseragent,'internet explorer','MSIE never announced as Internet Explorer (UA-0202). '); //74c
$ax += inmatch($lcuseragent,'centric','SEO bot detection (UA-0203). '); //74c
$ax += inmatch($lcuseragent,'mormor','Scrapebot (UA-0204). '); //74c
$ax += inmatch($lcuseragent,'rarely used','User agent unacceptable (UA-0205). '); //74c
$ax += inmatch($lcuseragent,'flightdeckreportsbot','Use of flight deck reports bot not authorized by website admin (UA-0206). '); //74c
$ax += inmatch($lcuseragent,'a6-indexer','Use of A6-Indexer not authorized by website admin (UA-0207). '); //74d
$ax += inmatch($lcuseragent,'prlog','Use of Prlog not authorized by website admin (UA-0208). '); //74d
$ax += inmatch($lcuseragent,'abonti','Use of Abonti not authorized by website admin (UA-0209). '); //74d
$ax += inmatch($lcuseragent,'nrsbot','Use of NetResearchServer not authorized by website admin (UA-0210). '); //74d
$ax += inmatch($lcuseragent,'accserver','Use of AccServer not authorized by website admin (UA-0211). '); //74d
$ax += inmatch($lcuseragent,'http-agent','Use of http-agent not authorized by website admin (UA-0212). '); //74d
if((inmatch($lcuseragent,'msie','')) && (inmatch($lcuseragent,'firefox',''))){ $ax += 1; $whyblockout .= 'MS Fox, or Fire Explorer? Your browser ID is ambiguous (UA-0213.0). ';}
if((inmatch($lcuseragent,'firefox','')) && (inmatch($lcuseragent,'opera',''))){ $ax += 1; $whyblockout .= 'Opfox or Fiera? Your browser ID is ambiguous (UA-0213.1). ';} //75a
if((inmatch($lcuseragent,'msie','')) && (inmatch($lcuseragent,'opera',''))){ $ax += 1; $whyblockout .= 'Oplorer or Exera? Your browser ID is ambiguous (UA-0213.2). ';} //75a
$ax += inmatch($lcuseragent,'mutant','Your browser identifies as a mutant. Please change browsers, and scan for malware (UA-0214). '); //74d
$ax += inmatch($lcuseragent,'squider/','Use of Squider not authorized by website admin (UA-0215). '); //74d
$ax += inmatch($lcuseragent,'pa crawler','Use of unrecognized bot not authorized by website admin (UA-0216). '); //74d
$ax += inmatch($lcuseragent,'xenu','We do not allow visits from the galactic overlord. What next... The Spanish Inquisition? (UA-0217) '); //74d
$ax += inmatch($lcuseragent,'   ','Illegal user agent, no known agent with %20%20%20 in it (UA-0218). '); //74d
$ax += inmatch($lcuseragent,'(b:2600;c:int-3360;l:09)','Strange UA used in different attacks (UA-0219). '); //74d
$ax += inmatch($lcuseragent,'blog search','Use of Blog Search not authorized by website admin (UA-0220). '); //74d
//$ax += minmatch($lcuseragent,'msie',1,'Ambiguous User-Agent detected (UA-0221.0). '); //74d dropped 75d
//$ax += minmatch($lcuseragent,'mozilla',1,'Ambiguous User-Agent detected (UA-0221.1). '); //74d dropped 75d
$ax += inmatch($lcuseragent,'dumprendertree','Use of DumpRenderTree not authorized by website admin (UA-0222). '); //74d
$ax += inmatch($lcuseragent,'contextad','Use of Pulsepoint not authorized by website admin (UA-0223). '); //74d
$ax += inmatch($lcuseragent,'bigbozz','Use of BigBozz not authorized by website admin (UA-0224). '); //74d
$ax += inmatch($lcuseragent,'loadimpact','Go DoS someone else\'s server ya mook! INSTA-BAN (UA-0225). '); //74d
//$ax += inmatch($lcuseragent,'clam antivirus','Use of Clam AntiVirus not authorized by website admin (UA-0226). '); //74d
$ax += inmatch($lcuseragent,' audit','Questionable UA (UA-0227). '); //75a
$ax += inmatch($lcuseragent,'unlock','Questionable UA (UA-0228). '); //75a
$ax += inmatch($lcuseragent,'cheap','Questionable UA (UA-0229). '); //75a
$ax += inmatch($lcuseragent,'>click','Questionable UA (UA-0230). '); //75a
$ax += inmatch($lcuseragent,'reviewsx','Questionable UA (UA-0231). '); //75a
$ax += inmatch($lcuseragent,'jailbreak','Questionable UA (UA-0232). '); //75a
$ax += inmatch($lcuseragent,'outlet','Questionable UA (UA-0233). '); //75a
$ax += inmatch($lcuseragent,'violation','Questionable UA (UA-0234). '); //75a
$ax += inmatch($lcuseragent,'keylogger','Questionable UA (UA-0235). '); //75a
$ax += inmatch($lcuseragent,'topless','Questionable UA (UA-0236). '); //75a
$ax += inmatch($lcuseragent,' quibids ','Questionable UA (UA-0237). '); //75a
$ax += inmatch($lcuseragent,'sexy','Questionable UA (UA-0238). '); //75a
$ax += inmatch($lcuseragent,'guestbook','Questionable UA (UA-0239). '); //75a
$ax += inmatch($lcuseragent,'/how-','Questionable UA (UA-0240). '); //75a
$ax += inmatch($lcuseragent,'orgasm','Questionable UA (UA-0241). '); //75a
$ax += inmatch($lcuseragent,'vpngate','VPNGate, Free VPN network that is anonymous, and untracable for bad behavior (UA-0242). '); //75a
$ax += inmatch($lcuseragent,'admantx','Use of ADmantX not authorized by website admin (UA-0243). '); //75a
$ax += inmatch($lcuseragent,'analyzer','Use of site analyzers not authorized by website admin (UA-0244). '); //75a
$ax += inmatch($lcuseragent,'isitwp','Use of site analyzers not authorized by website admin (UA-0245). '); //75a
$ax += inmatch($lcuseragent,'socialayer','Use of socialayer agent not authorized by website admin (UA-0246). '); //75a
$ax += inmatch($lcuseragent,'a6-indexer','Known scraper bot (UA-0247). '); //75a
$ax += inmatch($lcuseragent,'nettrapport','Usage of NettRapport not authorised by website admin. (UA-0248). '); //75a
$ax += inmatch($lcuseragent,'phpcrawl','Usage of PHPCrawl not authorised by website admin. (UA-0249). '); //75a
$ax += inmatch($lcuseragent,'wikiapiary','Usage of Wikiapiary\'s products is not authorised by website admin. (UA-0250). '); //75a
$ax += inmatch($lcuseragent,'zurich financial services','ZFS products not authorized by website admin. (UA-0251). '); //75a
$ax += inmatch($lcuseragent,'macinroy privacy auditors','MacInroy Privacy Auditors not authorized by website admin. (UA-0252). '); //75a
$ax += inmatch($lcuseragent,'anyevent-http','AnyEvent-HTTP is not authorized by the system administrator (UA-0253). ');


// Fake googlebot handler.
// Modified 71h & 72b

if ((!((rmatch($hoster,'.googlebot.com','')) || (lmatch($address,'74.125','')) || (lmatch($address,'66.249','')))) && (inmatch($lcuseragent,'googlebot',''))){
  $tempwbo = 'Bad UA. ' . $hoster . ' is not a valid googlebot domain. See: http://googlewebmastercentral.blogspot.com/2006/09/how-to-verify-googlebot.html  (UA-139). ';
  $ax += (inmatch($lcuseragent,'googlebot',$tempwbo));
}

// *Spider Eating (These are bad spiders you don't want in your site. All ignore robots.txt)

$ax += inmatch($lcuseragent,'fast enterprise crawler','Dubious spider UA (SPD-0002). '); //69c.1
$ax += inmatch($lcuseragent,'k2spider','Dubious spider UA (SPD-0003). '); //69c.1
$ax += inmatch($lcuseragent,'scspider','Dubious spider UA (SPD-0004). '); //69c.1
$ax += inmatch($lcuseragent,'seznambot','Dubious spider UA (SPD-0005). '); //69c.1
$ax += inmatch($lcuseragent,'sohu agent','Dubious spider UA (SPD-0007). '); //69c.1
$ax += inmatch($lcuseragent,'voilabot','Dubious spider UA (SPD-0008). '); //69c.1
$ax += inmatch($lcuseragent,'dotbot','Dotbot - Paid Service SEO Service (Keyword Spamming Aides) (SPD-0009). ');
$ax += inmatch($lcuseragent,'omgilibot','Israel Server-Farm, sometimes use Python-urllib/1.17, does not use robots.txt (SPD-0010). '); 
$ax += inmatch($lcuseragent,'collect','Rogue Site Crawler (modsecurity.org) (SPD-0011). '); 
$ax += inmatch($lcuseragent,'magnet','Rogue Site Crawler (modsecurity.org) (SPD-0012). '); 
$ax += inmatch($lcuseragent,'extractor','Rogue Site Crawler (modsecurity.org) (SPD-0013). '); 
if(lmatch($lcuseragent,'windows-live-social-object-extractor','MSN Messenger poof! (SPD-0014). ')){ die(''); } //69e
$ax += inmatch($lcuseragent,'reaper','Rogue Site Crawler (modsecurity.org) (SPD-0015). '); 
$ax += inmatch($lcuseragent,'siphon','Rogue Site Crawler (modsecurity.org) (SPD-0016). '); 
$ax += inmatch($lcuseragent,'wolf','Rogue Site Crawler (modsecurity.org) (SPD-0017). '); 
$ax += inmatch($lcuseragent,'irgrabber','Rogue Site Crawler (modsecurity.org) (SPD-0018). '); 
$ax += inmatch($lcuseragent,'xtractorpro','Rogue Site Crawler (modsecurity.org) (SPD-0019). '); 
$ax += inmatch($lcuseragent,'attache','Rogue Site Crawler (modsecurity.org) (SPD-0020). '); 
$ax += inmatch($lcuseragent,'athens','Rogue Site Crawler (modsecurity.org) (SPD-0021). '); 
$ax += inmatch($lcuseragent,'emailspider','Rogue Site Crawler (modsecurity.org) (SPD-0022). '); 
$ax += inmatch($lcuseragent,'dsarobot','Rogue Site Crawler (modsecurity.org) (SPD-0023). '); 
$ax += inmatch($lcuseragent,'emailex','Rogue Site Crawler (modsecurity.org) (SPD-0024). '); 
$ax += inmatch($lcuseragent,'3mir','Rogue Site Crawler (modsecurity.org) (SPD-0025). '); 
$ax += inmatch($lcuseragent,'fastlwspider','Rogue Site Crawler (modsecurity.org) (SPD-0026). '); 
$ax += inmatch($lcuseragent,'floodgate','Rogue Site Crawler (modsecurity.org) (SPD-0027). '); 
$ax += inmatch($lcuseragent,'pcbrowser','Rogue Site Crawler (modsecurity.org) (SPD-0028). '); 
$ax += inmatch($lcuseragent,'packrat','Rogue Site Crawler (modsecurity.org) (SPD-0029). '); 
$ax += inmatch($lcuseragent,'psurf','Rogue Site Crawler (modsecurity.org) (SPD-0030). '); 
$ax += inmatch($lcuseragent,'digout4uagent','Rogue Site Crawler (modsecurity.org) (SPD-0031). '); 
$ax += inmatch($lcuseragent,'takeout','Rogue Site Crawler (modsecurity.org) (SPD-0032). '); 
$ax += inmatch($lcuseragent,'cha0s','Rogue Site Crawler (modsecurity.org) (SPD-0033). '); 
$ax += inmatch($lcuseragent,'chinaclaw','Rogue Site Crawler (modsecurity.org) (SPD-0034). '); 
$ax += inmatch($lcuseragent,'rsync','Rogue Site Crawler (modsecurity.org) (SPD-0035). '); 
$ax += inmatch($lcuseragent,'shai','Rogue Site Crawler (modsecurity.org) (SPD-0036). '); 
$ax += inmatch($lcuseragent,'zeus','Rogue Site Crawler (modsecurity.org) (SPD-0037). '); 
$ax += inmatch($lcuseragent,'nutch','Rogue Site Crawler (SPD-0038). ');
$ax += inmatch($lcuseragent,'webster','Rogue Site Crawler. INSTA-BAN (SPD-0039).'); //70d expanded from "webster pro"
$ax += inmatch($lcuseragent,'dkimrepbot','Bad spider, does not use robots.txt (SPD-0040). '); 
$ax += inmatch($lcuseragent,'_sitemapper','Bad spider, does not use robots.txt (SPD-0041). '); 
$ax += inmatch($lcuseragent,'tasapspider','Bad spider, does not use robots.txt (SPD-0042). '); 
$ax += inmatch($lcuseragent,'jadynavebot','Bad spider, does not use robots.txt (SPD-0043). '); 
$ax += inmatch($lcuseragent,'emailsearch','Bad spider, does not use robots.txt (SPD-0044). '); 
$ax += inmatch($lcuseragent,'rulinki','Bad spider, does not use robots.txt (SPD-0045). '); 
$ax += inmatch($lcuseragent,'irc search','Bad spider, does not use robots.txt (SPD-0046). '); 
$ax += inmatch($lcuseragent,'mentormate','Bad spider, does not use robots.txt (SPD-0047). '); 
$ax += inmatch($lcuseragent,'larbin','Scrapebot, does not use robots.txt (SPD-0048). ');
$ax += inmatch($lcuseragent,'binlar','Scrapebot, does not use robots.txt (SPD-0048.1). '); //74f
$ax += inmatch($lcuseragent,'harvest','Scrapebot, does not use robots.txt (SPD-0049). ');
$ax += inmatch($lcuseragent,'jakarta','Scrapebot, does not use robots.txt (SPD-0050). ');
$ax += inmatch($lcuseragent,'accelo','Content scraper for paid service (SPD-0051). ');
$ax += inmatch($lcuseragent,'oozbot','Email harvester from India (SPD-0052). ');
$ax += inmatch($lcuseragent,'artviper','Scrapebot, does not use robots.txt (SPD-0053). ');
$ax += inmatch($lcuseragent,'vbseo','Scrapebot, SEO scum (SPD-0054). ');
$ax += inmatch($lcuseragent,'dotnetdotcom','SEOMOZ keyword scraper (SPD-0055). ');
$ax += inmatch($lcuseragent,'dotcomdotnet','SEOMOZ keyword scraper (SPD-0056). ');
$ax += inmatch($lcuseragent,'ccbot','Vague, nutch like scraper (SPD-0057). '); //62a
$ax += inmatch($lcuseragent,'3d-ftp','Possibly hostile scraper/harvester (SPD-0058). '); //62a
$ax += inmatch($lcuseragent,'boitho','Possibly hostile scraper/harvester (SPD-0059). '); //62a
$ax += inmatch($lcuseragent,'bpimagewalker','Possibly hostile scraper/harvester (SPD-0060). '); //62a
$ax += inmatch($lcuseragent,'cr4nk','Possibly hostile scraper/harvester (SPD-0061). '); //62a
$ax += inmatch($lcuseragent,'enabot','Possibly hostile scraper/harvester (SPD-0062). '); //62a
$ax += inmatch($lcuseragent,'envolk','Possibly hostile scraper/harvester (SPD-0063). '); //62a
$ax += inmatch($lcuseragent,'eurobot','Possibly hostile scraper/harvester (SPD-0064). '); //62a
$ax += inmatch($lcuseragent,'geturl11','Possibly hostile scraper/harvester (SPD-0065). '); //62a
$ax += inmatch($lcuseragent,'grub','Possibly hostile scraper/harvester (SPD-0066). '); //62a
$ax += inmatch($lcuseragent,'gurujibot','Possibly hostile scraper/harvester (SPD-0067). '); //62a
$ax += inmatch($lcuseragent,'heritrix','Possibly hostile scraper/harvester (SPD-0068). '); //62a
$ax += inmatch($lcuseragent,'holmes','Possibly hostile scraper/harvester (SPD-0069). '); //62a
$ax += inmatch($lcuseragent,'httpunit','Possibly hostile scraper/harvester (SPD-0070). '); //62a
$ax += inmatch($lcuseragent,'keywenbot','Possibly hostile scraper/harvester (SPD-0071). '); //62a
$ax += inmatch($lcuseragent,'linkwalker','Possibly hostile scraper/harvester (SPD-0072). '); //62a
$ax += inmatch($lcuseragent,'mahiti','Possibly hostile scraper/harvester (SPD-0073). '); //62a
$ax += inmatch($lcuseragent,'mot-v980','Possibly hostile scraper/harvester (SPD-0074). '); //62a
$ax += inmatch($lcuseragent,'multicrawler','Possibly hostile scraper/harvester (SPD-0075). '); //62a
$ax += inmatch($lcuseragent,'page_verifier','Possibly hostile scraper/harvester (SPD-0076). '); //62a
$ax += inmatch($lcuseragent,'path 2','Possibly hostile scraper/harvester (SPD-0077). '); //62a
$ax += inmatch($lcuseragent,'poe-component-client-http','Possibly hostile scraper/harvester (SPD-0078). '); //62a
$ax += inmatch($lcuseragent,'rankivabot','Possibly hostile scraper/harvester (SPD-0079). '); //62a
$ax += inmatch($lcuseragent,'rebi-shoveler','Possibly hostile scraper/harvester (SPD-0080). '); //62a
$ax += inmatch($lcuseragent,'sbider','Possibly hostile scraper/harvester (SPD-0081). '); //62a
$ax += inmatch($lcuseragent,'tagsdir','Possibly hostile scraper/harvester (SPD-0082). '); //62a
$ax += inmatch($lcuseragent,'turnitinbot','Possibly hostile scraper/harvester (SPD-0083). '); //62a
$ax += inmatch($lcuseragent,'visbot','Possibly hostile scraper/harvester (SPD-0084). '); //62a
$ax += inmatch($lcuseragent,'wauuu','Possibly hostile scraper/harvester (SPD-0085). '); //62a
$ax += inmatch($lcuseragent,'webalta','Possibly hostile scraper/harvester (SPD-0086). '); //62a
$ax += inmatch($lcuseragent,'wget','Possibly hostile scraper/harvester, signature may interfere with some Wordpress installs (SPD-0087). '); //62a
$ax += inmatch($lcuseragent,'winhttp','Possibly hostile scraper/harvester (SPD-0088). '); //62a
$ax += inmatch($lcuseragent,'yoofind','Possibly hostile scraper/harvester (SPD-0090). '); //62a
$ax += inmatch($lcuseragent,'indocom','Possibly hostile scraper/harvester (SPD-0091). '); //65b
$ax += inmatch($lcuseragent,'80legs','Confirmed hostile scraper/harvester, INSTA-BAN (SPD-0092). '); //65c Upgraded to instant 74b
$ax += inmatch($lcuseragent,'purity','Possibly hostile scraper/harvester (SPD-0093). '); //65c
$ax += inmatch($lcuseragent,'purebot','Possibly hostile scraper/harvester (SPD-0094). '); //65c
$ax += inmatch($lcuseragent,'httrack','Possibly hostile scraper/harvester (SPD-0095). '); //65c
$ax += inmatch($lcuseragent,'sniper','Possibly hostile scraper/harvester (SPD-0096). '); //69b
$ax += inmatch($lcuseragent,'affinity','Possibly hostile scraper/harvester (SPD-0097). '); //69b
$ax += inmatch($lcuseragent,'discobot','Possibly hostile scraper/harvester (SPD-0098). '); //69b
$ax += inmatch($lcuseragent,'web downloader','Possibly hostile scraper/harvester (SPD-0099). '); //69f
$ax += inmatch($lcuseragent,'appengine-google','Google Cloud Services. Not Google Search (SPD-0100). '); //69d
$ax += lmatch($lcuseragent,'spider','Generic scrapebot, does not use robots.txt (SPD-0102). '); 
$ax += inmatch($lcuseragent,'ezoom','Possibly hostile scraper/harvester. New dotnetdotcom bot (SPD-0103). '); //69d
$ax += inmatch($lcuseragent,'ahref','Possibly hostile scraper/harvester (SPD-0104). '); //70b
$ax += inmatch($lcuseragent,'centiverse','Possibly hostile scraper/harvester (SPD-0105). '); //70e
$ax += inmatch($lcuseragent,'lushbot','Possibly hostile scraper/harvester (SPD-0106). '); //70e
$ax += inmatch($lcuseragent,'dts agent','Possibly hostile scraper/harvester (SPD-0107). '); //71b
$ax += inmatch($lcuseragent,'digext','Possibly hostile scraper/harvester (SPD-0108). '); //71b
$ax += inmatch($lcuseragent,'mlbot','Possibly hostile scraper/harvester (SPD-0109). '); //71b
$ax += inmatch($lcuseragent,'yandex','Yandex is banned. INSTA-BAN (SPD-0110). '); //71b
$ax += inmatch($lcuseragent,'swebot','Possibly hostile scraper/harvester (SPD-0111). '); //71c
$ax += inmatch($lcuseragent,'voyager/1.0','Possibly hostile scraper/harvester (SPD-0112). '); //71c
$ax += inmatch($lcuseragent,'pagegetter','Possibly hostile scraper/harvester (SPD-0113). '); //71c
$ax += inmatch($lcuseragent,'fetchor','Possibly hostile scraper/harvester (SPD-0114). '); //71c
$ax -= inmatch($lcuseragent,'unwindfetchor','UnwindFetchor bypass (BYP-SPD-114). '); //71c
$ax += inmatch($lcuseragent,'kimengi','Possibly hostile scraper/harvester (SPD-0115). '); //71c
$ax += inmatch($lcuseragent,'nineconnections','Possibly hostile scraper/harvester (SPD-0116). '); //71c
$ax += inmatch($lcuseragent,'inagist','Possibly hostile scraper/harvester (SPD-0117). '); //71c
//$ax += inmatch($lcuseragent,'showyoubot','Possibly hostile scraper/harvester (SPD-0118). '); //71c Removed 72b Facebook Linked
$ax += inmatch($lcuseragent,'kkman','Possibly hostile scraper/harvester (SPD-0119). '); //71d
$ax += inmatch($lcuseragent,'eak01ag9','Blackhat opera spoof pre-spam crawler (SPD-0120). '); //71d
$ax += inmatch($lcuseragent,'dcpbot','Scraper and/or Harvester UA (SPD-0121). '); //71d
$ax += inmatch($lcuseragent,'sistrix','Scraper and/or Harvester UA (SPD-0122). '); //71d
$ax += inmatch($lcuseragent,'pixray','Scraper and/or Harvester UA (SPD-0123). '); //71d
$ax += inmatch($lcuseragent,'wotbox','Scraper and/or Harvester UA (SPD-0124). '); //71d
$ax += inmatch($lcuseragent,'crawlfire','Scraper and/or Harvester UA (SPD-0126). '); //71d
$ax += inmatch($lcuseragent,'siteintel','Scraper and/or Harvester UA (SPD-0128). '); //71d
$ax += inmatch($lcuseragent,'spbot','Scraper and/or Harvester UA (SPD-0129). '); //71d
$ax += inmatch($lcuseragent,'seoprofiler','Scraper and/or Harvester UA (SPD-0130). '); //71d
$ax += inmatch($lcuseragent,'mahonie','Scraper and/or Harvester UA (SPD-0131). '); //71d
$ax += inmatch($lcuseragent,'neofonie','Scraper and/or Harvester UA (SPD-0132). '); //71d
$ax += inmatch($lcuseragent,'mia bot','Scraper and/or Harvester UA (SPD-0133). '); //71d
$ax += inmatch($lcuseragent,'ssearch','Scraper and/or Harvester UA (SPD-0134). '); //71d
$ax += inmatch($lcuseragent,'news bot','Scraper and/or Harvester UA (SPD-0135). '); //71d
$ax += inmatch($lcuseragent,'sbl-bot','Scraper and/or Harvester UA (SPD-0136). '); //71d
$ax += inmatch($lcuseragent,'sbl.net','Scraper and/or Harvester UA (SPD-0137). '); //71d
$ax += inmatch($lcuseragent,'updowner','Scraper and/or Harvester UA (SPD-0138). '); //71d
$ax += inmatch($lcuseragent,'curious george','Scraper and/or Harvester UA (SPD-0139). '); //71d
$ax += inmatch($lcuseragent,'analyticsseo','Scraper and/or Harvester UA (SPD-0140). '); //71d
$ax += inmatch($lcuseragent,'influencebot','Scraper and/or Harvester UA (SPD-0141). '); //71d
$ax += inmatch($lcuseragent,'bnf.fr','French IntProp infoscraper UA (SPD-0142). '); //71d
$ax += inmatch($lcuseragent,'brandwatch','Snoop UA (SPD-0143). '); //71d
$ax += inmatch($lcuseragent,'salad','Shopsalad UA (defunct domain, no whois) (SPD-0144). '); //71d
$ax += inmatch($lcuseragent,'ryze','Domain name sniping UA (SPD-0145). '); //71d
$ax += inmatch($lcuseragent,'blekko','Dubious search bot (SPD-0146). '); //71d
$ax += inmatch($lcuseragent,'page fetcher','Possibly hostile scraper/harvester (SPD-0147). '); //71c mod 71e
$ax += inmatch($lcuseragent,'image-fetcher','Possibly hostile scraper/harvester (SPD-0148). '); //71e
$ax += inmatch($lcuseragent,'image fetcher','Possibly hostile scraper/harvester (SPD-0149). '); //71e
$ax += inmatch($lcuseragent,'fetch/','Possibly hostile scraper/harvester (SPD-0150). '); //71e
$ax += inmatch($lcuseragent,'http fetcher','Possibly hostile scraper/harvester (SPD-0151). '); //71e
$ax += inmatch($lcuseragent,'boardreader','Possibly hostile scraper/harvester (SPD-0152). '); //71e
$ax += inmatch($lcuseragent,'sitebot','Possibly hostile scraper/harvester (SPD-0153). '); //71f
$ax += inmatch($lcuseragent,'cydral','Possibly hostile scraper/harvester (SPD-0154). '); //71f
$ax += inmatch($lcuseragent,'aghaven','Possibly hostile scraper/harvester (SPD-0155). '); //71f
$ax += inmatch($lcuseragent,'linkdex','Possibly hostile scraper/harvester (SPD-0156). '); //71f
$ax += inmatch($lcuseragent,'bazqux','Possibly hostile scraper/harvester (SPD-0157). '); //71f
$ax += inmatch($lcuseragent,'getty','Possibly hostile scraper/harvester (SPD-0158). '); //71f
$ax += inmatch($lcuseragent,'googlealerts','Possibly hostile scraper/harvester (SPD-0159). '); //71f
$ax += inmatch($lcuseragent,'debate','Possibly hostile scraper/harvester (SPD-0160). '); //71f
$ax += inmatch($lcuseragent,'coverscout','Possibly hostile scraper/harvester (SPD-0161). '); //71f
$ax += inmatch($lcuseragent,'tineye','Possibly hostile scraper/harvester (SPD-0162). '); //71f
$ax += inmatch($lcuseragent,'cmsworldmap','Possibly hostile scraper/harvester (SPD-0163). '); //71f
$ax += inmatch($lcuseragent,'windows nt;','Possibly hostile scraper/harvester (SPD-0164). '); //71f
$ax += inmatch($lcuseragent,'windows 3','Possibly hostile scraper/harvester (SPD-0165). '); //71f
$ax += inmatch($lcuseragent,'t-h-u-n','Possibly hostile scraper/harvester (SPD-0166). '); //71f
$ax += inmatch($lcuseragent,'proximic','Possibly hostile scraper/harvester (SPD-0167). '); //71f
$ax += inmatch($lcuseragent,'picture finder','Possibly hostile scraper/harvester (SPD-0169). '); //71f
$ax += inmatch($lcuseragent,'imagewalker','Possibly hostile scraper/harvester (SPD-0170). '); //71f
$ax += inmatch($lcuseragent,'doubanbot','Possibly hostile scraper/harvester (SPD-0171). '); //71f
$ax += inmatch($lcuseragent,'reverseget','Possibly hostile scraper/harvester (SPD-0172). '); //71f
$ax += inmatch($lcuseragent,'rganalytics','Possibly hostile scraper/harvester (SPD-0173). '); //71f
$ax += inmatch($lcuseragent,'wikio','Possibly hostile scraper/harvester (SPD-0175). '); //71f
$ax += inmatch($lcuseragent,'python','Possibly hostile scraper/harvester (SPD-0176). '); //71f
$ax += inmatch($lcuseragent,'powermarks','Possibly hostile scraper/harvester (SPD-0177). '); //71f
$ax += inmatch($lcuseragent,'keywordsearchtool','Possibly hostile scraper/harvester (SPD-0178). '); //71f
$ax += inmatch($lcuseragent,'chilkat','Possibly hostile scraper/harvester (SPD-0179). '); //71f
$ax += inmatch($lcuseragent,'panscient','Possibly hostile scraper/harvester (SPD-0180). '); //71f
$ax += inmatch($lcuseragent,'liperhey','Possibly hostile scraper/harvester (SPD-0181). '); //71f
$ax += inmatch($lcuseragent,'daylife','Possibly hostile scraper/harvester (SPD-0184). '); //71f
$ax += inmatch($lcuseragent,'nsplayer','Possibly hostile scraper/harvester (SPD-0185). '); //71f
$ax += inmatch($lcuseragent,'vlc/','Possibly hostile scraper/harvester (SPD-0186). '); //71f
$ax += inmatch($lcuseragent,'traumacadx','Possibly hostile scraper/harvester (SPD-0187). '); //71f
$ax += inmatch($lcuseragent,'upictobot','Possibly hostile scraper/harvester (SPD-0188). '); //71f
$ax += inmatch($lcuseragent,'mattters','Possibly hostile scraper/harvester (SPD-0189). '); //71f
$ax += inmatch($lcuseragent,'commoncrawl','Possibly hostile scraper/harvester (SPD-0190). '); //71f
$ax += inmatch($lcuseragent,'pixmatch','Possibly hostile scraper/harvester (SPD-0191). '); //71f
$ax += inmatch($lcuseragent,'copyright','Possibly hostile scraper/harvester (SPD-0192). '); //71f
$ax += inmatch($lcuseragent,'abot','Possibly hostile scraper/harvester (SPD-0193). '); //71f
$ax += inmatch($lcuseragent,'aipbot','Possibly hostile scraper/harvester (SPD-0194). '); //71f
$ax += inmatch($lcuseragent,'pics','Possibly hostile scraper/harvester (SPD-0195). '); //71f
$ax += inmatch($lcuseragent,'pictsnapshot','Possibly hostile scraper/harvester (SPD-0196). '); //71f
$ax += inmatch($lcuseragent,'netseer','Possibly hostile scraper/harvester (SPD-0198). '); //71f
$ax += inmatch($lcuseragent,'bitvo','Possibly hostile scraper/harvester (SPD-0200). '); //71f
$ax += inmatch($lcuseragent,'pipl','Possibly hostile scraper/harvester (SPD-0201). '); //71f
$ax += inmatch($lcuseragent,'bender','Possibly hostile scraper/harvester (SPD-0202). '); //71f
$ax += inmatch($lcuseragent,'semrush','Possibly hostile scraper/harvester (SPD-0203). '); //71f
//if (!(inmatch($requesturi,'/wp-cron.php?','WordPress cronjob bypass. '))){$ax += inmatch($lcuseragent,'wordpress/','Possibly hostile scraper/harvester (SPD-0204). ');} //71f REMOVED TO CUSTOMSIG.INC only in 72b
$ax += inmatch($lcuseragent,'bogahn','Possibly hostile scraper/harvester (SPD-0205). '); //71f
$ax += inmatch($lcuseragent,'gslfbot','Possibly hostile scraper/harvester (SPD-0208). '); //71f
$ax += inmatch($lcuseragent,'vonchimpenfurlr',"Shock the monkey tonight! (MailChimp's, unwanted link validator) (SPD-0210). "); //71f Changed 73b
$ax += inmatch($lcuseragent,'komodiabot','Bot not obeying nofollow (SPD-0211). '); //71f
$ax += inmatch($lcuseragent,'wbsearchbot','Possibly hostile scraper/harvester (SPD-0212). '); //71f
$ax += inmatch($lcuseragent,'warebay','Possibly hostile scraper/harvester (SPD-0213). '); //71f
$ax += inmatch($lcuseragent,'jike','Possibly hostile scraper/harvester (SPD-0214). '); //71g
$ax += inmatch($lcuseragent,'360spider','Possibly hostile scraper/harvester (SPD-0215). '); //71h
$ax += inmatch($lcuseragent,'fibgen','Possibly hostile scraper/harvester (SPD-0216). '); //71h
$ax += inmatch($lcuseragent,'worldbot','Possibly hostile scraper/harvester (SPD-0217). '); //71h
$ax += inmatch($lcuseragent,'seoeng','Possibly hostile scraper/harvester (SPD-0218). '); //71h
$ax += inmatch($lcuseragent,'topseo','Possibly hostile scraper/harvester (SPD-0219). '); //71h
$ax += inmatch($lcuseragent,'seostat','Possibly hostile scraper/harvester (SPD-0220). '); //71h
$ax += inmatch($lcuseragent,'coccoc','Spider caught being abusive (SPD-0221). '); //71
$ax += inmatch($lcuseragent,'compspy','Unwanted spider (SPD-0222). '); //71
$ax += inmatch($lcuseragent,'mrchrome','Scrapebot (SPD-0223). '); //71
$ax += inmatch($lcuseragent,'webmoney advisor','Scrapebot (SPD-0224). '); //71
$ax += inmatch($lcuseragent,'plukkie','Unverifiable search engine(SPD-0225). '); //71
$ax += inmatch($lcuseragent,'aboundex','Unverifiable search engine(SPD-0226). '); //71
$ax += inmatch($lcuseragent,'vagabondo','SEO Spider (SPD-0227). '); //71
$ax += inmatch($lcuseragent,'wise-guys','SEO Spider (SPD-0228). '); //71
$ax += inmatch($lcuseragent,'radian6','SEO Spider (SPD-0229). '); //71
$ax += inmatch($lcuseragent,'comment','Wide based SEO Spider detection (SPD-0230). '); //71
$ax += inmatch($lcuseragent,'r6_','SEO Spider (SPD-0231). '); //71
$ax += inmatch($lcuseragent,'200please','SEO Spider (SPD-0232). '); //72b
$ax += inmatch($lcuseragent,'mail.ru','Hostile spider (SPD-0233). '); //72b
$ax += inmatch($lcuseragent,'yacy','Distributed Search Spider (SPD-0234). '); //73a
$ax += inmatch($lcuseragent,'backlink','General backlink checker (SPD-0235). '); //73b
$ax += inmatch($lcuseragent,'joc','Joc web spider not allowed (SPD-0236). '); //73d
$ax += inmatch($lcuseragent,'solomono','SolomonoBot, SEO bot. Scrapes sites, then checks robots.txt for more URLS, and hits honeypots. (SPD-0237). '); //73d
$ax += inmatch($lcuseragent,'saidwot','SaidWot reputation spider (SPD-0238). '); //73d
$ax += inmatch($lcuseragent,'linguee',"Linguee bot. Doesn't like robots.txt (SPD-0239). "); //73d
$ax += inmatch($lcuseragent,'rocketcrawler','LightSpeed systems censor bot, scrapes sites proactively instead of on use (SPD-0240). '); //73d
$ax += inmatch($lcuseragent,'integromedb','There is no medical info on this site for integromedb to scrape (SPD-0241). '); //73d
$ax += inmatch($lcuseragent,'easou','Robot that has been caught not pulling robots.txt before hitting honeypot (SPD-0242). '); //73d
$ax += inmatch($lcuseragent,'ip-web-crawler','Intellectual property user-agent, puts sites in jeopardy of lawsuit (SPD-0243). '); //73d
$ax += inmatch($lcuseragent,'pagesinventory','Pages Inventory bot, suspected back-end to an SEO service (SPD-0244). '); //73d
$ax += inmatch($lcuseragent,'nextgensearchbot',"NextGenSearchBot, SEO bot with bad behavior, does not follow robots.txt, and looks for suspected 'sploit files (SPD-0245). "); //73d
$ax += inmatch($lcuseragent,'bixo','Bixo crawler, private crawler of dubious use (SPD-0246). '); //73e
$ax += inmatch($lcuseragent,'dioscout','DioScout, blind RSS grabs without visiting robots.txt (SPD-0247). '); //73e
$ax += inmatch($lcuseragent,'crawler4j','crawler4j, chinanet educational crawler hosted on google code? (SPD-0248). '); //73f
$ax += inmatch($lcuseragent,'funbot',"Funbot Link Checker, Checks to see the status of it's spam on your site (SPD-0249). "); //73f
$ax += inmatch($lcuseragent,'catchbot','Catchbot b2b indexer, does not check robots.txt (SPD-0250). '); //74a
$ax += inmatch($lcuseragent,'searchmetricsbot','SearchmetricsBot, SEO crawler, caught not accessing robots.txt (SPD-0251)'); //74a
$ax += inmatch($lcuseragent,'dow jones searchbot','Dow Jones Searchbot is a site scraper (SPD-0252). '); //74b
$ax += inmatch($lcuseragent,'yisouspider','Old nasty spider, still on the loose (SPD-0253). '); //74b fixed 74d
$ax += inmatch($lcuseragent,'netcomber','netcomber.com, provides no benefit to webmasters, ignores robots.txt (WOT report), and probes to disclose hidden details (SPD-0254). '); //74b
$ax += inmatch($lcuseragent,'meanpath','Use of meanpathbot not authorized by website admin (SPD-0255). '); //74c
$ax += inmatch($lcuseragent,'blex','Use of blexbot not authorized by website admin (SPD-0256). '); //74c
$ax += inmatch($lcuseragent,'webmeup','Use of webmeup not authorized by website admin (SPD-0257). '); //74c
$ax += inmatch($lcuseragent,'linkscrawler','Use of linkscrawler not authorized by website admin (SPD-0258). '); //74c
$ax += inmatch($lcuseragent,'adnormcrawler','Use of adnormcrawler not authorized by website admin (SPD-0259). '); //74c
$ax += inmatch($lcuseragent,'yyspider','Use of YYSpider not authorized by website admin (SPD-0260.0). '); //74c
$ax += inmatch($lcuseragent,'yunyun','Use of YYSpider not authorized by website admin (SPD-0260.1). '); //74c
$ax += inmatch($lcuseragent,'yrspider','Use of YRSpider not authorized by website admin (SPD-0260.2). '); //74c
$ax += inmatch($lcuseragent,'yunrang','Use of YRSspider not authorized by website admin (SPD-0260.3). '); //74c
$ax += inmatch($lcuseragent,'grapeshot','Use of Grapeshot Crawler not authorized by website admin (SPD-0261). '); //74d
$ax += inmatch($lcuseragent,'hubspot','Use of HubSpot not authorized by website admin (SPD-0262). '); //74d
$ax += inmatch($lcuseragent,'imrbot','Use of imrbot not authorized by website admin (SPD-0263). '); //74d
$ax += inmatch($lcuseragent,'mignify','Use of Mignify not authorized by website admin (SPD-0264). '); //74d
$ax += inmatch($lcuseragent,'sickseo','Backlink checker (SPD-0265). '); //73b mod 74d
$ax += inmatch($lcuseragent,'struct.it','Use of Struct.it crawler not authorized by website admin (SPD-0266). '); //75a
$ax += inmatch($lcuseragent,'ossproxy','Your computer is infected with spyware "Marketscore". Please use Malware Bytes Anti-Malware free from :http://www.malwarebytes.org/products/malwarebytes_free/ and return when clean (SPD-0267). '); //75a
$ax += inmatch($lcuseragent,'dle_spider','Network not allowed. INSTA-BAN (SPD-0268). '); //75c


// Hostname Bombs
// Thanks MickeyRoush for your clean regex signature!

$ax += regexmatch($hoster,"(?:^[:.-]|[:.-]$|[.:][a-z\d-]{64,}[.:]|[^a-z\d:.-]+|^(?:\d+|.{256,})?$)",'Illegal Character, Illegal Configuration, Empty Field, or Too Many Characters in RDNS (HNB-000). ');

//if (inmatch($whyblockout,"(HNB-","Dangerous hostname detected! Neutralized (HNB-FIX). ")){ $hoster = $address ; }


// Normal Hostname Blocks

$ax += inmatch($hoster,'majestic','MJ01 (HN-0001). '); //70e
$ax += inmatch($hoster,'hosteurope','Bothost and/or Server Farm. Not an access provider ISP (HN-0002). '); //68c Fix
$ax += rmatch($hoster,'seomoz.org','Site scrapers (HN-0003). ');
$ax += rmatch($hoster,'rulinki.ru','Bad spider, does not use robots.txt (HN-0004). ');
$ax += rmatch($hoster,'internetserviceteam.com','internetserviceteam, phpbb hackers (HN-0005). ');
$ax += rmatch($hoster,'kimsufi.com','kimsufi, forum spambots (HN-0006). ');
$ax += rmatch($hoster,'pool.ukrtel.net','ukrtel, forum spambots (HN-0007). ');
$ax += rmatch($hoster,'mbox.kz',"mbox, blog 'sploit bothost (HN-0008). ");
$ax += rmatch($hoster,'cjh-law.com','cjh-law, nasty phishers / scammers (HN-0009). ');
$ax += rmatch($hoster,'kiyosho.jp','kiyosho, infected japanese machine (HN-0010). ');
$ax += rmatch($hoster,'adsinmedia.co.in','Bothost and/or Server Farm. Not an access provider ISP (HN-0011). ');
$ax += rmatch($hoster,'holhost.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0012). ');
$ax += rmatch($hoster,'vip-net.pl','Bothost and/or Server Farm. Not an access provider ISP (HN-0013). ');
$ax += rmatch($hoster,'23gb.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0014). ');
$ax += rmatch($hoster,'swifttrim.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0015). ');
$ax += rmatch($hoster,'dns-safe.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0016). ');
$ax += rmatch($hoster,'cadinor.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0017). ');
$ax += rmatch($hoster,'neointeractiva.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0018). ');
$ax += rmatch($hoster,'3fn.net','Bothost and/or Server Farm. Not an access provider ISP (HN-0019). ');
$ax += rmatch($hoster,'.fsfreeware.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0020). ');
$ax += rmatch($hoster,'linkneo.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0021). ');
$ax += rmatch($hoster,'host.caracastelecom.net','Bothost and/or Server Farm. Not an access provider ISP (HN-0022). ');
$ax += rmatch($hoster,'ig.com.br','Bothost and/or Server Farm. Not an access provider ISP (HN-0023). ');
$ax += rmatch($hoster,'clanmoi.de','Bothost and/or Server Farm. Not an access provider ISP (HN-0024). ');
$ax += rmatch($hoster,'piemontetv.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0025). ');
$ax += rmatch($hoster,'authenticnetworks.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0026). ');
$ax += rmatch($hoster,'ogicom.pl','Bothost and/or Server Farm. Not an access provider ISP (HN-0027). ');
$ax += rmatch($hoster,'agava.net','Bothost and/or Server Farm. Not an access provider ISP (HN-0028). ');
$ax += rmatch($hoster,'rivreg.ru','Bothost and/or Server Farm. Not an access provider ISP (HN-0029). ');
$ax += rmatch($hoster,'americanforeclosures.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0030). ');
$ax += rmatch($hoster,'vampire.pl','Bothost and/or Server Farm. Not an access provider ISP (HN-0031). ');
$ax += rmatch($hoster,'midphase.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0032). ');
$ax += rmatch($hoster,'brasiltelecom.net.br','Bothost and/or Server Farm. Not an access provider ISP (credit: eclecticdjs.com) (HN-0033). ');
$ax += rmatch($hoster,'starnet.md','Bothost and/or Server Farm. Not an access provider ISP (credit: eclecticdjs.com) (HN-0034). ');
$ax += inmatch($hoster,'steephost','Bothost and/or Server Farm. Not an access provider ISP (credit: eclecticdjs.com) (HN-0035). '); //Modified 74b
$ax += rmatch($hoster,'followmeoffice.com',"Bothost / Better idea, don't follow me (HN-0036). ");
$ax += rmatch($hoster,'dumpyourbitch.com','Rude script attackers (HN-0037). ');
$ax += rmatch($hoster,'exatt.net',"Bad ISP, allows bots to run loose, hides fact it's in Mumbai, India (HN-0038). ");
$ax += rmatch($hoster,'dotnetdotcom.org','Bad search spider. Ignores robots.txt. Offers an explosive .zip to those who try to use their services (HN-0039). ');
//$ax += rmatch($hoster,'asianet.co.th','Bothost (HN-0040). '); ***PROVISIONAL REMOVAL***
if (!(rmatch($hoster,'.user.veloxzone.com.br',''))){$ax += rmatch($hoster,'veloxzone.com.br','Bothost and/or Server Farm. Not an access provider ISP (HN-0041). ');} //modified 73d to see if it user domain should be bypassed.
$ax += rmatch($hoster,'qvt.net.br','Bothost and/or Server Farm. Not an access provider ISP (HN-0042). ');
$ax += rmatch($hoster,'vtr.net','Bothost and/or Server Farm. Not an access provider ISP (weird!) (HN-0043). ');
$ax += rmatch($hoster,'terra.cl','Bothost and/or Server Farm. Not an access provider ISP (HN-0044). ');
$ax += rmatch($hoster,'iam.net.ma','Bothost and/or Server Farm. Not an access provider ISP (HN-0045). ');
$ax += rmatch($hoster,'35up.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0046). ');
$ax += rmatch($hoster,'isnet.net','South African Bothosts (HN-0047). ');
$ax += rmatch($hoster,'tiscali.it','tiscali, constant source of forum spam attempts (HN-0048). ');
$ax += rmatch($hoster,'dragonara.net','Spamjockey ISP... GO AWAY! (HN-0049). ');
$ax += rmatch($hoster,'accentrainc.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0050). ');
$ax += rmatch($hoster,'colo.iinet.com','Iterasi site scrapers (HN-0051). ');
$ax += rmatch($hoster,'smartservercontrol.com',"smartservercontrol.com - ya ain't controlling my server bub (HN-0052). ");
$ax += rmatch($hoster,'hinet.net','Taiwanese ISP with a history of uncontrolled attacks (HN-0053). ');
$ax += rmatch($hoster,'chello.pl','Problematic ISP/Host, constant source of attacks (HN-0054). ');
$ax += rmatch($hoster,'accelovation.com','Content scraper for paid service (HN-0055). ');
$ax += rmatch($hoster,'setooz.com','Email harvester from India (HN-0056). ');
$ax += rmatch($hoster,'altushost.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0057). ');
$ax += rmatch($hoster,'bestprice.com','Spammers (HN-0058). ');
$ax += rmatch($hoster,'doctore.sk','Skiddy (HN-0059). ');
$ax += rmatch($hoster,'page-store.com','SEOMOZ keyword scraper (HN-0061). ');
$ax += rmatch($hoster,'mantraonline.com','Indian spammers / malware spreaders (HN-0062). ');
$ax += rmatch($hoster,'jkserv.net','Game server network that keeps probing the author (HN-0063). ');
$ax += rmatch($hoster,'webhostserver.biz','Server network that keeps probing the author (HN-0064). ');
$ax += rmatch($hoster,'ctinets.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0065). ');
$ax += rmatch($hoster,'server4you.de','Bothost and/or Server Farm. Not an access provider ISP (HN-0066). ');
$ax += rmatch($hoster,'propagation.net','No propogation allowed (spammers) (HN-0067). ');
$ax += rmatch($hoster,'hostacy.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0068). ');
$ax += rmatch($hoster,'onlinehome-server.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0069). ');
$ax += rmatch($hoster,'onlinehome-server.net','Bothost and/or Server Farm. Not an access provider ISP (HN-0070). ');
$ax += rmatch($hoster,'onlinehome-server.info','Bothost and/or Server Farm. Not an access provider ISP (HN-0071). ');
$ax += rmatch($hoster,'bezeqint.net','ISP with a bad reputation, and heavy spam record (HN-0072). ');
$ax += rmatch($hoster,'prking.com.au','Spammer (HN-0073). ');
$ax += rmatch($hoster,'.server.de','Bothost and/or Server Farm. Not an access provider ISP (HN-0074). '); //69b adjusted
$ax += rmatch($hoster,'nettopia.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0075). ');
$ax += rmatch($hoster,'webfusion.co.uk','Bothost and/or Server Farm. Not an access provider ISP (HN-0076). ');
$ax += rmatch($hoster,'phatservers.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0077). ');
$ax += rmatch($hoster,'insite.com.br','Bothost and/or Server Farm. Not an access provider ISP (HN-0078). ');
$ax += rmatch($hoster,'justhost.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0079). ');
$ax += rmatch($hoster,'is74.ru','Proxy provider for hackers (HN-0080). ');
$ax += inmatch($hoster,'45ru.net.au','Abuse RFC ignorant network, caught abusing (HN-0081). ');
//$ax += rmatch($hoster,'alicedsl.de','Abuse ignorant ISP listed on abuse.rfc-ignorant.org (HN-0082). '); //71a Provisional Removal
$ax += rmatch($hoster,'reliablehosting.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0083). '); //69c
$ax += rmatch($hoster,'quadranet.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0084). '); //69c
$ax += rmatch($hoster,'server.lu','Bothost and/or Server Farm. Not an access provider ISP (HN-0085). ');  //69c
$ax += rmatch($hoster,'ertelecom.ru','Dangerous network (HN-0086). '); //69c description changed //75a
$ax += rmatch($hoster,'.airtelbroadband.in','Please use a different ISP, as Airtel India hides spammers via fast-flux DNS (HN-0087). '); //69c
$ax += rmatch($hoster,'.pldt.net','Malicious ISP, fostering spambots (HN-0088). '); //69c
$ax += rmatch($hoster,'.giga-dns.com','Scraper host, Not an access provider ISP (HN-0089). '); //70a
$ax += rmatch($hoster,'.rdsnet.ro','RDSNET is a constant source of spam and attacks (HN-0090). '); //70c
$ax += rmatch($hoster,'.myforexvps.com','Spamhost detection (HN-0091). '); //70c
$ax += rmatch($hoster,'.oroxy.com','oroxy.com is an annonmous proxy (HN-0092). '); //70c
$ax += rmatch($hoster,'.duo.carnet.hr','Spam host (HN-0093). '); //70c
$ax += rmatch($hoster,'.telecom.net.ar','Spam host (HN-0094). '); //70c
$ax += rmatch($hoster,'.pool-xxx.hcm.fpt','Spam host (HN-0095). '); //70c
$ax += rmatch($hoster,'.pointandchange.com','Scraper host (HN-0096). '); //70d
$ax += inmatch($hoster,'swebot','Scraper host (HN-0097). '); //71c
$ax += inmatch($hoster,'exabot','Scraper host (HN-0098). '); //71d
$ax += inmatch($hoster,'youdaobot','Scraper host (HN-0099). '); //71d
$ax += inmatch($hoster,'ceptro','Scraper host (HN-0100). '); //71d
$ax += inmatch($hoster,'boardreader','Scraper host (HN-0101). '); //71e
$ax += inmatch($hoster,'2dayhost.com','Scraper host (HN-0102). '); //71f
$ax += rmatch($hoster,'retail.telecomitalia.it','Spammer tolerant host network (HN-0103). ');
$ax += rmatch($hoster,'fidelity.com','fidelity.c0m, Abusive forum scraping network (HN-0104). '); //69d
$ax += rmatch($hoster,'technicolor.com','technicolor.c0m, Abusive forum scraping network (HN-0105). '); //69d
$ax += inmatch($hoster,'rumer','Caught you! INSTA-BAN (HN-0106). '); //70c
$ax += inmatch($hoster,'pymep','Caught you! INSTA-BAN (HN-0107). '); //70c
//$ax += rmatch($hoster,'tpnet.pl','tpnet.pl, this network turned clean, turned dirty again (HN-0108). '); //70c removed again 73d. Let's see if they play nice now?
$ax += rmatch($hoster,'hostnoc.net','hostnoc.net, Abusive network, SQL hacks (HN-0109). '); //70d
$ax += inmatch($hoster,'yandex','Yandex is banned. INSTA-BAN (HN-0110). '); //71b Yandex has many tlds.
$ax += rmatch($hoster,'mail.ru','Mail.ru is banned. INSTA-BAN (HN-0111). '); //71c
$ax += inmatch($hoster,'dedibox','Dubious French hoster (HN-0112). '); //71d (moved & strengthened)
$ax += inmatch($hoster,'laycat','Dubious French search engine (HN-0113). '); //71d (moved & strengthened)
$ax += inmatch($hoster,'kyklo','Dubious French search engine (HN-0114). '); //71d (moved & strengthened)
$ax += inmatch($hoster,'aceleo','Dubious French search engine (HN-0115). '); //71d (moved & strengthened)
$ax += rmatch($hoster,'xcelmg.com','Host caught trying to hack (HN-0116). '); //71g
$ax += rmatch($hoster,'dimenoc.com','Host caught trying to hack (HN-0117). '); //71g
$ax += inmatch($hoster,'slicehost','Slicehost/Splicehost AS12200 (HN-0118). '); //71g
$ax += rmatch($hoster,'startdedicated.com','Scraper host (HN-0119). '); //71g
$ax += inmatch($hoster,'triolan','triolan.net (HN-0120). '); //71h
$ax += rmatch($hoster,'vpsnow.ru','vpsnow.ru hostile probes (HN-0121). '); //71
$ax += rmatch($hoster,'ideastack.com','ideastack.com, hostile host (HN-0122). '); //72a
$ax += rmatch($hoster,'esonicspider.com','esonicspider.com, hostile host (HN-0123). '); //72a
$ax += rmatch($hoster,'megacom.biz','megacom.biz, hostile host (HN-0124). '); //72a
$ax += rmatch($hoster,'telsp.net.br','telsp.net.br, Bothost and/or Server Farm (HN-0125). '); //72b moved from RBN
$ax += inmatch($hoster,'kyivstar','kyivstar, Supposedly a cell provider, smells like a bothost and/or Server Farm (HN-0126). '); //72b
$ax += inmatch($hoster,'hotspotsheild','esonicspider.com, hostile host (HN-0127). '); //72a
$ax += inmatch($hoster,'anchorfree','esonicspider.com, hostile host (HN-0128). '); //72a
$ax += inmatch($hoster,'dedipower','Depricated tweetmemebot (FAKE) host (HN-0128). '); //73b
//$ax += inmatch($hoster,'.seo','SEO hostname detection (HN-0129.0). '); //73b
//$ax += inmatch($hoster,'seo.','SEO hostname detection (HN-0129.1). '); //73b
$ax += inmatch($hoster,'seeweb.it','Hostile LFI upload attacks from multiple sequential hosts (HN-0130). '); //73b
$ax += inmatch($hoster,'buyurl.net','Strange crawler, probably SEO, Not only RFC-ignorant, but RFC-rejecting (HN-0131). '); //73c
$ax += inmatch($hoster,'solomono.ru','solomono.ru, SEO bothost. Scrapes sites, then checks robots.txt for more URLS, and hits honeypots. (HN-0132). '); //73d
$ax += inmatch($hoster,'your-server.de','your-server.de, Known host of attack scripts. Not an access provider (HN-0133). '); //73d
$ax += inmatch($hoster,'lightspeedsystems.com','LightSpeed systems censor bot, scrapes sites proactively instead of on use (HN-0134). '); //73d
$ax += rmatch($hoster,'.host.ru','host.ru, low level access provider, mostly hosting & colo. Constant source of attacks (HN-0135). '); //73d
$ax += inmatch($hoster,'brandaffinity','Possible brandname/client name SLAPP trolling scanner. Does not query, or obey robots.txt (HN-0136). '); //74a
$ax += inmatch($hoster,'liwio.','HTTP_REFERER spamvertising fake medicines (HN-0137). '); //74a
$ax += inmatch($hoster,'aramenet.com','Blind Probes (HN-0138). '); //74a
$ax += inmatch($hoster,'phishmongers.com','Blind Probes (HN-0139). '); //74a
$ax += inmatch($hoster,'2kom.ru','Nasty Scraper (HN-0140). '); //74a
$ax += inmatch($hoster,'awcheck','AwcheckBot, Ignores robots.txt (WOT), and is used for SEO keyword analyss (HN-0141). '); //74a
$ax += inmatch($hoster,'captch','Captcha cracker detection (HN-0142). '); //74b
$ax += inmatch($hoster,'dbcapi.me','Captcha cracker detection (HN-0143). '); //74b
$ax += inmatch($hoster,'.oodle.com','Keyword scraping bot that does not pull robots.txt (HN-0144). '); //74b
$ax += inmatch($hoster,'smileweb.com.ua','Referer spambots (HN-0145). '); //74c
$ax += inmatch($hoster,'psychz','Bothost and/or Server Farm. Not an access provider ISP (HN-0146). '); //74c
$ax += inmatch($hoster,'luxuryhandbag','Bothost and/or Server Farm. Not an access provider ISP (HN-0147). '); //74c
$ax += inmatch($hoster,'unassigned','Questionable hosthame, access denied (HN-0148). '); //74c
$ax += inmatch($hoster,'no-data','Questionable hosthame, access denied (HN-0149). '); //74c
$ax += inmatch($hoster,'hostenko.com','Host with an attack record, using anonymous whois (HN-0150). '); //74c
$ax += inmatch($hoster,'moneymattersnow','Bothost and/or Server Farm. Not an access provider ISP (HN-0151). '); //74c
$ax += inmatch($hoster,'seznam.cz','Bothost and/or Server Farm. Not an access provider ISP (HN-0152). '); //74c
$ax += inmatch($hoster,'fulltextrobot','Cloaked Dubious spider UA (HN-0153). '); //74c
$ax += inmatch($hoster,'meanpath','Use of meanpathbot not authorized by website admin (HN-0154). '); //74c
$ax += inmatch($hoster,'no-dns-yet','Your Internet Service Provider has a severe problem in rDNS resolution. We are sorry, but until this is repaired, we cannot connect you to the party you are trying to reach. (HN-0155.0). '); //74c
$ax += inmatch($hoster,'no-reverse-dns-yet','Your Internet Service Provider has a severe problem in rDNS resolution. We are sorry, but until this is repaired, we cannot connect you to the party you are trying to reach. (HN-0155.1). '); //74d
$ax += lmatch($hoster,'hosted-by','Questionable hosthame, access denied (HN-0156). '); //74c
$ax += inmatch($hoster,'sistrix','Scraper and/or Harvester (HN-0157). '); //74c
$ax += inmatch($hoster,'leaseweb','Bothost and/or Server Farm. Not an access provider ISP (HN-0158). '); //74c
$ax += lmatch($hoster,'hosted-in','Questionable hosthame, access denied (HN-0159). '); //74c
$ax += inmatch($hoster,'servepath.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0160). '); //74c
$ax += inmatch($hoster,'buysellsales','Bothost and/or Server Farm. Not an access provider ISP (HN-0161). '); //74c
$ax += inmatch($hoster,'voxility.net','Bothost and/or Server Farm. Not an access provider ISP (HN-0162). '); //74d
$ax += inmatch($hoster,'vympelstroy.ru','Bothost and/or Server Farm. Not an access provider ISP (HN-0163). '); //74d
$ax += inmatch($hoster,'no-rdns-record','Questionable hosthame, access denied (HN-0163). '); //74d
$ax += inmatch($hoster,'core.youtu.me','Questionable hosthame, access denied (HN-0164). '); //74d
$ax += inmatch($hoster,'anahaqq','Questionable hosthame, access denied (HN-0165). '); //74d
$ax += inmatch($hoster,'spletnahisa','Questionable hosthame, access denied (HN-0166). '); //74d
$ax += inmatch($hoster,'qeas','Questionable hosthame, access denied (HN-0167). '); //74d
$ax += inmatch($hoster,'work.from','Questionable hosthame, access denied (HN-0168). '); //74d
$ax += lmatch($hoster,'test.','Questionable hosthame, access denied (HN-0169). '); //74d
$ax += inmatch($hoster,'therewill.be','Questionable hosthame, access denied (HN-0170). '); //74d
$ax += inmatch($hoster,'bibbly.com','Use of Bibbly not authorized by website admin (HN-0171). '); //74d
$ax += inmatch($hoster,'cyber-uslugi','cyber-uslugi.pl and cyber-host.pl, unauthorised SEO service (HN-0172). '); //74d
$ax += inmatch($hoster,'cheapseovps','cheapseovps.com, unauthorised SEO service (HN-0173). '); //74d
$ax += inmatch($hoster,'dreamhost','Bothost and/or Server Farm. Not an access provider ISP (HN-0174). '); //74d
$ax += inmatch($hoster,'scopehosts','Bothost and/or Server Farm. Not an access provider ISP (HN-0175). '); //74d
$ax += inmatch($hoster,'cyber-host.pl','Bothost and/or Server Farm. Not an access provider ISP (HN-0176). '); //74d
$ax += inmatch($hoster,'yhost.name','Bothost and/or Server Farm. Not an access provider ISP (HN-0177). '); //74d
$ax += inmatch($hoster,'bergdorf-group','Bothost and/or Server Farm. Not an access provider ISP (HN-0178). '); //74d
$ax += inmatch($hoster,'slaskdatacenter.pl','Bothost and/or Server Farm. Not an access provider ISP (HN-0179). '); //74d
$ax += inmatch($hoster,'colocrossing.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0180). '); //74d
$ax += inmatch($hoster,'instantdedicated.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0181). '); //74d
$ax += inmatch($hoster,'serverbuddies.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0182). '); //74d
$ax += inmatch($hoster,'reliablesite.net','Bothost and/or Server Farm. Not an access provider ISP (HN-0183). '); //74d
$ax += inmatch($hoster,'xeex','Dangerous host/network (HN-0184). '); //74d
$ax += inmatch($hoster,'prohibitivestuff','Dangerous host/network (HN-0185). '); //74d
$ax += inmatch($hoster,'drugstore','Bothost and/or Server Farm. Not an access provider ISP (HN-0186). '); //74d
$ax += inmatch($hoster,'productsnetworksx','Bothost and/or Server Farm. Not an access provider ISP (HN-0187). '); //74d
$ax += inmatch($hoster,'jackwellsmusic','Compromised server, source of spam (HN-0188). '); //74d
$ax += inmatch($hoster,'tkvprok.ru','Bothost and/or Server Farm. Not an access provider ISP (HN-0189). '); //74d
$ax += inmatch($hoster,'khavarzamin.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0190). '); //74d
$ax += inmatch($hoster,'mobilemarketingaid.info','Bothost and/or Server Farm. Not an access provider ISP (HN-0191). '); //74d
$ax += inmatch($hoster,'viral-customers.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0192). '); //74d
$ax += inmatch($hoster,'moneytech.mg','Bothost and/or Server Farm. Not an access provider ISP (HN-0193). '); //74d
$ax += inmatch($hoster,'inkjetrefillink.com','Compromised server, source of spam (HN-0194). '); //74d
$ax += inmatch($hoster,'.as13448.','Websense Network. Odd behavior, possible hostile intent (HN-0195.0). '); //74d
$ax += inmatch($hoster,'.websense.','Websense Network. Odd behavior, possible hostile intent (HN-0195.1). '); //74d
$ax += inmatch($hoster,'squider','Squider Network. Known spammers hitting spamtraps (WOT) (HN-0196). '); //74d
$ax += inmatch($hoster,'fibersunucu.com.tr','Your ISP is banned. Known collaboration with xrumer (HN-0197). '); //74d
$ax += inmatch($hoster,'zvelo.com','zvelo.com not authorized by site admin (HN-0198). '); //74d
$ax += inmatch($hoster,'westdc.net','Westhost not authorized by site admin (HN-0199). '); //74d
$ax += inmatch($hoster,'pulsepoint.com','Pulsepoint not authorized by site admin (HN-0200). '); //74d
$ax += inmatch($hoster,'automobilelending4u.info','Bothost and/or Server Farm. Not an access provider ISP (HN-0201). '); //74d
$ax += inmatch($hoster,'loan-modification-fraud4u.info','Bothost and/or Server Farm. Not an access provider ISP (HN-0202). '); //74d
$ax += inmatch($hoster,'artisticgoals.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0203). '); //74d
$ax += inmatch($hoster,'fast-cash4u.info','Bothost and/or Server Farm. Not an access provider ISP (HN-0204). '); //74d
$ax += inmatch($hoster,'profninja.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0205). '); //74d
$ax += inmatch($hoster,'replyingst.net','Bothost and/or Server Farm. Not an access provider ISP (HN-0206). '); //74d
$ax += rmatch($hoster,'anonine.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0207). '); //74d
$ax += inmatch($hoster,'newslettersrus.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0208). '); //74d
$ax += inmatch($hoster,'cars-loans4u.info','Bothost and/or Server Farm. Not an access provider ISP (HN-0209). '); //74d
$ax += inmatch($hoster,'missiondish.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0210). '); //74d
$ax += rmatch($hoster,'groupcross.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0211). '); //74d
$ax += lmatch($hoster,'damage.','Bothost and/or Server Farm. Not an access provider ISP (HN-0212). '); //74d
$ax += lmatch($hoster,'moon.','Bothost and/or Server Farm. Not an access provider ISP (HN-0213). '); //74d
$ax += rmatch($hoster,'4u.info','Bothost and/or Server Farm. Not an access provider ISP (HN-0214). '); //74d
$ax += inmatch($hoster,'securityspace.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0215). '); //74d
$ax += rmatch($hoster,'xlhost.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0216). '); //74d
$ax += rmatch($hoster,'netcomber.com','Reputaion/SEO manager service scrapes sites (HN-0217). '); //74d
$ax += inmatch($hoster,'vpngate','VPNGate, Free VPN network that is anonymous, and untracable for bad behavior (HN-0218). '); //75a
$ax += inmatch($hoster,'thefreevpn','The free VPN, Free VPN network that is anonymous, and untracable for bad behavior (HN-0219). '); //75a
$ax += inmatch($hoster,'public-net','Network that is anonymous, and untracable for bad behavior (HN-0220). '); //75a
$ax += rmatch($hoster,'dedicatedpanel.com','Bothost and/or Server Farm. Not an access provider ISP (HN-0221). '); //75a
$ax += rmatch($hoster,'mojsite.com','quvHa\'ghach qem SoH veQ (HN-0222). '); //75a
$ax += rmatch($hoster,'barefruit.com','Keyword Scraper (HN-0223). '); //75a
$ax += rmatch($hoster,'balticservers.com','Attack host (HN-0224). '); //75b
$ax += inmatch($hoster,'tag-trek','Tag-Trek not authorized by site admin (HN-0225). '); //75d
$ax += rmatch($hoster,'vpn999.com','Possibly dangerous host (HN-0226). '); //76a


// Cloud Computing Providers

$ax += rmatch($hoster,'softlayer.com','Cloud Services. Not an access provider ISP (CLD-0001). ');
if ((inmatch($whyblockout,'(CLD-0001)','')) && ($ax > 0)){
	$zbamz = 0;
	$zbamz += lmatch($lcuseragent,'showyoubot','ShowyouBot bypass. '); //72b
	$zbamz += inmatch($lcuseragent,'disqus','Disqus bypass. '); //74a
	$zbamz += inmatch($useragent,'Feedspot http://www.feedspot.com','Feedspot bypass. '); //74a
	$zbamz += inmatch($useragent,'Superfeedr bot/2.0','Superfeedr bypass. '); //74a
	$zbamz += inmatch($useragent,'Feedbot','Feedbot bypass. '); //74a	
	if ($zbamz > 0){$ax -= 1;}
}

$ax += rmatch($hoster,'newservers.com','Cloud Services. Not an access provider ISP (CLD-0002). ');
$ax += rmatch($hoster,'savvis.com','Cloud Services. Not an access provider ISP (CLD-0003). ');
$ax += rmatch($hoster,'terremark.com','Cloud Services. Not an access provider ISP (CLD-0004). ');
$ax += rmatch($hoster,'gogrid.com','Cloud Services. Not an access provider ISP (CLD-0005). ');
$ax += rmatch($hoster,'joyent.com','Cloud Services. Not an access provider ISP (CLD-0006). ');
$ax += rmatch($hoster,'salesforce.com','Cloud Services. Not an access provider ISP (CLD-0007). ');
$ax += rmatch($hoster,'rackspace.com','Cloud Services. Not an access provider ISP (CLD-0007). ');
$ax += rmatch($hoster,'rackspacecloud.com','Cloud Services. Not an access provider ISP (CLD-0008). ');
$ax += rmatch($hoster,'engineyard.com','Cloud Services. Not an access provider ISP (CLD-0009). ');
$ax += rmatch($hoster,'heroku.com','Cloud Services. Not an access provider ISP (CLD-0010). ');
$ax += rmatch($hoster,'10gen.com','Cloud Services. Not an access provider ISP (CLD-0011). ');
$ax += rmatch($hoster,'3leafsystems.com','Cloud Services. Not an access provider ISP (CLD-0012). ');
$ax += rmatch($hoster,'3tera.com','Cloud Services. Not an access provider ISP (CLD-0013). ');
$ax += rmatch($hoster,'appirio.com','Cloud Services. Not an access provider ISP (CLD-0014). ');
$ax += rmatch($hoster,'appistry.com','Cloud Services. Not an access provider ISP (CLD-0015). ');
$ax += rmatch($hoster,'appnexus.com','Cloud Services. Not an access provider ISP (CLD-0016). ');
$ax += rmatch($hoster,'aptana.com','Cloud Services. Not an access provider ISP (CLD-0017). ');
$ax += rmatch($hoster,'arjuna.com','Cloud Services. Not an access provider ISP (CLD-0018). ');
$ax += rmatch($hoster,'asyanka.com','Cloud Services. Not an access provider ISP (CLD-0019). ');
$ax += rmatch($hoster,'bluewolf.com','Cloud Services. Not an access provider ISP (CLD-0020). ');
$ax += rmatch($hoster,'boomi.com','Cloud Services. Not an access provider ISP (CLD-0021). ');
$ax += rmatch($hoster,'.box.net','Cloud Services. Not an access provider ISP (CLD-0022). ');
$ax += rmatch($hoster,'camsolutionsinc.com','Cloud Services. Not an access provider ISP (CLD-0023). ');
$ax += rmatch($hoster,'cassatt.com','Cloud Services. Not an access provider ISP (CLD-0024). ');
$ax += rmatch($hoster,'cloud9analytics.com','Cloud Services. Not an access provider ISP (CLD-0025). ');
$ax += rmatch($hoster,'cloudera.com','Cloud Services. Not an access provider ISP (CLD-0026). ');
$ax += rmatch($hoster,'cloudcomputingchina.com','Cloud Services. Not an access provider ISP (CLD-0027). ');
$ax += rmatch($hoster,'cloudscale.com','Cloud Services. Not an access provider ISP (CLD-0028). ');
$ax += rmatch($hoster,'cloudstatus.com','Cloud Services. Not an access provider ISP (CLD-0029). ');
$ax += rmatch($hoster,'cloudworks.com','Cloud Services. Not an access provider ISP (CLD-0030). ');
$ax += rmatch($hoster,'cohesiveft.com','Cloud Services. Not an access provider ISP (CLD-0031). ');
$ax += rmatch($hoster,'theprocessfactory.com','Cloud Services. Not an access provider ISP (CLD-0032). ');
$ax += rmatch($hoster,'dataline.com','Cloud Services. Not an access provider ISP (CLD-0033). ');
$ax += rmatch($hoster,'datasisar.com','Cloud Services. Not an access provider ISP (CLD-0034). ');
$ax += rmatch($hoster,'elastichosts.com','Cloud Services. Not an access provider ISP (CLD-0035). ');
$ax += rmatch($hoster,'elastra.com','Cloud Services. Not an access provider ISP (CLD-0036). ');
$ax += rmatch($hoster,'.emc.com','Cloud Services. Not an access provider ISP (CLD-0037). ');
$ax += rmatch($hoster,'enkiconsulting.net','Cloud Services. Not an access provider ISP (CLD-0038). ');
$ax += rmatch($hoster,'enomalism.com','Cloud Services. Not an access provider ISP (CLD-0039). ');
$ax += rmatch($hoster,'eucalyptus.cs.uscb.edu','Cloud Services. Not an access provider ISP (CLD-0040). ');
$ax += rmatch($hoster,'flexiscale.com','Cloud Services. Not an access provider ISP (CLD-0041). ');
$ax += rmatch($hoster,'.force.com','Cloud Services. Not an access provider ISP (CLD-0042). ');
//$ax += rmatch($hoster,'fortressitx.com','Cloud Services. Not an access provider ISP (CLD-0043). '); //Removed 73d
$ax += rmatch($hoster,'g.ho.st','Cloud Services. Not an access provider ISP (CLD-0044). ');
$ax += rmatch($hoster,'gigaspaces.com','Cloud Services. Not an access provider ISP (CLD-0045). ');
$ax += rmatch($hoster,'thinkgos.com','Cloud Services. Not an access provider ISP (CLD-0046). ');
$ax += rmatch($hoster,'.hosting.com','Cloud Services. Not an access provider ISP (CLD-0047). ');
$ax += rmatch($hoster,'hyperic.com','Cloud Services. Not an access provider ISP (CLD-0048). ');
$ax += rmatch($hoster,'icloud.com','Cloud Services. Not an access provider ISP (CLD-0049). ');
$ax += rmatch($hoster,'jumpbox.com','Cloud Services. Not an access provider ISP (CLD-0050). ');
$ax += rmatch($hoster,'kaavo.com','Cloud Services. Not an access provider ISP (CLD-0051). ');
$ax += rmatch($hoster,'keynote.com','Cloud Services. Not an access provider ISP (CLD-0052). ');
$ax += rmatch($hoster,'layeredtech.com','Cloud Services. Not an access provider ISP (CLD-0053). ');
$ax += rmatch($hoster,'ltdomains.com','Cloud Services. Not an access provider ISP (CLD-0054). '); //70b
$ax += rmatch($hoster,'mor.ph','Cloud Services. Not an access provider ISP (CLD-0055). ');
$ax += rmatch($hoster,'morphexchange.com','Cloud Services. Not an access provider ISP (CLD-0056). ');
$ax += rmatch($hoster,'nasstar.com','Cloud Services. Not an access provider ISP (CLD-0057). ');
$ax += rmatch($hoster,'netsuite.com','Cloud Services. Not an access provider ISP (CLD-0058). ');
$ax += rmatch($hoster,'nirvanix.com','Cloud Services. Not an access provider ISP (CLD-0059). ');
$ax += rmatch($hoster,'nscaled.com','Cloud Services. Not an access provider ISP (CLD-0060). ');
$ax += rmatch($hoster,'opennebula.org','Cloud Services. Not an access provider ISP (CLD-0061). ');
$ax += rmatch($hoster,'qrimp.com','Cloud Services. Not an access provider ISP (CLD-0062). ');
$ax += rmatch($hoster,'rightscale.com','Cloud Services. Not an access provider ISP (CLD-0064). ');
$ax += rmatch($hoster,'stax.com','Cloud Services. Not an access provider ISP (CLD-0065). ');
$ax += rmatch($hoster,'thoughtexpress.com','Cloud Services. Not an access provider ISP (CLD-0066). ');
$ax += rmatch($hoster,'trustsaas.com','Cloud Services. Not an access provider ISP (CLD-0067). ');
$ax += rmatch($hoster,'utilitystatus.com','Cloud Services. Not an access provider ISP (CLD-0068). ');
$ax += rmatch($hoster,'moderro.com','Cloud Services. Not an access provider ISP (CLD-0069). ');
$ax += rmatch($hoster,'.cloud.com','Cloud Services. Not an access provider ISP (CLD-0070). ');
$ax += rmatch($hoster,'hexagrid.com','Cloud Services. Not an access provider ISP (CLD-0071). ');
$ax += rmatch($hoster,'onelogin.com','Cloud Services. Not an access provider ISP (CLD-0072). ');
$ax += rmatch($hoster,'qlayer.com','Cloud Services. Not an access provider ISP (CLD-0073). ');
$ax += rmatch($hoster,'skytap.com','Cloud Services. Not an access provider ISP (CLD-0074). ');
$ax += rmatch($hoster,'webscalesolutions.com','Cloud Services. Not an access provider ISP (CLD-0075). ');
$ax += rmatch($hoster,'agathon.com','Cloud Services. Not an access provider ISP (CLD-0076). ');
$ax += rmatch($hoster,'.gridlayer.com','Cloud Services. Not an access provider ISP (CLD-0077). ');
$ax += rmatch($hoster,'.thegridlayer.com','Cloud Services. Not an access provider ISP (CLD-0078). ');
$ax += rmatch($hoster,'reliacloud.com','Cloud Services. Not an access provider ISP (CLD-0079). ');
$ax += rmatch($hoster,'mosso.com','Cloud Services. Not an access provider ISP (CLD-0080). ');
$ax += rmatch($hoster,'pluraprocessing.com','Cloud Services. Not an access provider ISP (CLD-0081). ');
$ax += rmatch($hoster,'azati.com','Cloud Services. Not an access provider ISP (CLD-0082). ');
$ax += rmatch($hoster,'birtondemand.com','Cloud Services. Not an access provider ISP (CLD-0083). ');
$ax += rmatch($hoster,'bungeeconnect.com','Cloud Services. Not an access provider ISP (CLD-0084). ');
$ax += rmatch($hoster,'cloudcontrol.com','Cloud Services. Not an access provider ISP (CLD-0085). ');
$ax += rmatch($hoster,'imodrive.com','Cloud Services. Not an access provider ISP (CLD-0086). ');
$ax += rmatch($hoster,'novatium.com','Cloud Services. Not an access provider ISP (CLD-0087). ');
$ax += rmatch($hoster,'quantix-uk.com','Cloud Services. Not an access provider ISP (CLD-0088). ');
$ax += rmatch($hoster,'12designer.com','Cloud Services. Not an access provider ISP (CLD-0089). ');
$ax += rmatch($hoster,'aconex.com','Cloud Services. Not an access provider ISP (CLD-0090). ');
$ax += rmatch($hoster,'advologix.com','Cloud Services. Not an access provider ISP (CLD-0091). ');
$ax += rmatch($hoster,'altornetworks.com','Cloud Services. Not an access provider ISP (CLD-0092). ');
$ax += rmatch($hoster,'mturk.com','Cloud Services. Not an access provider ISP (CLD-0093). ');
$ax += rmatch($hoster,'amitive.com','Cloud Services. Not an access provider ISP (CLD-0094). ');
$ax += rmatch($hoster,'andersdenken.at','Cloud Services. Not an access provider ISP (CLD-0095). ');
$ax += rmatch($hoster,'.appian.com','Cloud Services. Not an access provider ISP (CLD-0096). ');
$ax += rmatch($hoster,'appjet.com','Cloud Services. Not an access provider ISP (CLD-0097). ');
$ax += rmatch($hoster,'apprenda.com','Cloud Services. Not an access provider ISP (CLD-0098). ');
$ax += rmatch($hoster,'appzero.com','Cloud Services. Not an access provider ISP (CLD-0099). ');
$ax += rmatch($hoster,'ariasystems.com','Cloud Services. Not an access provider ISP (CLD-0100). ');
$ax += rmatch($hoster,'artofdefence.com','Cloud Services. Not an access provider ISP (CLD-0101). ');
$ax += rmatch($hoster,'asterdata.com','Cloud Services. Not an access provider ISP (CLD-0102). ');
$ax += rmatch($hoster,'beam4d.com','Cloud Services. Not an access provider ISP (CLD-0103). ');
$ax += rmatch($hoster,'beowulf.org','Cloud Services. Not an access provider ISP (CLD-0104). ');
$ax += rmatch($hoster,'bhivesoft.com','Cloud Services. Not an access provider ISP (CLD-0105). ');
$ax += rmatch($hoster,'blinklogic.com','Cloud Services. Not an access provider ISP (CLD-0106). ');
$ax += rmatch($hoster,'bluelock.com','Cloud Services. Not an access provider ISP (CLD-0107). ');
$ax += rmatch($hoster,'bucketexplorer.com','Cloud Services. Not an access provider ISP (CLD-0108). ');
$ax += rmatch($hoster,'caspio.com','Cloud Services. Not an access provider ISP (CLD-0109). ');
$ax += rmatch($hoster,'castiron.com','Cloud Services. Not an access provider ISP (CLD-0110). ');
$ax += rmatch($hoster,'clarioanalytics.com','Cloud Services. Not an access provider ISP (CLD-0111). ');
$ax += rmatch($hoster,'clickability.com','Cloud Services. Not an access provider ISP (CLD-0112). ');
$ax += rmatch($hoster,'cloud42.com','Cloud Services. Not an access provider ISP (CLD-0113). ');
$ax += rmatch($hoster,'cloudfoundry.com','Cloud Services. Not an access provider ISP (CLD-0114). ');
$ax += rmatch($hoster,'cloudkick.com','Cloud Services. Not an access provider ISP (CLD-0115). ');
$ax += rmatch($hoster,'cloudswitch.com','Cloud Services. Not an access provider ISP (CLD-0116). ');
$ax += rmatch($hoster,'clusterseven.com','Cloud Services. Not an access provider ISP (CLD-0117). ');
$ax += rmatch($hoster,'coghead.com','Cloud Services. Not an access provider ISP (CLD-0118). ');
$ax += rmatch($hoster,'coldlightsolutions.com','Cloud Services. Not an access provider ISP (CLD-0119). ');
$ax += rmatch($hoster,'collab.net','Cloud Services. Not an access provider ISP (CLD-0120). ');
$ax += rmatch($hoster,'concur.com','Cloud Services. Not an access provider ISP (CLD-0121). ');
$ax += rmatch($hoster,'.ctera.com','Cloud Services. Not an access provider ISP (CLD-0122). ');
$ax += rmatch($hoster,'datasynaps.com','Cloud Services. Not an access provider ISP (CLD-0123). ');
$ax += rmatch($hoster,'directlaw.com','Cloud Services. Not an access provider ISP (CLD-0124). ');
$ax += rmatch($hoster,'doclanding.com','Cloud Services. Not an access provider ISP (CLD-0125). ');
$ax += rmatch($hoster,'dropbox.com','Cloud Services. Not an access provider ISP (CLD-0126). ');
$ax += rmatch($hoster,'dynamsoft.com','Cloud Services. Not an access provider ISP (CLD-0127). ');
$ax += rmatch($hoster,'.dyn.com','Cloud Services. Not an access provider ISP (CLD-0128). ');
$ax += rmatch($hoster,'enstratus.com','Cloud Services. Not an access provider ISP (CLD-0129). ');
$ax += rmatch($hoster,'etelos.com','Cloud Services. Not an access provider ISP (CLD-0130). ');
$ax += rmatch($hoster,'eucalyptus.com','Cloud Services. Not an access provider ISP (CLD-0131). ');
$ax += rmatch($hoster,'evapt.com','Cloud Services. Not an access provider ISP (CLD-0132). ');
$ax += rmatch($hoster,'fathomdb.com','Cloud Services. Not an access provider ISP (CLD-0133). ');
$ax += rmatch($hoster,'gemstone.com','Cloud Services. Not an access provider ISP (CLD-0134). ');
$ax += rmatch($hoster,'.gnip.com','Cloud Services. Not an access provider ISP (CLD-0135). ');
$ax += rmatch($hoster,'hubspan.com','Cloud Services. Not an access provider ISP (CLD-0136). ');
$ax += rmatch($hoster,'.icims.com','Cloud Services. Not an access provider ISP (CLD-0137). ');
$ax += rmatch($hoster,'iboss.org','Cloud Services. Not an access provider ISP (CLD-0138). ');
$ax += rmatch($hoster,'infobright.com','Cloud Services. Not an access provider ISP (CLD-0139). ');
$ax += rmatch($hoster,'informatica.com','Cloud Services. Not an access provider ISP (CLD-0140). ');
$ax += rmatch($hoster,'itricityhosting.com','Cloud Services. Not an access provider ISP (CLD-0141). ');
$ax += rmatch($hoster,'junglebox.com','Cloud Services. Not an access provider ISP (CLD-0142). ');
$ax += rmatch($hoster,'k2analytics.com','Cloud Services. Not an access provider ISP (CLD-0143). ');
$ax += rmatch($hoster,'knowledgetree.com','Cloud Services. Not an access provider ISP (CLD-0144). ');
$ax += rmatch($hoster,'liveops.com','Cloud Services. Not an access provider ISP (CLD-0145). ');
$ax += rmatch($hoster,'loadstorm.com','Cloud Services. Not an access provider ISP (CLD-0146). ');
$ax += rmatch($hoster,'logixml.com','Cloud Services. Not an access provider ISP (CLD-0147). ');
$ax += rmatch($hoster,'longjump.com','Cloud Services. Not an access provider ISP (CLD-0148). ');
$ax += rmatch($hoster,'memcached.org','Cloud Services. Not an access provider ISP (CLD-0149). ');
$ax += rmatch($hoster,'mozy.com','Cloud Services. Not an access provider ISP (CLD-0150). ');
$ax += rmatch($hoster,'mulesoft.com','Cloud Services. Not an access provider ISP (CLD-0151). ');
$ax += rmatch($hoster,'netapp.com','Cloud Services. Not an access provider ISP (CLD-0152). ');
$ax += rmatch($hoster,'netdocuments.com','Cloud Services. Not an access provider ISP (CLD-0153). ');
$ax += rmatch($hoster,'newrelic.com','Cloud Services. Not an access provider ISP (CLD-0154). ');
$ax += rmatch($hoster,'nionex.com','Cloud Services. Not an access provider ISP (CLD-0155). ');
$ax += rmatch($hoster,'oco-inc.com','Cloud Services. Not an access provider ISP (CLD-0156). ');
$ax += rmatch($hoster,'onpathtech.com','Cloud Services. Not an access provider ISP (CLD-0157). ');
$ax += rmatch($hoster,'controltier.com','Cloud Services. Not an access provider ISP (CLD-0158). ');
$ax += rmatch($hoster,'openqrm.com','Cloud Services. Not an access provider ISP (CLD-0159). ');
$ax += rmatch($hoster,'opsource.com','Cloud Services. Not an access provider ISP (CLD-0160). ');
$ax += rmatch($hoster,'.panorama.com','Cloud Services. Not an access provider ISP (CLD-0161). ');
$ax += rmatch($hoster,'.parallels.com','Cloud Services. Not an access provider ISP (CLD-0162). ');
$ax += rmatch($hoster,'parascale.com','Cloud Services. Not an access provider ISP (CLD-0163). ');
$ax += rmatch($hoster,'parature.com','Cloud Services. Not an access provider ISP (CLD-0164). ');
$ax += rmatch($hoster,'pinqidentity.com','Cloud Services. Not an access provider ISP (CLD-0165). ');
$ax += rmatch($hoster,'pivotlink.com','Cloud Services. Not an access provider ISP (CLD-0166). ');
$ax += rmatch($hoster,'optimal.de','Cloud Services. Not an access provider ISP (CLD-0167). ');
$ax += rmatch($hoster,'quantivo.com','Cloud Services. Not an access provider ISP (CLD-0168). ');
$ax += rmatch($hoster,'.quest.com','Cloud Services. Not an access provider ISP (CLD-0169). ');
$ax += rmatch($hoster,'redi2.com','Cloud Services. Not an access provider ISP (CLD-0170). ');
$ax += rmatch($hoster,'reductivelabs.com','Cloud Services. Not an access provider ISP (CLD-0171). ');
$ax += rmatch($hoster,'responsys.com','Cloud Services. Not an access provider ISP (CLD-0172). ');
$ax += rmatch($hoster,'rightnow.com','Cloud Services. Not an access provider ISP (CLD-0173). ');
$ax += rmatch($hoster,'rollbase.com','Cloud Services. Not an access provider ISP (CLD-0174). ');
$ax += rmatch($hoster,'rpath.com','Cloud Services. Not an access provider ISP (CLD-0175). ');
$ax += rmatch($hoster,'sertifi.com','Cloud Services. Not an access provider ISP (CLD-0176). ');
$ax += rmatch($hoster,'evionet.com','Cloud Services. Not an access provider ISP (CLD-0177). ');
$ax += rmatch($hoster,'snaplogic.com','Cloud Services. Not an access provider ISP (CLD-0178). ');
$ax += rmatch($hoster,'soasta.com','Cloud Services. Not an access provider ISP (CLD-0179). ');
$ax += rmatch($hoster,'springcm.com','Cloud Services. Not an access provider ISP (CLD-0180). ');
$ax += rmatch($hoster,'streetsmarts.com','Cloud Services. Not an access provider ISP (CLD-0181). ');
$ax += rmatch($hoster,'successmetrics.com','Cloud Services. Not an access provider ISP (CLD-0182). ');
$ax += rmatch($hoster,'symplified.com','Cloud Services. Not an access provider ISP (CLD-0183). ');
$ax += rmatch($hoster,'syncplicity.com','Cloud Services. Not an access provider ISP (CLD-0184). ');
$ax += rmatch($hoster,'taleo.com','Cloud Services. Not an access provider ISP (CLD-0185). ');
$ax += rmatch($hoster,'.terracotta.org','Cloud Services. Not an access provider ISP (CLD-0186). ');
$ax += rmatch($hoster,'terramark.com','Cloud Services. Not an access provider ISP (CLD-0187). ');
$ax += rmatch($hoster,'1978th.net','Cloud Services. Not an access provider ISP (CLD-0188). ');
$ax += rmatch($hoster,'vaultscape.com','Cloud Services. Not an access provider ISP (CLD-0189). ');
$ax += rmatch($hoster,'vertica.com','Cloud Services. Not an access provider ISP (CLD-0190). ');
$ax += rmatch($hoster,'vmware.com','Cloud Services. Not an access provider ISP (CLD-0191). ');
$ax += rmatch($hoster,'.voda.com','Cloud Services. Not an access provider ISP (CLD-0192). ');
$ax += rmatch($hoster,'vordel.com','Cloud Services. Not an access provider ISP (CLD-0193). ');
$ax += rmatch($hoster,'.voxel.net','Cloud Services. Not an access provider ISP (CLD-0194). ');
$ax += rmatch($hoster,'webhosting.uk.com','Cloud Services. Not an access provider ISP (CLD-0195). ');
$ax += rmatch($hoster,'.workday.com','Cloud Services. Not an access provider ISP (CLD-0196). ');
$ax += rmatch($hoster,'xactlycorp.com','Cloud Services. Not an access provider ISP (CLD-0197). ');
$ax += rmatch($hoster,'xcalibre.co.uk','Cloud Services. Not an access provider ISP (CLD-0198). ');
$ax += rmatch($hoster,'xen.org','Cloud Services. Not an access provider ISP (CLD-0199). ');
$ax += rmatch($hoster,'xythos.com','Cloud Services. Not an access provider ISP (CLD-0200). ');
$ax += rmatch($hoster,'zembly.com','Cloud Services. Not an access provider ISP (CLD-0201). ');
$ax += rmatch($hoster,'zetta.net','Cloud Services. Not an access provider ISP (CLD-0202). ');
if(inmatch($whyblockout,'(CLD-0202)','') && ($ax == 1)){
	$zbamz = 0;
	$zbamz += inmatch($hoster,'ssg-corp.zetta.net','corporate office bypass. '); //74e
	if ($zbamz > 0){$ax -= 1;}
}

$ax += rmatch($hoster,'zimory.com','Cloud Services. Not an access provider ISP (CLD-0203). ');
$ax += rmatch($hoster,'zmanda.com','Cloud Services. Not an access provider ISP (CLD-0204). ');
$ax += rmatch($hoster,'zoho.com','Cloud Services. Not an access provider ISP (CLD-0205). ');
$ax += rmatch($hoster,'zuora.com','Cloud Services. Not an access provider ISP (CLD-0206). ');
$ax += inmatch($hoster,'ipredate','Skiddy friendly cloud services. INSTA-BAN (CLD-0207). '); //69c
$ax += inmatch($hoster,'ipredator','Skiddy friendly cloud services. INSTA-BAN (CLD-0208). '); //70d
$ax += rmatch($hoster,'candycloud.eu','Cloud Services. Not an access provider ISP (CLD-0209). '); //71g
$ax += rmatch($hoster,'ovh.net','Cloud Services. Not an access provider ISP. Allows IP hopping. (CLD-0210). '); //71
if(inmatch($whyblockout,'(CLD-0210)','') && ($ax == 1)){
	$zbamz = 0;
	$zbamz += inmatch($lcuseragent,'paperlibot','paperli bypass. '); //72b}
	if ($zbamz > 0){$ax -= 1;}
}
$ax += inmatch($hoster,'ipxserver','Cloud Services. Not an access provider ISP (CLD-0211). '); //74d


// Amazon AWS cloud block with bypasses.

$ax += (rmatch($hoster,'amazonaws.com','Amazon Web Services. Not an access provider ISP. Used by hackers, Keyword spamming SEO bots, and other unsavories (CLD-0AMZ). '));
if ((inmatch($whyblockout,'Amazon Web Services','Checked for bypass - ')) && ($ax > 0)){
	$zbamz = 0;
	$zbamz += inmatch($lcuseragent,'alexa','alexa bypass. '); //72b
	$zbamz += inmatch($lcuseragent,'postrank','postrank bypass. '); //72b
	$zbamz += inmatch($lcuseragent,'twitturly','twitturly bypass. '); //72b
	$zbamz += inmatch($lcuseragent,'twitterfeed','TwitterFeed bypass. '); //72b
	$zbamz += inmatch($lcuseragent,'bitlybot','bit.ly bypass. '); //72b
	$zbamz += inmatch($lcuseragent,'unwindfetchor','UnwindFetchor bypass. '); //72b
	$zbamz += inmatch($lcuseragent,'metauri','MetaURI bypass. '); //72b
	$zbamz += inmatch($lcuseragent,'pinterest','pinterest bypass. '); //73d
	$zbamz += rmatch($lcuseragent,'silk-accelerated=true','silk browser bypass. '); //73d
	$zbamz += rmatch($useragent,'Digg Feed Fetcher','Digg Feed Fetcher bypass. '); //74c
	$zbamz += rmatch($useragent,'Feedspot http://www.feedspot.com','Feedspot bypass. '); //74c
	$zbamz += lmatch($useragent,'NewRelicPinger/1.0','NewRelic pinger bypass. '); //75a
	if ($zbamz > 0){$ax -= 1;}
}


// *IPs and IP Ranges

// Skip section if coming from own IP
if($_SERVER['REMOTE_ADDR']!= $_SERVER['SERVER_ADDR']){

$ax += lmatch($address,'65.94.3.','Site Scraper (IP-001). ');
$ax += lmatch($address,'115.124.102.24','Infected Machine (IP-002). ');
$ax += lmatch($address,'122.221.10.234','Infected Machine (IP-003). ');
$ax += lmatch($address,'188.40.98.199','EYE De UKRAINE, very aggressive spider (IP-004). ');
$ax += lmatch($address,'188.40.42.199','YMC AG, very aggressive spider (IP-005). ');
$ax += iprange($address,'4.78.243.0','4.78.243.255','Quantcast banned network (IP-006). ');
$ax += iprange($address,'41.210.192.0','41.210.255.255','Movicel Telecomunicacoes LDA Angola (IP-007). ');
$ax += iprange($address,'59.93.0.0','59.93.255.255','India bad block (IP-008). ');
$ax += iprange($address,'64.128.80.0','64.128.83.255','networkphantom.net (IP-009). ');
//$ax += iprange($address,'65.98.0.0','65.98.127.255','pwebtech/FortressITX spam-friendly host/aviary.com unregulated proxy service (IP-010). '); //removed 73d
$ax += iprange($address,'65.208.151.112','65.208.151.119','Jarvis Universal Purchase Company (IP-011). ');
$ax += iprange($address,'66.7.192.0','66.7.223.255','3IX / host-care (IP-012). ');
$ax += iprange($address,'66.228.192.0','66.228.223.255','Swift Ventures (IP-013). ');
$ax += iprange($address,'67.215.230.0','67.215.230.255','Email harvester from India (setooz.com) (IP-014). ');
$ax += iprange($address,'68.168.216.0','68.168.216.255','Attacking /24 (IP-015). ');
$ax += iprange($address,'69.36.0.0','69.36.15.255','3IX / host-care (IP-016). ');
$ax += iprange($address,'69.72.128.0','69.72.159.255','Hacker/Spammer Hosts (IP-017). ');
$ax += iprange($address,'69.89.16.0','69.89.31.255','Hacker/Spammer Hosts (IP-018). ');
$ax += iprange($address,'69.210.185.0','69.210.185.7','spunge.org (IP-019). ');
$ax += iprange($address,'72.20.99.0','72.20.99.255','Content scraper for paid service (IP-020). ');
$ax += iprange($address,'72.27.0.0','72.27.213.104','Jamaica Spammer Network (frittobay) (IP-021). '); //70a split
$ax += iprange($address,'72.27.213.106','72.27.223.255','Jamaica Spammer Network (frittobay) (IP-022). '); //70a split
$ax += iprange($address,'79.143.177.0','79.143.177.255',"Netherlands Site Host (doesn't need access to other sites) (IP-023). ");
$ax += iprange($address,'80.81.159.0','80.81.159.255','Problematic netblock (IP-024). ');
$ax += iprange($address,'80.81.208.0','80.81.223.255','Problematic netblock (IP-025). ');
$ax += iprange($address,'80.87.152.0','80.87.152.255','Server farm infected with grum spambot (IP-026). ');
$ax += iprange($address,'80.93.122.0','80.93.122.255','Ukrainian Attack Prone Netblock (IP-027). ');
$ax += iprange($address,'81.21.74.0','81.21.74.255','webfusion.co.uk (IP-028). ');
$ax += iprange($address,'81.223.254.0','81.223.254.127','smartservercontrol.com (IP-029). ');
$ax += iprange($address,'83.233.30.0','83.233.33.255','Multiple referer spam block (IP-030). ');
$ax += iprange($address,'84.201.224.0','84.201.239.255','Spam network (IP-031). '); 
$ax += iprange($address,'85.131.188.0','85.131.191.255','.de hosts (IP-032). ');
$ax += iprange($address,'87.101.0.0','87.101.15.255','PureHosting.nl, a possible extention of keyweb.de .ru (bothost) (IP-033). ');
$ax += iprange($address,'87.118.68.0','87.118.122.255','keyweb.de .ru (bothost) (IP-034). ');
$ax += iprange($address,'87.248.64.0','87.248.95.255','Polish Bad Block (IP-035). ');
$ax += iprange($address,'87.248.162.0','87.248.189.255','Moldavia Bad Block (IP-036). ');
$ax += iprange($address,'91.205.40.0','91.205.43.255','British Virgin Islands Spambots (IP-037). ');
$ax += iprange($address,'91.214.44.0','91.214.45.255','Altushost bothost and/or Server Farm (IP-038). ');
$ax += iprange($address,'95.24.0.0','95.24.255.255','Corbina.ru (IP-039). ');
$ax += iprange($address,'95.128.128.0','95.129.199.255','Problematic Russian Netblock (IP-040). '); // split in 63c
$ax += iprange($address,'95.129.204.0','95.129.223.255','Problematic Russian Netblock (IP-041). '); // split in 63c, 69c, 69f
$ax += iprange($address,'95.129.232.0','95.131.103.255','Problematic Russian Netblock (IP-042). '); // split in 63c, 69c, 69f
$ax += iprange($address,'95.131.112.0','95.135.255.255','Problematic Russian Netblock (IP-043). '); // split in 63c, 69c
$ax += iprange($address,'113.160.0.0','113.191.255.255','localhost spoofing netblock (IP-044). ');
$ax += cidrblock($address,'118.98.0.0/17','Spammy Indonesia Netblock (IP-045). '); // mod 71h
$ax += iprange($address,'118.175.254.0','118.175.255.255','Bangkok Attack prone 512 address block (IP-046). ');
$ax += iprange($address,'122.182.2.0','122.182.2.255','India spammer/malware host (IP-047). ');
$ax += iprange($address,'124.123.0.0','124.125.255.255','Indian hackers - 192K address netblock is bad (IP-048). ');
$ax += iprange($address,'141.11.0.0','141.11.255.255','technicolor.c0m (IP-049). '); //69d
$ax += cidrblock($address,'178.239.48.0/20','Hostile Belize Block (IP-050). '); //69f
$ax += iprange($address,'187.32.0.0','187.32.255.255','Problematic Brazilian netblock (IP-051). ');
$ax += iprange($address,'173.45.65.155','173.45.65.158','Bot not obeying nofollow (IP-052). '); //71f
$ax += iprange($address,'188.92.72.0','188.92.79.255','adtechnology.lv (IP-053). ');
$ax += iprange($address,'189.15.0.0','189.15.255.255','Problematic Brazilian netblock (IP-054). ');
$ax += iprange($address,'189.41.0.0','189.41.255.255','Problematic Brazilian netblock (IP-055). ');
$ax += iprange($address,'189.112.0.0','189.112.255.255','Problematic Brazilian netblock (IP-056). ');
$ax += iprange($address,'193.200.150.0','193.200.150.255',"Anonymizing proxy network, hacker's paradise (IP-057). ");
$ax += iprange($address,'194.8.74.0','194.8.75.255','British Virgin Islands Spambots (IP-058). ');
$ax += iprange($address,'195.87.102.0','195.87.102.255','Comment spammer netblock (IP-059). ');
$ax += iprange($address,'195.238.38.0','195.238.71.255','Problematic netblock (IP-060). ');
$ax += iprange($address,'195.238.95.0','195.238.118.255','Problematic netblock (IP-061). ');
$ax += iprange($address,'200.63.42.0','200.63.47.255','panamaserver.com .ru (IP-062). ');
$ax += iprange($address,'200.146.192.0','200.146.255.255','Problematic Brazilian netblock (IP-063). ');
$ax += iprange($address,'200.170.128.0','200.170.255.255','Problematic Brazilian netblock (IP-064). ');
$ax += iprange($address,'200.225.192.0','200.225.255.255','Problematic Brazilian netblock (IP-065). ');
$ax += iprange($address,'200.233.128.0','200.233.255.255','Problematic Brazilian netblock (IP-066). ');
$ax += iprange($address,'201.16.128.0','201.16.255.255','Problematic Brazilian netblock (IP-067). ');
$ax += iprange($address,'201.48.0.0','201.48.255.255','Problematic Brazilian netblock (IP-068). ');
$ax += iprange($address,'203.160.1.0','203.160.1.255','Vietnam Junk Mailer/Forum Spammer (Spoofed as 203.160.1.49 localhost!) (IP-069). ');
$ax += iprange($address,'204.8.34.0','204.8.34.255','Swift Ventures (IP-070). ');
$ax += iprange($address,'204.11.16.0','204.11.19.255','onestop.net (IP-071). ');
$ax += iprange($address,'204.13.164.0','204.13.167.255','Swift Ventures (IP-072). ');
$ax += iprange($address,'204.15.224.0','204.15.255.255','Swift Ventures (IP-073). ');
$ax += iprange($address,'204.124.180.0','204.124.183.255','Comment spammer netblock (IP-074). ');
$ax += iprange($address,'204.244.109.240','204.244.109.247','Tynt, Evil Proxy (IP-075). ');
$ax += iprange($address,'204.244.120.176','204.244.120.183','Tynt, Evil Proxy (IP-076). ');
$ax += iprange($address,'206.161.0.0','206.161.255.255','Questionable Hosts, some malicious. Do not need access to your site (IP-077). ');
$ax += iprange($address,'206.196.110.0','206.196.111.255','Rose Hosting. Does not need access to your site (IP-078). ');
$ax += iprange($address,'207.38.118.0','207.38.118.255','Scraper Network (IP-079). '); //69b
$ax += iprange($address,'207.226.88.0','207.226.95.255','many sitehosts - questionable behavior (IP-080). ');
$ax += iprange($address,'208.64.28.0','208.64.31.255','.bh servers caught being b.h. surfers (IP-081). ');
$ax += iprange($address,'208.64.200.0','208.64.203.255','Accentra Inc. , Bothost and/or Server Farm (IP-082). ');
$ax += iprange($address,'208.64.230.0','208.64.230.127','Possible Terrorist Serverblock (credit: diabolicbg!) (IP-083). ');
$ax += iprange($address,'208.99.192.0','208.99.255.255','Swift Ventures spam/scrape network (IP-084). ');
$ax += iprange($address,'208.115.111.240','208.115.111.255','Dotbot - Paid Service SEO Service (Keyword Spamming Aides) (IP-085). ');
$ax += iprange($address,'209.62.96.0','209.62.127.255','Questionable Hosts, some malicious. Do not need access to your site (IP-086). ');
$ax += iprange($address,'209.135.34.0','209.135.157.255','Questionable Hosts, some malicious. Do not need access to your site (IP-087). ');
$ax += iprange($address,'209.249.0.0','209.249.255.255','HUGE block of spam-mail servers, and scanbots (IP-088). ');
$ax += iprange($address,'210.0.160.0','210.0.255.255','Japanese servers on Hong Kong netblock, suspicious (IP-089). ');
$ax += iprange($address,'211.43.0.0','211.45.191.255','Korean Suspicious (IP-090). ');
$ax += iprange($address,'211.91.0.0','211.97.255.255','Chinese Bad Block (IP-091). ');
$ax += iprange($address,'212.113.41.0','212.113.63.255','Ukraine Bad Block (IP-092). ');
$ax += iprange($address,'212.117.188.0','212.117.188.255','Altushost bothost and/or Server Farm (IP-093). ');
$ax += iprange($address,'212.178.0.0','212.178.29.255','Ukraine Bad Block (IP-094). ');
$ax += iprange($address,'213.166.128.0','213.166.159.255','Saudi Arabia bothost (IP-095). ');
$ax += iprange($address,'216.240.128.0','216.240.159.255','Abusive Network (IP-096). '); //71d
$ax += iprange($address,'218.56.21.0','218.56.21.255','Chinese Bad Block (IP-097). ');
$ax += iprange($address,'222.124.31.0','222.124.255.255','India Bad Block (IP-098). ');
$ax += cidrblock($address,'108.3.64.0/18','Cyberterrorist hiding in this netblock of 16384 IPs (IP-100). '); //71g
$ax += cidrblock($address,'93.182.128.0/18','Heavy abuse Swedish VPN VIAEU-AS47155 (IP-101). '); //71
$ax += iprange($address,'5.135.18.160','5.135.18.191','Leak ID scraper. (IP-102). '); //71
$ax += cidrblock($address,'5.144.176.0/24','HSHNetworkInternational (IP-103). '); //71
$ax += iprange($address,'68.68.107.160','68.68.107.161','Anchorfree/HotSpotShield freak network. (IP-104). '); //71
$ax += cidrblock($address,'194.71.222.0/23','ERRSY-NET: Proxy services for scrapers and SEOs (IP-105). '); //72b
$ax += cidrblock($address,'178.238.232.0/21','ice2solutions , known dangerous host/network (IP-106). '); //74c
$ax += lmatch($address,'78.158.11.226','Project Honey Pot rule-breaker, vulnerability scanner (IP-107). ');


$ax += cidrblock($address,'72.10.32.0/19','MediaTemple, illegal nameserver response on reverse lookup. Caught scraping (IP-099). ');


// *Ecatel/internetserviceteam.com/netdirekt e.K./NetDirect/jmhservices.com.

$ax += iprange($address,'62.41.26.0','62.41.27.255','Ecatel/internetserviceteam.com/netdirekt e.K./NetDirect/jmhservices.com. ');
$ax += iprange($address,'77.223.128.0','77.223.159.255','Ecatel/internetserviceteam.com/netdirekt e.K./NetDirect/jmhservices.com. ');
$ax += iprange($address,'78.40.224.0','78.40.231.255','Ecatel/internetserviceteam.com/netdirekt e.K./NetDirect/jmhservices.com. ');
$ax += iprange($address,'78.159.96.0','78.159.127.255','Ecatel/internetserviceteam.com/netdirekt e.K./NetDirect/jmhservices.com. ');
$ax += cidrblock($address,'80.82.64.0/20','Ecatel/internetserviceteam.com/netdirekt e.K./NetDirect/jmhservices.com. '); //75a
$ax += iprange($address,'84.16.224.0','84.16.255.255','Ecatel/internetserviceteam.com/netdirekt e.K./NetDirect/jmhservices.com. ');
$ax += iprange($address,'89.149.192.0','89.149.255.255','Ecatel/internetserviceteam.com/netdirekt e.K./NetDirect/jmhservices.com. ');
$ax += iprange($address,'89.248.160.0','89.248.175.255','Ecatel/internetserviceteam.com/netdirekt e.K./NetDirect/jmhservices.com. ');
$ax += iprange($address,'91.191.160.0','91.191.175.255','Ecatel/internetserviceteam.com/netdirekt e.K./NetDirect/jmhservices.com. ');
$ax += iprange($address,'92.45.72.0','92.45.72.255','Ecatel/internetserviceteam.com/netdirekt e.K./NetDirect/jmhservices.com. ');
$ax += iprange($address,'93.174.88.0','93.174.95.255','Ecatel/internetserviceteam.com/netdirekt e.K./NetDirect/jmhservices.com. ');
$ax += iprange($address,'93.187.200.0','93.187.207.255','Ecatel/internetserviceteam.com/netdirekt e.K./NetDirect/jmhservices.com. ');
$ax += iprange($address,'94.102.48.0','94.102.63.255','Ecatel/internetserviceteam.com/netdirekt e.K./NetDirect/jmhservices.com. ');
$ax += iprange($address,'95.168.160.0','95.168.191.255','Ecatel/internetserviceteam.com/netdirekt e.K./NetDirect/jmhservices.com. ');
$ax += iprange($address,'95.211.85.0','95.211.86.255','Ecatel/internetserviceteam.com/netdirekt e.K./NetDirect/jmhservices.com. ');
$ax += iprange($address,'188.72.192.0','188.72.255.255','Ecatel/internetserviceteam.com/netdirekt e.K./NetDirect/jmhservices.com. ');
$ax += iprange($address,'212.95.32.0','212.95.255.255','Ecatel/internetserviceteam.com/netdirekt e.K./NetDirect/jmhservices.com. ');
$ax += iprange($address,'212.252.24.0','212.252.31.255','Ecatel/internetserviceteam.com/netdirekt e.K./NetDirect/jmhservices.com. ');
$ax += iprange($address,'217.20.112.0','217.20.127.255','Ecatel/internetserviceteam.com/netdirekt e.K./NetDirect/jmhservices.com. ');
$ax += inmatch($hoster,'ecatel','Ecatel/internetserviceteam.com/netdirekt e.K./NetDirect/jmhservices.com. ');
$ax += inmatch($hoster,'netdirekt','Ecatel/internetserviceteam.com/netdirekt e.K./NetDirect/jmhservices.com. ');
$ax += inmatch($hoster,'netdirect','Ecatel/internetserviceteam.com/netdirekt e.K./NetDirect/jmhservices.com. ');
$ax += inmatch($hoster,'internetserviceteam','Ecatel/internetserviceteam.com/netdirekt e.K./NetDirect/jmhservices.com. ');
$ax += inmatch($hoster,'jmhservices','Ecatel/internetserviceteam.com/netdirekt e.K./NetDirect/jmhservices.com. ');


// *RapidSwitch (Crimeware Friendly ISP)
// (hpHosts Blog warned us about this one)

$ax += iprange($address,'78.129.128.0','78.129.255.255','a Rapidswitch. ');
$ax += iprange($address,'82.145.32.0','82.145.63.255','b Rapidswitch. ');
$ax += iprange($address,'83.142.224.0','83.142.231.255','c Rapidswitch. ');
$ax += iprange($address,'87.117.192.0','87.117.255.255','d Rapidswitch. ');
$ax += iprange($address,'95.154.192.0','95.154.255.255','e Rapidswitch. ');
$ax += iprange($address,'109.75.160.0','109.75.167.255','f Rapidswitch. ');
$ax += iprange($address,'109.169.0.0','109.169.127.255','g Rapidswitch. ');
$ax += iprange($address,'193.201.200.0','193.201.201.255','h Rapidswitch. ');
$ax += iprange($address,'193.227.244.0','193.227.245.255','i Rapidswitch. ');
$ax += iprange($address,'195.40.15.0','195.40.15.255','j Rapidswitch. ');
$ax += iprange($address,'195.62.10.0','195.62.11.255','k Rapidswitch. ');
$ax += iprange($address,'195.242.214.0','195.242.215.255','l Rapidswitch. ');
$ax += iprange($address,'213.228.193.0','213.228.193.255','m Rapidswitch. ');
$ax += iprange($address,'217.147.80.0','217.147.95.255','n Rapidswitch. ');

// iweb/privatedns Domain Spammers
// Snooping on your site, sniping your domain.

$ax += rmatch($hoster,'privatedns.com','RFC ignorant/Suspected domain name snipers/spammers. '); //70b
$ax += rmatch($hoster,'iweb.ca','RFC ignorant/Suspected domain name snipers/spammers. '); //70b
$ax += rmatch($hoster,'iweb.com','RFC ignorant/Suspected domain name snipers/spammers. '); //70b
$ax += lmatch($hoster,'iweb','RFC ignorant/Suspected domain name snipers/spammers. '); //70b
$ax += lmatch($hoster,'www.iweb','RFC ignorant/Suspected domain name snipers/spammers. '); //70b

// Spamahost and hostkey network.
// self explanatory!

$ax += cidrblock($address,'46.17.96.0/21','Hostkey & Spamahost known range. '); //70c
$ax += cidrblock($address,'66.96.128.0/18','Spamahost known range. '); //70c
$ax += cidrblock($address,'83.229.128.0/17','Spamahost known range. '); //70c
$ax += cidrblock($address,'195.162.68.0/23','Hostkey known range (spammers). '); //70c
$ax += inmatch($hoster,'spamahost','Spamahost. '); //70c
$ax += rmatch($hoster,'hostkey.ru','Hostkey (known spammers). '); //70c

// Nobis Technology Group / Ubiquity Servers / AS15003
// Not an access provider. Exceedingly bad record.

$ax += cidrblock($address,'23.19.0.0/16','Nobis Technology Group. (ASN-NOBIS-TECH-0). '); //74d
$ax += cidrblock($address,'23.80.0.0/16','Nobis Technology Group. (ASN-NOBIS-TECH-1). '); //74d
$ax += cidrblock($address,'23.81.0.0/17','Nobis Technology Group. (ASN-NOBIS-TECH-2). '); //74d
$ax += cidrblock($address,'23.81.128.0/18','Nobis Technology Group. (ASN-NOBIS-TECH-3). '); //74d
$ax += cidrblock($address,'23.81.192.0/20','Nobis Technology Group. (ASN-NOBIS-TECH-4). '); //74d
$ax += cidrblock($address,'23.81.216.0/21','Nobis Technology Group. (ASN-NOBIS-TECH-5). '); //74d
$ax += cidrblock($address,'23.81.224.0/19','Nobis Technology Group. (ASN-NOBIS-TECH-6). '); //74d
$ax += cidrblock($address,'23.82.0.0/16','Nobis Technology Group. (ASN-NOBIS-TECH-7). '); //74d
$ax += cidrblock($address,'23.83.0.0/17','Nobis Technology Group. (ASN-NOBIS-TECH-8). '); //74d
$ax += cidrblock($address,'23.83.128.0/18','Nobis Technology Group. (ASN-NOBIS-TECH-9). '); //74d
$ax += cidrblock($address,'23.83.192.0/20','Nobis Technology Group. (ASN-NOBIS-TECH-10). '); //74d
$ax += cidrblock($address,'23.104.0.0/16','Nobis Technology Group. (ASN-NOBIS-TECH-11). '); //74d
$ax += cidrblock($address,'23.105.0.0/19','Nobis Technology Group. (ASN-NOBIS-TECH-12). '); //74d
$ax += cidrblock($address,'23.105.64.0/19','Nobis Technology Group. (ASN-NOBIS-TECH-13). '); //74d
$ax += cidrblock($address,'64.64.224.0/19','Nobis Technology Group. (ASN-NOBIS-TECH-14). '); //74d
$ax += cidrblock($address,'64.120.1.0/24','Nobis Technology Group. (ASN-NOBIS-TECH-15). '); //74d
$ax += cidrblock($address,'64.120.2.0/23','Nobis Technology Group. (ASN-NOBIS-TECH-16). '); //74d
$ax += cidrblock($address,'64.120.4.0/22','Nobis Technology Group. (ASN-NOBIS-TECH-17). '); //74d
$ax += cidrblock($address,'64.120.8.0/21','Nobis Technology Group. (ASN-NOBIS-TECH-18). '); //74d
$ax += cidrblock($address,'64.120.16.0/20','Nobis Technology Group. (ASN-NOBIS-TECH-19). '); //74d
$ax += cidrblock($address,'64.120.32.0/19','Nobis Technology Group. (ASN-NOBIS-TECH-20). '); //74d
$ax += cidrblock($address,'64.120.64.0/19','Nobis Technology Group. (ASN-NOBIS-TECH-21). '); //74d
$ax += cidrblock($address,'64.120.96.0/20','Nobis Technology Group. (ASN-NOBIS-TECH-22). '); //74d
$ax += cidrblock($address,'64.120.112.0/21','Nobis Technology Group. (ASN-NOBIS-TECH-23). '); //74d
$ax += cidrblock($address,'64.120.122.0/23','Nobis Technology Group. (ASN-NOBIS-TECH-24). '); //74d
$ax += cidrblock($address,'64.120.124.0/22','Nobis Technology Group. (ASN-NOBIS-TECH-25). '); //74d
$ax += cidrblock($address,'64.250.152.0/22','Nobis Technology Group. (ASN-NOBIS-TECH-26). '); //74d
$ax += cidrblock($address,'67.201.0.0/21','Nobis Technology Group. (ASN-NOBIS-TECH-27). '); //74d
$ax += cidrblock($address,'67.201.48.0/23','Nobis Technology Group. (ASN-NOBIS-TECH-28). '); //74d
$ax += cidrblock($address,'67.230.160.0/19','Nobis Technology Group. (ASN-NOBIS-TECH-29). '); //74d
$ax += cidrblock($address,'68.168.128.0/20','Nobis Technology Group. (ASN-NOBIS-TECH-30). '); //74d
$ax += cidrblock($address,'69.31.107.0/24','Nobis Technology Group. (ASN-NOBIS-TECH-31). '); //74d
$ax += cidrblock($address,'69.147.224.0/19','Nobis Technology Group. (ASN-NOBIS-TECH-32). '); //74d
$ax += cidrblock($address,'69.174.60.0/22','Nobis Technology Group. (ASN-NOBIS-TECH-33). '); //74d
$ax += cidrblock($address,'70.32.32.0/20','Nobis Technology Group. (ASN-NOBIS-TECH-34). '); //74d
$ax += cidrblock($address,'72.37.204.0/24','Nobis Technology Group. (ASN-NOBIS-TECH-35). '); //74d
$ax += cidrblock($address,'72.37.221.0/24','Nobis Technology Group. (ASN-NOBIS-TECH-36). '); //74d
$ax += cidrblock($address,'72.37.222.0/23','Nobis Technology Group. (ASN-NOBIS-TECH-37). '); //74d
$ax += cidrblock($address,'72.37.224.0/21','Nobis Technology Group. (ASN-NOBIS-TECH-38). '); //74d
$ax += cidrblock($address,'72.37.237.0/24','Nobis Technology Group. (ASN-NOBIS-TECH-39). '); //74d
$ax += cidrblock($address,'72.37.242.0/23','Nobis Technology Group. (ASN-NOBIS-TECH-40). '); //74d
$ax += cidrblock($address,'72.37.246.0/23','Nobis Technology Group. (ASN-NOBIS-TECH-41). '); //74d
$ax += cidrblock($address,'74.82.192.0/19','Nobis Technology Group. (ASN-NOBIS-TECH-42). '); //74d
$ax += cidrblock($address,'96.45.176.0/20','Nobis Technology Group. (ASN-NOBIS-TECH-43). '); //74d
$ax += cidrblock($address,'108.62.0.0/16','Nobis Technology Group. (ASN-NOBIS-TECH-44). '); //74d
$ax += cidrblock($address,'108.171.33.0/24','Nobis Technology Group. (ASN-NOBIS-TECH-45). '); //74d
$ax += cidrblock($address,'108.171.34.0/23','Nobis Technology Group. (ASN-NOBIS-TECH-46). '); //74d
$ax += cidrblock($address,'108.171.36.0/23','Nobis Technology Group. (ASN-NOBIS-TECH-47). '); //74d
$ax += cidrblock($address,'108.171.38.0/24','Nobis Technology Group. (ASN-NOBIS-TECH-48). '); //74d
$ax += cidrblock($address,'108.171.43.0/24','Nobis Technology Group. (ASN-NOBIS-TECH-49). '); //74d
$ax += cidrblock($address,'108.171.44.0/22','Nobis Technology Group. (ASN-NOBIS-TECH-50). '); //74d
$ax += cidrblock($address,'108.171.53.0/24','Nobis Technology Group. (ASN-NOBIS-TECH-51). '); //74d
$ax += cidrblock($address,'108.171.54.0/23','Nobis Technology Group. (ASN-NOBIS-TECH-52). '); //74d
$ax += cidrblock($address,'108.171.56.0/24','Nobis Technology Group. (ASN-NOBIS-TECH-53). '); //74d
$ax += cidrblock($address,'108.171.59.0/24','Nobis Technology Group. (ASN-NOBIS-TECH-54). '); //74d
$ax += cidrblock($address,'108.171.60.0/23','Nobis Technology Group. (ASN-NOBIS-TECH-55). '); //74d
$ax += cidrblock($address,'108.171.63.0/24','Nobis Technology Group. (ASN-NOBIS-TECH-56). '); //74d
$ax += cidrblock($address,'108.177.128.0/17','Nobis Technology Group. (ASN-NOBIS-TECH-57). '); //74d
$ax += cidrblock($address,'142.91.0.0/16','Nobis Technology Group. (ASN-NOBIS-TECH-58). '); //74d
$ax += cidrblock($address,'142.234.0.0/16','Nobis Technology Group. (ASN-NOBIS-TECH-59). '); //74d
$ax += cidrblock($address,'147.255.0.0/16','Nobis Technology Group. (ASN-NOBIS-TECH-60). '); //74d
$ax += cidrblock($address,'162.209.128.0/17','Nobis Technology Group. (ASN-NOBIS-TECH-61). '); //74d
$ax += cidrblock($address,'172.240.0.0/15','Nobis Technology Group. (ASN-NOBIS-TECH-62). '); //74d
$ax += cidrblock($address,'172.247.0.0/16','Nobis Technology Group. (ASN-NOBIS-TECH-63). '); //74d
$ax += cidrblock($address,'172.255.0.0/16','Nobis Technology Group. (ASN-NOBIS-TECH-64). '); //74d
$ax += cidrblock($address,'173.208.0.0/18','Nobis Technology Group. (ASN-NOBIS-TECH-65). '); //74d
$ax += cidrblock($address,'173.208.64.0/19','Nobis Technology Group. (ASN-NOBIS-TECH-66). '); //74d
$ax += cidrblock($address,'173.208.96.0/21','Nobis Technology Group. (ASN-NOBIS-TECH-67). '); //74d
$ax += cidrblock($address,'173.208.104.0/24','Nobis Technology Group. (ASN-NOBIS-TECH-68). '); //74d
$ax += cidrblock($address,'173.208.106.0/23','Nobis Technology Group. (ASN-NOBIS-TECH-69). '); //74d
$ax += cidrblock($address,'173.208.108.0/22','Nobis Technology Group. (ASN-NOBIS-TECH-70). '); //74d
$ax += cidrblock($address,'173.208.112.0/20','Nobis Technology Group. (ASN-NOBIS-TECH-71). '); //74d
$ax += cidrblock($address,'173.234.0.0/16','Nobis Technology Group. (ASN-NOBIS-TECH-72). '); //74d
$ax += cidrblock($address,'174.34.128.0/18','Nobis Technology Group. (ASN-NOBIS-TECH-73). '); //74d
$ax += cidrblock($address,'174.137.48.0/20','Nobis Technology Group. (ASN-NOBIS-TECH-74). '); //74d
$ax += cidrblock($address,'188.130.250.0/24','Nobis Technology Group. (ASN-NOBIS-TECH-75). '); //74d
$ax += cidrblock($address,'192.151.224.0/20','Nobis Technology Group. (ASN-NOBIS-TECH-76). '); //74d
$ax += cidrblock($address,'192.163.160.0/19','Nobis Technology Group. (ASN-NOBIS-TECH-77). '); //74d
$ax += cidrblock($address,'192.229.64.0/18','Nobis Technology Group. (ASN-NOBIS-TECH-78). '); //74d
$ax += cidrblock($address,'192.238.128.0/17','Nobis Technology Group. (ASN-NOBIS-TECH-79). '); //74d
$ax += cidrblock($address,'192.253.240.0/21','Nobis Technology Group. (ASN-NOBIS-TECH-80). '); //74d
$ax += cidrblock($address,'196.45.112.0/22','Nobis Technology Group. (ASN-NOBIS-TECH-81). '); //74d
$ax += cidrblock($address,'198.48.96.0/20','Nobis Technology Group. (ASN-NOBIS-TECH-82). '); //74d
$ax += cidrblock($address,'216.6.224.0/20','Nobis Technology Group. (ASN-NOBIS-TECH-83). '); //74d
$ax += cidrblock($address,'216.151.31.0/24','Nobis Technology Group. (ASN-NOBIS-TECH-84). '); //74d
$ax += cidrblock($address,'216.152.224.0/20','Nobis Technology Group. (ASN-NOBIS-TECH-85). '); //74d
$ax += cidrblock($address,'216.193.237.0/24','Nobis Technology Group. (ASN-NOBIS-TECH-86). '); //74d
$ax += cidrblock($address,'216.231.128.0/20','Nobis Technology Group. (ASN-NOBIS-TECH-87). '); //74d
$ax += inmatch($hoster,'nobis','Nobis Technology Group. (ASN-NOBIS-TECH-88). '); //70c
$ax += inmatch($hoster,'ubiquity','Nobis Technology Group. (ASN-NOBIS-TECH-89). '); //70c


// Rackspace
// AS19994/AS27357/AS15395/AS33070/AS12200

$ax += cidrblock($address,'5.79.0.0/18','Rackspace (ASN-RKSP-001). ');
$ax += cidrblock($address,'31.222.128.0/18','Rackspace (ASN-RKSP-002). ');
$ax += cidrblock($address,'37.188.96.0/19','Rackspace (ASN-RKSP-003). ');
$ax += cidrblock($address,'46.38.160.0/19','Rackspace (ASN-RKSP-004). ');
$ax += cidrblock($address,'50.28.192.0/22','Rackspace (ASN-RKSP-005). ');
$ax += cidrblock($address,'50.56.0.0/15','Rackspace (ASN-RKSP-006). ');
$ax += cidrblock($address,'64.39.0.0/19','Rackspace (ASN-RKSP-007). ');
$ax += cidrblock($address,'64.49.192.0/18','Rackspace (ASN-RKSP-008). ');
$ax += cidrblock($address,'65.61.128.0/18','Rackspace (ASN-RKSP-009). ');
$ax += cidrblock($address,'66.216.64.0/18','Rackspace (ASN-RKSP-010). ');
$ax += cidrblock($address,'67.23.0.0/19','Rackspace (ASN-RKSP-011). ');
$ax += cidrblock($address,'67.23.32.0/20','Rackspace (ASN-RKSP-012). ');
$ax += cidrblock($address,'67.192.0.0/16','Rackspace (ASN-RKSP-013). ');
$ax += cidrblock($address,'67.207.128.0/19','Rackspace (ASN-RKSP-014). ');
$ax += cidrblock($address,'69.20.0.0/17','Rackspace (ASN-RKSP-015). ');
$ax += cidrblock($address,'72.3.128.0/17','Rackspace (ASN-RKSP-016). ');
$ax += cidrblock($address,'72.4.112.0/20','Rackspace (ASN-RKSP-017). ');
$ax += cidrblock($address,'72.32.0.0/16','Rackspace (ASN-RKSP-018). ');
$ax += cidrblock($address,'74.91.84.0/22','Rackspace (ASN-RKSP-019). ');
$ax += cidrblock($address,'74.91.88.0/21','Rackspace (ASN-RKSP-020). ');
$ax += cidrblock($address,'74.123.152.0/22','Rackspace (ASN-RKSP-021). ');
$ax += cidrblock($address,'74.205.0.0/17','Rackspace (ASN-RKSP-022). ');
$ax += cidrblock($address,'78.136.0.0/18','Rackspace (ASN-RKSP-023). ');
$ax += cidrblock($address,'83.138.128.0/18','Rackspace (ASN-RKSP-024). ');
$ax += cidrblock($address,'89.234.0.0/18','Rackspace (ASN-RKSP-025). ');
$ax += cidrblock($address,'91.227.208.0/24','Rackspace (ASN-RKSP-026). ');
$ax += cidrblock($address,'92.52.64.0/18','Rackspace (ASN-RKSP-027). ');
$ax += cidrblock($address,'94.236.0.0/17','Rackspace (ASN-RKSP-028). ');
$ax += cidrblock($address,'95.138.128.0/18','Rackspace (ASN-RKSP-029). ');
$ax += cidrblock($address,'98.129.0.0/16','Rackspace (ASN-RKSP-030). ');
$ax += cidrblock($address,'103.28.40.0/22','Rackspace (ASN-RKSP-031). ');
$ax += cidrblock($address,'108.166.0.0/17','Rackspace (ASN-RKSP-032). ');
$ax += cidrblock($address,'108.171.160.0/19','Rackspace (ASN-RKSP-033). ');
$ax += cidrblock($address,'134.8.0.0/24','Rackspace (ASN-RKSP-034). ');
$ax += cidrblock($address,'134.8.2.0/24','Rackspace (ASN-RKSP-035). ');
$ax += cidrblock($address,'164.177.128.0/19','Rackspace (ASN-RKSP-036). ');
$ax += cidrblock($address,'173.45.224.0/19','Rackspace (ASN-RKSP-037). ');
$ax += cidrblock($address,'173.203.0.0/16','Rackspace (ASN-RKSP-038). ');
$ax += cidrblock($address,'174.143.0.0/16','Rackspace (ASN-RKSP-039). ');
$ax += cidrblock($address,'175.107.191.0/24','Rackspace (ASN-RKSP-040). ');
$ax += cidrblock($address,'184.106.0.0/16','Rackspace (ASN-RKSP-041). ');
$ax += cidrblock($address,'192.204.40.0/21','Rackspace (ASN-RKSP-042). ');
$ax += cidrblock($address,'193.142.244.0/24','Rackspace (ASN-RKSP-043). ');
$ax += cidrblock($address,'198.61.128.0/17','Rackspace (ASN-RKSP-044). ');
$ax += cidrblock($address,'198.101.128.0/17','Rackspace (ASN-RKSP-045). ');
$ax += cidrblock($address,'198.184.18.0/24','Rackspace (ASN-RKSP-046). ');
$ax += cidrblock($address,'199.15.212.0/22','Rackspace (ASN-RKSP-047). ');
$ax += cidrblock($address,'199.91.52.0/23','Rackspace (ASN-RKSP-048). ');
$ax += cidrblock($address,'199.187.164.0/22','Rackspace (ASN-RKSP-049). ');
$ax += cidrblock($address,'199.241.120.0/21','Rackspace (ASN-RKSP-050). ');
$ax += cidrblock($address,'203.55.21.0/24','Rackspace (ASN-RKSP-051). ');
$ax += cidrblock($address,'204.232.128.0/17','Rackspace (ASN-RKSP-052). ');
$ax += cidrblock($address,'205.166.177.0/24','Rackspace (ASN-RKSP-053). ');
$ax += cidrblock($address,'206.188.192.0/19','Rackspace (ASN-RKSP-054). ');
$ax += cidrblock($address,'207.32.116.0/24','Rackspace (ASN-RKSP-055). ');
$ax += cidrblock($address,'207.71.8.0/24','Rackspace (ASN-RKSP-056). ');
$ax += cidrblock($address,'207.71.44.0/23','Rackspace (ASN-RKSP-057). ');
$ax += cidrblock($address,'207.97.192.0/18','Rackspace (ASN-RKSP-058). ');
$ax += cidrblock($address,'207.235.4.0/22','Rackspace (ASN-RKSP-059). ');
$ax += cidrblock($address,'207.235.16.0/23','Rackspace (ASN-RKSP-060). ');
$ax += cidrblock($address,'208.78.96.0/21','Rackspace (ASN-RKSP-061). ');
$ax += cidrblock($address,'209.20.64.0/19','Rackspace (ASN-RKSP-062). ');
$ax += cidrblock($address,'209.61.128.0/18','Rackspace (ASN-RKSP-063). ');
$ax += cidrblock($address,'209.114.32.0/19','Rackspace (ASN-RKSP-064). ');
$ax += cidrblock($address,'209.163.232.0/21','Rackspace (ASN-RKSP-065). ');
$ax += cidrblock($address,'209.163.244.0/22','Rackspace (ASN-RKSP-066). ');
$ax += cidrblock($address,'209.163.248.0/22','Rackspace (ASN-RKSP-067). ');
$ax += cidrblock($address,'209.216.104.0/21','Rackspace (ASN-RKSP-068). ');
$ax += cidrblock($address,'212.64.128.0/19','Rackspace (ASN-RKSP-069). ');
if ($hoster != 'www.googlealert.com'){$ax += cidrblock($address,'212.100.224.0/19','Rackspace (ASN-RKSP-070). ');}  //70d mod 71e
$ax += cidrblock($address,'216.18.144.0/21','Rackspace (ASN-RKSP-071). ');
$ax += cidrblock($address,'216.105.48.0/20','Rackspace (ASN-RKSP-072). ');
$ax += cidrblock($address,'216.110.32.0/20','Rackspace (ASN-RKSP-073). ');


//Pakistan Telecom AS44595
//Spam without end, huge blacklistings!

$ax += cidrblock($address,'39.40.0.0/13','Pakistan Telecom AS44595 (ASN-PkT-01). '); //70d
$ax += cidrblock($address,'39.48.0.0/12','Pakistan Telecom AS44595 (ASN-PkT-02). '); //70d
$ax += cidrblock($address,'59.103.0.0/16','Pakistan Telecom (Possible Interlace) AS44595 (ASN-PkT-03). '); //70d
$ax += cidrblock($address,'116.71.0.0/16','Pakistan Telecom AS44595 (ASN-PkT-04). '); //70d
$ax += cidrblock($address,'119.152.0.0/13','Pakistan Telecom AS44595 (ASN-PkT-05). '); //70d
$ax += cidrblock($address,'182.176.0.0/12','Pakistan Telecom AS44595 (ASN-PkT-06). '); //70d
$ax += cidrblock($address,'202.70.144.0/20','Pakistan Telecom AS44595 (ASN-PkT-07). '); //70d
$ax += cidrblock($address,'202.125.128.0/19','Pakistan Telecom AS44595 (ASN-PkT-08). '); //70d
$ax += cidrblock($address,'203.99.160.0/19','Pakistan Telecom AS44595 (ASN-PkT-09). '); //70d
$ax += cidrblock($address,'203.128.252.0/22','Pakistan Telecom AS44595 (ASN-PkT-10). '); //70d
$ax += cidrblock($address,'203.135.0.0/18','Pakistan Telecom (Heavy Interlace) AS44595 (ASN-PkT-11). '); //70d
$ax += cidrblock($address,'203.175.107.0/24','Pakistan Telecom AS44595 (ASN-PkT-11). '); //70d

//Kintiskton LLC, Mark Manager copyright check bot (abusive history)

$ax += cidrblock($address,'63.110.158.0/24','Kintiskton LLC (ASN-KINT-01). ');
$ax += cidrblock($address,'64.124.14.0/24','Kintiskton LLC (ASN-KINT-02). ');
$ax += cidrblock($address,'64.124.59.0/24','Kintiskton LLC (ASN-KINT-03). ');
$ax += cidrblock($address,'64.124.69.0/24','Kintiskton LLC (ASN-KINT-04). ');
//$ax += cidrblock($address,'65.192.0.0/16','Kintiskton LLC (ASN-KINT-05). '); //Removed 71c
$ax += cidrblock($address,'65.200.47.0/24','Kintiskton LLC (ASN-KINT-06). ');
$ax += cidrblock($address,'65.200.90.0/24','Kintiskton LLC (ASN-KINT-07). ');
$ax += cidrblock($address,'65.208.151.0/24','Kintiskton LLC (ASN-KINT-08). ');
$ax += cidrblock($address,'65.208.174.0/24','Kintiskton LLC (ASN-KINT-09). ');
$ax += cidrblock($address,'65.208.181.0/24','Kintiskton LLC (ASN-KINT-10). ');
$ax += cidrblock($address,'65.208.185.0/24','Kintiskton LLC (ASN-KINT-11). ');
$ax += cidrblock($address,'65.208.189.0/24','Kintiskton LLC (ASN-KINT-12). ');
$ax += cidrblock($address,'65.211.195.0/24','Kintiskton LLC (ASN-KINT-13). ');
$ax += cidrblock($address,'70.42.144.0/23','Kintiskton LLC (ASN-KINT-14). ');
$ax += cidrblock($address,'76.216.100.0/24','Kintiskton LLC (ASN-KINT-15). ');
$ax += cidrblock($address,'207.126.100.0/24','Kintiskton LLC (ASN-KINT-16). ');

//Limestone networks ASN 46475: Hosts hackforums.net

$ax += cidrblock($address,'63.143.32.0/19','Limestone Networks ASN46475 (ASN-LSN-01). ');
$ax += cidrblock($address,'64.31.0.0/18','Limestone Networks ASN46475 (ASN-LSN-02). ');
$ax += cidrblock($address,'69.162.64.0/18','Limestone Networks ASN46475 (ASN-LSN-03). ');
$ax += cidrblock($address,'74.63.192.0/18','Limestone Networks ASN46475 (ASN-LSN-04). ');
$ax += cidrblock($address,'208.115.192.0/18','Limestone Networks ASN46475 (ASN-LSN-05). ');
$ax += cidrblock($address,'216.144.240.0/20','Limestone Networks ASN46475 (ASN-LSN-06). ');
$ax += cidrblock($address,'216.245.192.0/19','Limestone Networks ASN46475 (ASN-LSN-07). ');

// Redstation Network
// ASN35662


$ax += cidrblock($address,'5.152.192.0/19','Redstation Limited, not an access provider ISP. (ASN-REDSTATION-0). '); //74d
$ax += cidrblock($address,'31.3.224.0/19','Redstation Limited, not an access provider ISP. (ASN-REDSTATION-1). '); //74d
$ax += cidrblock($address,'37.157.240.0/21','Redstation Limited, not an access provider ISP. (ASN-REDSTATION-2). '); //74d
$ax += cidrblock($address,'37.220.0.0/19','Redstation Limited, not an access provider ISP. (ASN-REDSTATION-3). '); //74d
$ax += cidrblock($address,'77.245.64.0/20','Redstation Limited, not an access provider ISP. (ASN-REDSTATION-4). '); //74d
$ax += cidrblock($address,'79.143.80.0/22','Redstation Limited, not an access provider ISP. (ASN-REDSTATION-5). '); //74d
$ax += cidrblock($address,'80.84.48.0/20','Redstation Limited, not an access provider ISP. (ASN-REDSTATION-6). '); //74d
$ax += cidrblock($address,'80.243.176.0/20','Redstation Limited, not an access provider ISP. (ASN-REDSTATION-7). '); //74d
$ax += cidrblock($address,'81.94.192.0/20','Redstation Limited, not an access provider ISP. (ASN-REDSTATION-8). '); //74d
$ax += cidrblock($address,'88.150.128.0/17','Redstation Limited, not an access provider ISP. (ASN-REDSTATION-9). '); //74d
$ax += cidrblock($address,'91.225.0.0/22','Redstation Limited, not an access provider ISP. (ASN-REDSTATION-10). '); //74d
$ax += cidrblock($address,'91.238.100.0/24','Redstation Limited, not an access provider ISP. (ASN-REDSTATION-11). '); //74d
$ax += cidrblock($address,'109.73.64.0/20','Redstation Limited, not an access provider ISP. (ASN-REDSTATION-12). '); //74d
$ax += cidrblock($address,'109.200.0.0/19','Redstation Limited, not an access provider ISP. (ASN-REDSTATION-13). '); //74d
$ax += cidrblock($address,'149.3.128.0/20','Redstation Limited, not an access provider ISP. (ASN-REDSTATION-14). '); //74d
$ax += cidrblock($address,'176.227.192.0/19','Redstation Limited, not an access provider ISP. (ASN-REDSTATION-15). '); //74d
$ax += cidrblock($address,'185.5.0.0/22','Redstation Limited, not an access provider ISP. (ASN-REDSTATION-16). '); //74d
$ax += cidrblock($address,'185.20.96.0/22','Redstation Limited, not an access provider ISP. (ASN-REDSTATION-17). '); //74d
$ax += cidrblock($address,'188.227.160.0/19','Redstation Limited, not an access provider ISP. (ASN-REDSTATION-18). '); //74d
$ax += cidrblock($address,'213.238.163.0/24','Redstation Limited, not an access provider ISP. (ASN-REDSTATION-19). '); //74d


// AFAS AnchorFree Inc IP Network ASN26642
// Listed 71h

$ax += cidrblock($address,'63.141.198.0/24','AnchorFree Inc ASN26642 (ASN-AF-01). ');
$ax += cidrblock($address,'74.115.0.0/21','AnchorFree Inc ASN26642 (ASN-AF-02). ');
$ax += cidrblock($address,'209.73.132.0/24','AnchorFree Inc ASN26642 (ASN-AF-03). ');
$ax += cidrblock($address,'216.172.135.0/24','AnchorFree Inc ASN26642 (ASN-AF-04). ');
$ax += cidrblock($address,'216.172.142.0/24','AnchorFree Inc ASN26642 (ASN-AF-05). ');

/// Rotten romainian network.

$ax += cidrblock($address,'89.36.232.0/22','Romainian network trying to hack user accounts (ASN-AS41011-01). '); //69b
$ax += cidrblock($address,'89.37.132.0/24','Romainian network trying to hack user accounts (ASN-AS41011-02). '); //69b
$ax += cidrblock($address,'89.41.172.0/23','Romainian network trying to hack user accounts (ASN-AS41011-03). '); //69b
$ax += cidrblock($address,'89.46.132.0/22','Romainian network trying to hack user accounts (ASN-AS41011-04). '); //69b
$ax += cidrblock($address,'93.113.36.0/23','Romainian network trying to hack user accounts (ASN-AS41011-05). '); //69b
$ax += cidrblock($address,'93.115.240.0/23','Romainian network trying to hack user accounts (ASN-AS41011-06). '); //69b
$ax += cidrblock($address,'188.208.32.0/23','Romainian network trying to hack user accounts (ASN-AS41011-07). '); //69b
$ax += cidrblock($address,'188.240.32.0/22','Romainian network trying to hack user accounts (ASN-AS41011-08). '); //69b
$ax += cidrblock($address,'46.108.128.0/21','Romainian network trying to hack user accounts (ASN-AS41011-09). '); //69b
$ax += cidrblock($address,'46.108.144.0/21','Romainian network trying to hack user accounts (ASN-AS41011-10). '); //69b
$ax += cidrblock($address,'46.108.240.0/21','Romainian network trying to hack user accounts (ASN-AS41011-11). '); //69b

// Swiftway / Botmaster Labs AS35017

$ax += cidrblock($address,'31.214.232.0/20','Swiftway / Botmaster Labs AS35017 (ASN-SFT-01). '); //71f
$ax += cidrblock($address,'37.1.200.0/20','Swiftway / Botmaster Labs AS35017 (ASN-SFT-02). '); //71f
$ax += cidrblock($address,'37.72.168.0/21','Swiftway / Botmaster Labs AS35017 (ASN-SFT-03). '); //71f
$ax += cidrblock($address,'46.21.144.0/20','Swiftway / Botmaster Labs AS35017 (ASN-SFT-04). '); //71f
$ax += cidrblock($address,'69.1.69.0/23','Swiftway / Botmaster Labs AS35017 (ASN-SFT-05). '); //71f
$ax += cidrblock($address,'91.195.234.0/23','Swiftway / Botmaster Labs AS35017 (ASN-SFT-06). '); //71f
$ax += cidrblock($address,'91.198.218.0/24','Swiftway / Botmaster Labs AS35017 (ASN-SFT-07). '); //71f
$ax += cidrblock($address,'93.89.23.0/24','Swiftway / Botmaster Labs AS35017 (ASN-SFT-08). '); //71f
$ax += cidrblock($address,'94.100.16.0/20','Swiftway / Botmaster Labs AS35017 (ASN-SFT-09). '); //71f
$ax += cidrblock($address,'149.154.158.0/24','Swiftway / Botmaster Labs AS35017 (ASN-SFT-10). '); //71f
$ax += cidrblock($address,'149.255.32.0/21','Swiftway / Botmaster Labs AS35017 (ASN-SFT-11). '); //71f
$ax += cidrblock($address,'158.255.213.0/24','Swiftway / Botmaster Labs AS35017 (ASN-SFT-12). '); //71f
$ax += cidrblock($address,'194.126.172.0/22','Swiftway / Botmaster Labs AS35017 (ASN-SFT-13). '); //71f
$ax += cidrblock($address,'195.242.152.0/23','Swiftway / Botmaster Labs AS35017 (ASN-SFT-14). '); //71f

// SoftLayer Technologies/The Planet/Everyones Internet Hostile & Spam Tolerant Networks
// (AS36351, AS36420, AS30315, AS13749, AS21844)

$ax += cidrblock($address,'12.96.160.0/21','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-001). '); //71
$ax += cidrblock($address,'12.156.0.0/21','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-002). '); //71
$ax += cidrblock($address,'46.16.184.0/21','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-003). '); //71
$ax += cidrblock($address,'50.116.16.0/20','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-004). '); //71
$ax += cidrblock($address,'64.5.32.0/19','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-005). '); //71
$ax += cidrblock($address,'64.46.160.0/19','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-006). '); //71
$ax += cidrblock($address,'64.246.0.0/18','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-007). '); //71
$ax += cidrblock($address,'66.28.25.0/24','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-008). '); //71
$ax += cidrblock($address,'66.28.26.0/24','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-009). '); //71
$ax += cidrblock($address,'66.28.110.0/23','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-010). '); //71
$ax += cidrblock($address,'66.28.113.0/24','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-011). '); //71
$ax += cidrblock($address,'66.45.59.0/24','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-012). '); //71
$ax += cidrblock($address,'66.45.86.0/23','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-013). '); //71
$ax += cidrblock($address,'66.45.118.0/23','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-014). '); //71
$ax += cidrblock($address,'66.98.128.0/17','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-015). '); //71
$ax += cidrblock($address,'66.179.2.0/23','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-016). '); //71
$ax += cidrblock($address,'66.179.68.0/23','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-017). '); //71
$ax += cidrblock($address,'66.228.48.0/21','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-018). '); //71
$ax += cidrblock($address,'66.228.112.0/20','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-019). '); //71
$ax += cidrblock($address,'66.250.65.0/24','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-020). '); //71
$ax += cidrblock($address,'67.15.0.0/16','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-021). '); //71
$ax += cidrblock($address,'67.18.0.0/15','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-022). '); //71
$ax += cidrblock($address,'67.213.208.0/20','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-023). '); //71
$ax += cidrblock($address,'67.228.0.0/16','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-024). '); //71
$ax += cidrblock($address,'68.169.32.0/22','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-025). '); //71
$ax += cidrblock($address,'68.169.36.0/23','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-026). '); //71
$ax += cidrblock($address,'69.4.224.0/20','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-027). '); //71
$ax += cidrblock($address,'69.41.224.0/19','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-028). '); //71
$ax += cidrblock($address,'69.56.128.0/17','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-029). '); //71
$ax += cidrblock($address,'69.57.128.0/19','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-030). '); //71
$ax += cidrblock($address,'69.93.0.0/16','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-031). '); //71
$ax += cidrblock($address,'69.164.192.0/20','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-032). '); //71
$ax += cidrblock($address,'70.84.0.0/14','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-033). '); //71
// The below signature is being held in reserve, the sub-units are the split blocks.
//$ax += cidrblock($address,'72.14.176.0/20','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-034). '); //71
$ax += cidrblock($address,'72.14.176.0/23','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-034.1). '); //73d
$ax += cidrblock($address,'72.14.179.0/24','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-034.2). '); //73d
$ax += cidrblock($address,'72.14.180.0/22','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-034.3). '); //73d
$ax += cidrblock($address,'72.14.184.0/21','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-034.4). '); //73d
$ax += cidrblock($address,'74.52.0.0/14','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-035). '); //71
$ax += cidrblock($address,'74.86.0.0/16','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-036). '); //71
$ax += cidrblock($address,'75.125.0.0/16','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-037). '); //71
$ax += cidrblock($address,'75.126.0.0/16','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-038). '); //71
$ax += cidrblock($address,'81.95.144.0/20','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-039). '); //71
$ax += cidrblock($address,'96.47.32.0/23','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-040). '); //71
$ax += cidrblock($address,'96.47.40.0/21','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-041). '); //71
$ax += cidrblock($address,'96.126.112.0/20','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-042). '); //71
$ax += cidrblock($address,'149.75.192.0/18','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-043). '); //71
$ax += cidrblock($address,'155.65.0.0/19','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-044). '); //71
$ax += cidrblock($address,'173.192.0.0/18','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-045). '); //71
$ax += cidrblock($address,'173.192.128.0/18','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-046). '); //71
$ax += cidrblock($address,'173.192.192.0/19','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-047). '); //71
$ax += cidrblock($address,'173.192.224.0/20','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-048). '); //71
$ax += cidrblock($address,'173.192.240.0/22','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-049). '); //71
$ax += cidrblock($address,'173.192.244.0/23','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-050). '); //71
$ax += cidrblock($address,'173.193.0.0/18','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-051). '); //71
$ax += cidrblock($address,'173.193.192.0/18','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-052). '); //71
$ax += cidrblock($address,'173.255.192.0/19','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-053). '); //71
//$ax += cidrblock($address,'173.255.240.0/20','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-054). '); //71 Duplicate of ASN-HE1-029 dropped 74d
$ax += cidrblock($address,'174.36.0.0/15','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-055). '); //71
$ax += cidrblock($address,'174.120.0.0/14','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-056). '); //71
$ax += cidrblock($address,'174.132.0.0/15','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-057). '); //71
$ax += cidrblock($address,'184.172.0.0/15','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-058). '); //71
$ax += cidrblock($address,'189.1.160.0/20','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-059). '); //71
$ax += cidrblock($address,'198.22.121.0/24','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-060). '); //71
$ax += cidrblock($address,'198.58.96.0/19','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-061). '); //71
$ax += cidrblock($address,'199.233.181.0/24','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-062). '); //71
$ax += cidrblock($address,'200.58.126.0/24','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-063). '); //71
$ax += cidrblock($address,'202.162.242.0/23','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-064). '); //71
$ax += cidrblock($address,'202.162.244.0/24','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-065). '); //71
$ax += cidrblock($address,'204.42.10.0/24','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-066). '); //71
$ax += cidrblock($address,'204.42.47.0/24','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-067). '); //71
$ax += cidrblock($address,'206.217.192.0/22','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-068). '); //71
$ax += cidrblock($address,'206.217.200.0/21','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-069). '); //71
$ax += cidrblock($address,'206.217.208.0/20','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-070). '); //71
$ax += cidrblock($address,'207.44.128.0/17','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-071). '); //71
$ax += cidrblock($address,'207.218.192.0/18','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-072). '); //71
$ax += cidrblock($address,'208.43.0.0/16','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-073). '); //71
$ax += cidrblock($address,'208.101.0.0/18','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-074). '); //71
$ax += cidrblock($address,'209.44.52.0/23','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-075). '); //71
$ax += cidrblock($address,'209.62.0.0/17','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-076). '); //71
$ax += cidrblock($address,'209.85.0.0/17','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-077). '); //71
$ax += cidrblock($address,'209.223.234.0/23','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-078). '); //71
$ax += cidrblock($address,'209.236.64.0/24','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-079). '); //71
$ax += cidrblock($address,'216.12.192.0/19','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-080). '); //71
$ax += cidrblock($address,'216.40.192.0/18','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-081). '); //71
$ax += cidrblock($address,'216.75.232.0/24','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-082). '); //71
$ax += cidrblock($address,'216.88.76.0/23','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-083). '); //71
$ax += cidrblock($address,'216.88.79.0/24','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-084). '); //71
$ax += cidrblock($address,'216.88.118.0/23','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-085). '); //71
$ax += cidrblock($address,'216.90.204.0/23','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-086). '); //71
$ax += cidrblock($address,'216.127.64.0/19','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-087). '); //71
$ax += cidrblock($address,'216.163.148.0/22','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-088). '); //71
$ax += cidrblock($address,'216.185.96.0/19','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-089). '); //71
$ax += cidrblock($address,'216.234.224.0/19','Softlayer/ThePlanet/Everyone/Reach. (ASN-SLTP-090). '); //71

//Bypasses for (ASN-SLTP)

if ((inmatch($whyblockout,'(ASN-SLTP-','')) && ($ax > 0)){
	$zbamz = 0;
	$zbamz += inmatch($lcuseragent,'showyoubot','ShowyouBot bypass. '); //72b
	$zbamz += inmatch($lcuseragent,'disqus','Disqus bypass. '); //74a
	$zbamz += inmatch($useragent,'Feedspot http://www.feedspot.com','Feedspot bypass. '); //74c
	$zbamz += inmatch($useragent,'Superfeedr bot/2.0','Superfeedr bypass. '); //74c
	$zbamz += inmatch($useragent,'Feedbot','Feedbot bypass. '); //74c	
	if ($zbamz > 0){$ax -= 1;}
}

// Prolexic Technologies DDoS mitigation services.
// Attempted DoSing of:
// SpambotSecurity.com from IP 114.141.72.50 on 2012-12-09 @2230 hours MST
// ( AS32787 )

$ax += cidrblock($address,'72.52.0.0/18','Prolexic Technologies. (ASN-PLX-001). '); //72a
$ax += cidrblock($address,'93.191.168.0/21','Prolexic Technologies. (ASN-PLX-002). '); //72a
$ax += cidrblock($address,'109.69.136.0/21','Prolexic Technologies. (ASN-PLX-003). '); //72a
$ax += cidrblock($address,'114.141.72.0/21','Prolexic Technologies. (ASN-PLX-004). '); //72a
$ax += cidrblock($address,'155.136.0.0/16','Prolexic Technologies. (ASN-PLX-005). '); //72a
$ax += cidrblock($address,'209.200.128.0/18','Prolexic Technologies. (ASN-PLX-006). '); //72a

// Portlane Networks AB
// Huge set of anonymous VPN and Proxy spamming services!
// ( as42708 )

$ax += cidrblock($address,'5.133.192.0/19','Portlane Networks AB. (ASN-PTL-001). '); //72b
$ax += cidrblock($address,'5.153.239.0/24','Portlane Networks AB. (ASN-PTL-002). '); //72b
$ax += cidrblock($address,'5.198.248.0/21','Portlane Networks AB. (ASN-PTL-003). '); //72b
$ax += cidrblock($address,'5.249.160.0/21','Portlane Networks AB. (ASN-PTL-004). '); //72b
$ax += cidrblock($address,'5.254.128.0/19','Portlane Networks AB. (ASN-PTL-005). '); //72b
$ax += cidrblock($address,'46.246.0.0/17','Portlane Networks AB. (ASN-PTL-006). '); //72b
$ax += cidrblock($address,'80.67.0.0/20','Portlane Networks AB. (ASN-PTL-007). '); //72b
$ax += cidrblock($address,'91.213.246.0/24','Portlane Networks AB. (ASN-PTL-008). '); //72b
$ax += cidrblock($address,'91.217.189.0/24','Portlane Networks AB. (ASN-PTL-009). '); //72b
$ax += cidrblock($address,'91.236.116.0/24','Portlane Networks AB. (ASN-PTL-010). '); //72b
$ax += cidrblock($address,'91.240.64.0/22','Portlane Networks AB. (ASN-PTL-011). '); //72b
$ax += cidrblock($address,'178.73.192.0/18','Portlane Networks AB. (ASN-PTL-012). '); //72b
$ax += cidrblock($address,'185.5.44.0/22','Portlane Networks AB. (ASN-PTL-013). '); //72b
$ax += cidrblock($address,'188.126.64.0/19','Portlane Networks AB. (ASN-PTL-014). '); //72b
$ax += cidrblock($address,'193.105.134.0/24','Portlane Networks AB. (ASN-PTL-015). '); //72b
$ax += cidrblock($address,'193.180.125.0/24','Portlane Networks AB. (ASN-PTL-015). '); //72b
$ax += cidrblock($address,'195.191.144.0/23','Portlane Networks AB. (ASN-PTL-017). '); //72b

// WEBEXXPURTS Servers and Colocation. Not an access provider ISP.
// ( as57972 )

$ax += cidrblock($address,'5.34.246.0/23','WEBEXXPURTS. (ASN-WXX-001). '); //72b
$ax += cidrblock($address,'37.72.184.0/22','WEBEXXPURTS. (ASN-WXX-002). '); //72b
$ax += cidrblock($address,'46.29.252.0/22','WEBEXXPURTS. (ASN-WXX-003). '); //72b
$ax += cidrblock($address,'130.185.156.0/22','WEBEXXPURTS. (ASN-WXX-004). '); //72b
$ax += cidrblock($address,'151.237.189.0/22','WEBEXXPURTS, some interlacing. (ASN-WXX-005). '); //72b
$ax += cidrblock($address,'176.61.140.0/22','WEBEXXPURTS. (ASN-WXX-006). '); //72b
$ax += cidrblock($address,'206.246.84.0/22','WEBEXXPURTS. (ASN-WXX-007). '); //72b
$ax += cidrblock($address,'207.199.144.0/22','WEBEXXPURTS. (ASN-WXX-008). '); //72b
$ax += cidrblock($address,'207.199.156.0/22','WEBEXXPURTS. (ASN-WXX-009). '); //72b
$ax += cidrblock($address,'207.199.188.0/22','WEBEXXPURTS. (ASN-WXX-010). '); //72b
$ax += cidrblock($address,'209.147.72.0/23','WEBEXXPURTS. (ASN-WXX-011). '); //72b
$ax += cidrblock($address,'216.107.22.0/23','WEBEXXPURTS. (ASN-WXX-012). '); //72b
$ax += cidrblock($address,'216.107.41.0/24','WEBEXXPURTS. (ASN-WXX-013). '); //72b
$ax += cidrblock($address,'216.155.4.0/22','WEBEXXPURTS, some interlacing. (ASN-WXX-014). '); //72b


// Hurricane Electric, not an access provider ISP.
// Too many infected and hostile servers.
// ( as6939 )

$ax += cidrblock($address,'27.50.32.0/21','Hurricane Electric (ASN-HE1-001). '); //73b
$ax += cidrblock($address,'31.148.219.0/24','Hurricane Electric (ASN-HE1-002). '); //73b
$ax += cidrblock($address,'37.16.72.0/21','Hurricane Electric (ASN-HE1-003). '); //73b
$ax += cidrblock($address,'50.116.0.0/20','Hurricane Electric (ASN-HE1-004). '); //73b
$ax += cidrblock($address,'64.62.128.0/17','Hurricane Electric (ASN-HE1-005). '); //73b
$ax += cidrblock($address,'64.71.128.0/18','Hurricane Electric (ASN-HE1-006). '); //73b
$ax += cidrblock($address,'65.19.128.0/18','Hurricane Electric (ASN-HE1-007). '); //73b
$ax += cidrblock($address,'65.49.0.0/17','Hurricane Electric (ASN-HE1-008). '); //73b
$ax += cidrblock($address,'66.160.128.0/18','Hurricane Electric (ASN-HE1-009). '); //73b
$ax += cidrblock($address,'66.175.216.0/21','Hurricane Electric (ASN-HE1-010). '); //73b
$ax += cidrblock($address,'66.178.176.0/20','Hurricane Electric (ASN-HE1-011). '); //73b
$ax += cidrblock($address,'66.220.0.0/19','Hurricane Electric (ASN-HE1-012). '); //73b
$ax += cidrblock($address,'67.43.55.0/24','Hurricane Electric (ASN-HE1-013). '); //73b
$ax += cidrblock($address,'68.64.168.0/22','Hurricane Electric (ASN-HE1-014). '); //73b
$ax += cidrblock($address,'70.35.16.0/21','Hurricane Electric (ASN-HE1-015). '); //73b
$ax += cidrblock($address,'67.43.55.0/24','Hurricane Electric (ASN-HE1-016). '); //73b
$ax += cidrblock($address,'72.52.64.0/18','Hurricane Electric (ASN-HE1-017). '); //73b
$ax += cidrblock($address,'74.82.0.0/18','Hurricane Electric (ASN-HE1-018). '); //73b
$ax += cidrblock($address,'74.121.104.0/22','Hurricane Electric (ASN-HE1-019). '); //73b
$ax += cidrblock($address,'74.207.240.0/20','Hurricane Electric (ASN-HE1-020). '); //73b
$ax += cidrblock($address,'96.126.96.0/21','Hurricane Electric (ASN-HE1-021). '); //73b
$ax += cidrblock($address,'103.22.244.0/22','Hurricane Electric (ASN-HE1-022). '); //73b
$ax += cidrblock($address,'135.0.128.0/17','Hurricane Electric (ASN-HE1-023). '); //73b
$ax += cidrblock($address,'148.51.0.0/16','Hurricane Electric (ASN-HE1-024). '); //73b
$ax += cidrblock($address,'156.39.0.0/16','Hurricane Electric (ASN-HE1-025). '); //73b
$ax += cidrblock($address,'173.46.80.0/20','Hurricane Electric (ASN-HE1-026). '); //73b
$ax += cidrblock($address,'173.230.144.0/20','Hurricane Electric (ASN-HE1-027). '); //73b
$ax += cidrblock($address,'173.255.208.0/20','Hurricane Electric (ASN-HE1-028). '); //73b
$ax += cidrblock($address,'173.255.240.0/20','Hurricane Electric (ASN-HE1-029). '); //73b
$ax += cidrblock($address,'184.75.240.0/22','Hurricane Electric (ASN-HE1-030). '); //73b
$ax += cidrblock($address,'184.104.0.0/15','Hurricane Electric (ASN-HE1-031). '); //73b
$ax += cidrblock($address,'192.52.69.0/24','Hurricane Electric (ASN-HE1-032). '); //73b
$ax += cidrblock($address,'192.69.224.0/20','Hurricane Electric, Interlaced (ASN-HE1-033). '); //73b
$ax += cidrblock($address,'192.88.99.0/24','Hurricane Electric (ASN-HE1-034). '); //73b
$ax += cidrblock($address,'192.132.94.0/24','Hurricane Electric (ASN-HE1-035). '); //73b
$ax += cidrblock($address,'192.136.112.0/24','Hurricane Electric (ASN-HE1-036). '); //73b
$ax += cidrblock($address,'192.155.80.0/21','Hurricane Electric (ASN-HE1-037). '); //73b
$ax += cidrblock($address,'192.156.200.0/24','Hurricane Electric (ASN-HE1-038). '); //73b
$ax += cidrblock($address,'192.171.110.0/24','Hurricane Electric (ASN-HE1-039). '); //73b
$ax += cidrblock($address,'193.142.62.0/24','Hurricane Electric (ASN-HE1-040). '); //73b
$ax += cidrblock($address,'198.74.48.0/22','Hurricane Electric (ASN-HE1-041). '); //73b
$ax += cidrblock($address,'192.88.99.0/24','Hurricane Electric (ASN-HE1-042). '); //73b
$ax += cidrblock($address,'198.102.73.0/24','Hurricane Electric (ASN-HE1-043). '); //73b
$ax += cidrblock($address,'198.167.232.0/21','Hurricane Electric, Interlaced (ASN-HE1-044). '); //73b
$ax += cidrblock($address,'199.4.150.0/24','Hurricane Electric (ASN-HE1-045). '); //73b
$ax += cidrblock($address,'199.16.197.0/24','Hurricane Electric (ASN-HE1-046). '); //73b
$ax += cidrblock($address,'199.26.178.0/24','Hurricane Electric (ASN-HE1-047). '); //73b
$ax += cidrblock($address,'199.30.48.0/21','Hurricane Electric (ASN-HE1-048). '); //73b
$ax += cidrblock($address,'199.36.72.0/21','Hurricane Electric (ASN-HE1-049). '); //73b
$ax += cidrblock($address,'199.79.202.0/24','Hurricane Electric (ASN-HE1-050). '); //73b
$ax += cidrblock($address,'199.83.48.0/24','Hurricane Electric (ASN-HE1-051). '); //73b
$ax += cidrblock($address,'199.88.158.0/24','Hurricane Electric (ASN-HE1-052). '); //73b
$ax += cidrblock($address,'199.114.240.0/21','Hurricane Electric (ASN-HE1-053). '); //73b
$ax += cidrblock($address,'199.115.144.0/22','Hurricane Electric (ASN-HE1-054). '); //73b
$ax += cidrblock($address,'199.115.178.0/24','Hurricane Electric (ASN-HE1-055). '); //73b
$ax += cidrblock($address,'199.119.88.0/21','Hurricane Electric (ASN-HE1-056). '); //73b
$ax += cidrblock($address,'199.167.132.0/22','Hurricane Electric (ASN-HE1-057). '); //73b
$ax += cidrblock($address,'199.192.152.0/21','Hurricane Electric (ASN-HE1-058). '); //73b
$ax += cidrblock($address,'199.193.64.0/21','Hurricane Electric (ASN-HE1-059). '); //73b
$ax += cidrblock($address,'199.233.90.0/24','Hurricane Electric (ASN-HE1-060). '); //73b
$ax += cidrblock($address,'199.233.198.0/23','Hurricane Electric (ASN-HE1-061). '); //73b
$ax += cidrblock($address,'199.245.105.0/24','Hurricane Electric (ASN-HE1-063). '); //73b
$ax += cidrblock($address,'202.9.83.0/24','Hurricane Electric (ASN-HE1-063). '); //73b
$ax += cidrblock($address,'203.23.194.0/24','Hurricane Electric (ASN-HE1-064). '); //73b
$ax += cidrblock($address,'203.99.142.0/24','Hurricane Electric (ASN-HE1-065). '); //73b
$ax += cidrblock($address,'203.142.14.0/23','Hurricane Electric (ASN-HE1-066). '); //73b
$ax += cidrblock($address,'203.142.26.0/24','Hurricane Electric (ASN-HE1-067). '); //73b
$ax += cidrblock($address,'204.140.21.0/20','Hurricane Electric, Interlaced (ASN-HE1-068). '); //73b
$ax += cidrblock($address,'205.159.239.0/24','Hurricane Electric (ASN-HE1-069). '); //73b
$ax += cidrblock($address,'205.166.121.0/24','Hurricane Electric (ASN-HE1-070). '); //73b
$ax += cidrblock($address,'206.108.49.0/21','Hurricane Electric (ASN-HE1-071). '); //73b
$ax += cidrblock($address,'206.144.144.0/20','Hurricane Electric (ASN-HE1-072). '); //73b
$ax += cidrblock($address,'207.45.69.0/24','Hurricane Electric (ASN-HE1-073). '); //73b
$ax += cidrblock($address,'207.89.0.0/17','Hurricane Electric (ASN-HE1-074). '); //73b
$ax += cidrblock($address,'208.78.35.0/24','Hurricane Electric (ASN-HE1-075). '); //73b
$ax += cidrblock($address,'208.81.165.0/24','Hurricane Electric (ASN-HE1-076). '); //73b
$ax += cidrblock($address,'208.142.248.0/21','Hurricane Electric (ASN-HE1-077). '); //73b
$ax += cidrblock($address,'209.51.160.0/19','Hurricane Electric (ASN-HE1-078). '); //73b
$ax += cidrblock($address,'209.150.160.0/19','Hurricane Electric (ASN-HE1-079). '); //73b
$ax += cidrblock($address,'209.209.22.0/19','Hurricane Electric, Interlaced (ASN-HE1-080). '); //73b
$ax += cidrblock($address,'216.66.0.0/19','Hurricane Electric (ASN-HE1-081). '); //73b
$ax += cidrblock($address,'216.66.0.0/17','Hurricane Electric, Interlaced (ASN-HE1-082). '); //73b
$ax += cidrblock($address,'216.75.229.0/24','Hurricane Electric (ASN-HE1-083). '); //73b
$ax += cidrblock($address,'216.75.236.0/23','Hurricane Electric (ASN-HE1-084). '); //73b
$ax += cidrblock($address,'216.151.156.0/23','Hurricane Electric (ASN-HE1-085). '); //73b
$ax += cidrblock($address,'216.171.201.0/19','Hurricane Electric, Interlaced (ASN-HE1-086). '); //73b
$ax += cidrblock($address,'216.218.128.0/17','Hurricane Electric (ASN-HE1-087). '); //73b
$ax += cidrblock($address,'216.224.64.0/19','Hurricane Electric (ASN-HE1-088). '); //73b
$ax += cidrblock($address,'216.224.64.0/21','Hurricane Electric (ASN-HE1-089). '); //73b

//Bypasses for (ASN-HE1-008) (mod 74d)

if (((inmatch($whyblockout,'(ASN-HE1-)','')) || (inmatch($whyblockout,'(ASN-HE1-007)',''))) && ($ax > 0)){
	$zbamz = 0;
	$zbamz += rmatch($lcuseragent,'.getpebble.com','Nice enough to ask bypass. '); //74e
    $zbamz += inmatch($useragent,'Feedspot http://www.feedspot.com',' Feedspot bypass. ' ); //74c
	$zbamz += inmatch($useragent,'Feedly',' Feedly bypass. ' ); //74c
	if ($zbamz > 0){$ax -= 1;}
}

// Virpus Networks, not an access provider ISP.
// AS32875

$ax += cidrblock($address,'50.115.160.0/20','Virpus Networks (ASN-VP-01). '); //73b
$ax += cidrblock($address,'50.115.170.0/22','Virpus Networks (ASN-VP-02). '); //73b
$ax += cidrblock($address,'173.0.48.0/20','Virpus Networks (ASN-VP-03). '); //73b
$ax += cidrblock($address,'198.167.136.0/21','Virpus Networks (ASN-VP-04). '); //73b
$ax += cidrblock($address,'198.167.136.0/23','Virpus Networks (ASN-VP-05). '); //73b
$ax += cidrblock($address,'198.175.124.0/22','Virpus Networks (ASN-VP-06). '); //73b
$ax += cidrblock($address,'198.175.127.0/24','Virpus Networks (ASN-VP-07). '); //73b
$ax += cidrblock($address,'199.119.224.0/22','Virpus Networks (ASN-VP-08). '); //73b
$ax += cidrblock($address,'199.180.128.0/21','Virpus Networks (ASN-VP-09). '); //73b
$ax += cidrblock($address,'208.89.208.0/21','Virpus Networks (ASN-VP-10). '); //73b

// Eonix, not an access provider ISP.
// Many improper ASN records. Known attack vector.
// AS30693

$ax += cidrblock($address,'50.2.0.0/15','EONIX Network (ASN-EONIX-01). '); //73c
$ax += cidrblock($address,'69.4.80.0/21','EONIX Network (ASN-EONIX-02). '); //73c
$ax += cidrblock($address,'69.58.0.0/21','EONIX Network (ASN-EONIX-03). '); //73c
$ax += cidrblock($address,'75.75.224.0/19','EONIX Network (ASN-EONIX-04). '); //73c
$ax += cidrblock($address,'173.44.128.0/17','EONIX Network (ASN-EONIX-05). '); //73c
$ax += cidrblock($address,'192.157.60.0/22','EONIX Network (ASN-EONIX-06). '); //73c
$ax += cidrblock($address,'198.154.84.0/22','EONIX Network (ASN-EONIX-07). '); //73c
$ax += cidrblock($address,'204.14.0.0/21','EONIX Network (ASN-EONIX-08). '); //73c
$ax += cidrblock($address,'206.214.64.0/19','EONIX Network (ASN-EONIX-09). '); //73c
$ax += cidrblock($address,'208.89.216.0/21','EONIX Network (ASN-EONIX-10). '); //73c
$ax += cidrblock($address,'208.93.144.0/21','EONIX Network (ASN-EONIX-11). '); //73c

// Pegasus Web Technology / Fortress ITX
// Not an access provider.
// AS25653, AS56400

$ax += cidrblock($address,'50.60.0.0/15','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-0). '); //74a updated
$ax += cidrblock($address,'63.140.0.0/21','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-1). '); //74a updated
$ax += cidrblock($address,'65.98.0.0/17','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-2). '); //74a updated
$ax += cidrblock($address,'65.181.64.0/18','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-3). '); //74a updated
$ax += cidrblock($address,'69.57.160.0/19','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-4). '); //74a updated
$ax += cidrblock($address,'69.72.128.0/17','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-5). '); //74a updated
$ax += cidrblock($address,'69.168.232.0/24','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-6). '); //74a updated
$ax += cidrblock($address,'69.194.169.0/24','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-7). '); //74a updated
$ax += cidrblock($address,'69.194.192.0/23','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-8). '); //74a updated
$ax += cidrblock($address,'69.194.196.0/24','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-9). '); //74a updated
$ax += cidrblock($address,'69.194.198.0/23','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-10). '); //74a updated
$ax += cidrblock($address,'69.194.200.0/24','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-11). '); //74a updated
$ax += cidrblock($address,'69.194.202.0/24','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-12). '); //74a updated
$ax += cidrblock($address,'69.194.204.0/23','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-13). '); //74a updated
$ax += cidrblock($address,'100.42.51.0/24','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-14). '); //74a updated
$ax += cidrblock($address,'100.42.52.0/22','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-15). '); //74a updated
$ax += cidrblock($address,'100.42.56.0/22','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-16). '); //74a updated
$ax += cidrblock($address,'100.42.60.0/23','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-17). '); //74a updated
$ax += cidrblock($address,'100.42.62.0/24','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-18). '); //74a updated
$ax += cidrblock($address,'109.169.62.0/23','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-19). '); //74a updated
$ax += cidrblock($address,'109.169.72.0/23','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-20). '); //74a updated
$ax += cidrblock($address,'109.169.80.0/23','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-21). '); //74a updated
$ax += cidrblock($address,'142.0.128.0/20','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-22). '); //74a updated
$ax += cidrblock($address,'142.4.96.0/19','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-23). '); //74a updated
$ax += cidrblock($address,'192.55.203.0/24','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-24). '); //74a updated
$ax += cidrblock($address,'192.74.224.0/19','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-25). '); //74a updated
$ax += cidrblock($address,'198.2.192.0/18','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-26). '); //74a updated
$ax += cidrblock($address,'198.47.96.0/24','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-27). '); //74a updated
$ax += cidrblock($address,'198.200.32.0/19','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-28). '); //74a updated
$ax += cidrblock($address,'199.180.100.0/22','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-29). '); //74a updated
$ax += cidrblock($address,'199.188.104.0/21','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-30). '); //74a updated
$ax += cidrblock($address,'206.209.48.0/20','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-31). '); //74a updated
$ax += cidrblock($address,'208.116.0.0/18','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-32). '); //74a updated
$ax += cidrblock($address,'209.21.66.0/23','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-33). '); //74a updated
$ax += cidrblock($address,'209.21.68.0/23','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-34). '); //74a updated
$ax += cidrblock($address,'209.21.72.0/24','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-35). '); //74a updated
$ax += cidrblock($address,'209.21.78.0/23','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-36). '); //74a updated
$ax += cidrblock($address,'209.21.92.0/24','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-37). '); //74a updated
$ax += cidrblock($address,'209.140.128.0/18','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-38). '); //74a updated
$ax += cidrblock($address,'212.38.160.0/21','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-39). '); //74a updated
$ax += cidrblock($address,'216.67.224.0/19','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-40). '); //74a updated
$ax += cidrblock($address,'216.74.96.0/19','Pegasus Web Technologies / Fortress ITX, Not an access provider  (ASN-PWEBFITX-41). '); //74a updated


// Steadfast DNS
// Not an access provider.
// AS32748

$ax += cidrblock($address,'50.31.0.0/17','Steadfast DNS (ASN-SFDNS-0). ');
$ax += cidrblock($address,'64.17.32.0/20','Steadfast DNS (ASN-SFDNS-1). ');
$ax += cidrblock($address,'64.88.128.0/19','Steadfast DNS (ASN-SFDNS-2). ');
$ax += cidrblock($address,'66.103.16.0/20','Steadfast DNS (ASN-SFDNS-3). ');
$ax += cidrblock($address,'66.111.192.0/18','Steadfast DNS (ASN-SFDNS-4). ');
$ax += cidrblock($address,'67.20.48.0/20','Steadfast DNS (ASN-SFDNS-5). ');
$ax += cidrblock($address,'67.202.64.0/18','Steadfast DNS (ASN-SFDNS-6). ');
$ax += cidrblock($address,'67.210.240.0/20','Steadfast DNS (ASN-SFDNS-7). ');
$ax += cidrblock($address,'69.162.128.0/18','Steadfast DNS (ASN-SFDNS-8). ');
$ax += cidrblock($address,'72.44.80.0/20','Steadfast DNS (ASN-SFDNS-9). ');
$ax += cidrblock($address,'74.120.120.0/22','Steadfast DNS (ASN-SFDNS-10). ');
$ax += cidrblock($address,'173.249.144.0/20','Steadfast DNS (ASN-SFDNS-11). ');
$ax += cidrblock($address,'181.189.64.0/18','Steadfast DNS (ASN-SFDNS-12). ');
$ax += cidrblock($address,'198.23.48.0/20','Steadfast DNS (ASN-SFDNS-13). ');
$ax += cidrblock($address,'198.37.144.0/20','Steadfast DNS (ASN-SFDNS-14). ');
$ax += cidrblock($address,'199.38.180.0/22','Steadfast DNS (ASN-SFDNS-15). ');
$ax += cidrblock($address,'199.48.252.0/22','Steadfast DNS (ASN-SFDNS-16). ');
$ax += cidrblock($address,'204.238.229.0/24','Steadfast DNS (ASN-SFDNS-17). ');
$ax += cidrblock($address,'208.66.168.0/21','Steadfast DNS (ASN-SFDNS-18). ');
$ax += cidrblock($address,'208.100.0.0/18','Steadfast DNS (ASN-SFDNS-19). ');
$ax += cidrblock($address,'208.117.0.0/18','Steadfast DNS (ASN-SFDNS-20). ');
$ax += cidrblock($address,'209.152.160.0/19','Steadfast DNS (ASN-SFDNS-21). ');
$ax += cidrblock($address,'209.177.144.0/20','Steadfast DNS (ASN-SFDNS-22). ');
$ax += cidrblock($address,'216.86.144.0/20','Steadfast DNS (ASN-SFDNS-23). ');

// CyberBunker
// Not an access provider, and willingly participates in hosting web attacks.
// AS34109 and AS51088

$ax += cidrblock($address,'5.44.72.0/21','CyberBunker ASN (ASN-CYBERBUNKER-0). '); //73f
$ax += cidrblock($address,'31.134.200.0/21','CyberBunker ASN (ASN-CYBERBUNKER-1). '); //73f
$ax += cidrblock($address,'37.148.192.0/21','CyberBunker ASN (ASN-CYBERBUNKER-2). '); //73f
$ax += cidrblock($address,'46.174.134.0/23','CyberBunker ASN (ASN-CYBERBUNKER-3). '); //73f
$ax += cidrblock($address,'46.244.0.0/17','CyberBunker ASN (ASN-CYBERBUNKER-4). '); //73f
$ax += cidrblock($address,'81.30.64.0/20','CyberBunker ASN (ASN-CYBERBUNKER-5). '); //73f
$ax += cidrblock($address,'84.22.96.0/19','CyberBunker ASN (ASN-CYBERBUNKER-6). '); //73f
$ax += cidrblock($address,'84.243.192.0/18','CyberBunker ASN (ASN-CYBERBUNKER-7). '); //73f
$ax += cidrblock($address,'91.194.6.0/23','CyberBunker ASN (ASN-CYBERBUNKER-8). '); //73f
$ax += cidrblock($address,'91.209.12.0/24','CyberBunker ASN (ASN-CYBERBUNKER-9). '); //73f
$ax += cidrblock($address,'91.213.13.0/24','CyberBunker ASN (ASN-CYBERBUNKER-10). '); //73f
$ax += cidrblock($address,'91.224.164.0/23','CyberBunker ASN (ASN-CYBERBUNKER-11). '); //73f
$ax += cidrblock($address,'91.227.114.0/24','CyberBunker ASN (ASN-CYBERBUNKER-12). '); //73f
$ax += cidrblock($address,'91.230.33.0/24','CyberBunker ASN (ASN-CYBERBUNKER-13). '); //73f
$ax += cidrblock($address,'91.230.34.0/23','CyberBunker ASN (ASN-CYBERBUNKER-14). '); //73f
$ax += cidrblock($address,'91.233.52.0/23','CyberBunker ASN (ASN-CYBERBUNKER-15). '); //73f
$ax += cidrblock($address,'91.233.224.0/23','CyberBunker ASN (ASN-CYBERBUNKER-16). '); //73f
$ax += cidrblock($address,'91.234.203.0/24','CyberBunker ASN (ASN-CYBERBUNKER-17). '); //73f
$ax += cidrblock($address,'91.235.174.0/24','CyberBunker ASN (ASN-CYBERBUNKER-18). '); //73f
$ax += cidrblock($address,'93.93.120.0/21','CyberBunker ASN (ASN-CYBERBUNKER-19). '); //73f
$ax += cidrblock($address,'176.117.56.0/21','CyberBunker ASN (ASN-CYBERBUNKER-20). '); //73f
$ax += cidrblock($address,'178.238.96.0/24','CyberBunker ASN (ASN-CYBERBUNKER-21). '); //73f
$ax += cidrblock($address,'178.249.152.0/21','CyberBunker ASN (ASN-CYBERBUNKER-22). '); //73f
$ax += cidrblock($address,'178.250.16.0/21','CyberBunker ASN (ASN-CYBERBUNKER-23). '); //73f
$ax += cidrblock($address,'192.166.96.0/22','CyberBunker ASN (ASN-CYBERBUNKER-24). '); //73f
$ax += cidrblock($address,'193.108.238.0/24','CyberBunker ASN (ASN-CYBERBUNKER-25). '); //73f
$ax += cidrblock($address,'193.169.108.0/23','CyberBunker ASN (ASN-CYBERBUNKER-26). '); //73f
$ax += cidrblock($address,'194.145.194.0/23','CyberBunker ASN (ASN-CYBERBUNKER-27). '); //73f
$ax += cidrblock($address,'195.12.60.0/22','CyberBunker ASN (ASN-CYBERBUNKER-28). '); //73f
$ax += cidrblock($address,'195.88.202.0/23','CyberBunker ASN (ASN-CYBERBUNKER-29). '); //73f
$ax += cidrblock($address,'195.95.244.0/22','CyberBunker ASN (ASN-CYBERBUNKER-30). '); //73f
$ax += cidrblock($address,'195.95.248.0/23','CyberBunker ASN (ASN-CYBERBUNKER-31). '); //73f
$ax += cidrblock($address,'205.189.71.0/24','CyberBunker ASN (ASN-CYBERBUNKER-32). '); //73f
$ax += cidrblock($address,'205.189.72.0/23','CyberBunker ASN (ASN-CYBERBUNKER-33). '); //73f
$ax += cidrblock($address,'217.67.224.0/19','CyberBunker ASN (ASN-CYBERBUNKER-34). '); //73f
$ax += cidrblock($address,'250.250.250.0/24','CyberBunker ASN (ASN-CYBERBUNKER-35). '); //73f

// PIN-AS
// Small local access provider for Leningrad, HUGE spam-slinger.
// AS44050

$ax += cidrblock($address,'5.8.0.0/21','ASN pinspb.ru (ASN-PINAS-0). '); //73f
$ax += cidrblock($address,'5.8.16.0/20','ASN pinspb.ru (ASN-PINAS-1). '); //73f
$ax += cidrblock($address,'5.8.32.0/20','ASN pinspb.ru (ASN-PINAS-2). '); //73f
$ax += cidrblock($address,'5.8.64.0/18','ASN pinspb.ru (ASN-PINAS-3). '); //73f
$ax += cidrblock($address,'5.45.64.0/18','ASN pinspb.ru (ASN-PINAS-4). '); //73f
$ax += cidrblock($address,'5.78.96.0/19','ASN pinspb.ru (ASN-PINAS-5). '); //73f
$ax += cidrblock($address,'5.101.0.0/16','ASN pinspb.ru (ASN-PINAS-6). '); //73f
$ax += cidrblock($address,'5.188.0.0/15','ASN pinspb.ru (ASN-PINAS-7). '); //73f
$ax += cidrblock($address,'10.72.0.0/16','ASN pinspb.ru (ASN-PINAS-8). '); //73f
$ax += cidrblock($address,'31.44.184.0/24','ASN pinspb.ru (ASN-PINAS-9). '); //73f
$ax += cidrblock($address,'31.184.192.0/19','ASN pinspb.ru (ASN-PINAS-10). '); //73f
$ax += cidrblock($address,'31.184.224.0/23','ASN pinspb.ru (ASN-PINAS-11). '); //73f
$ax += cidrblock($address,'31.184.226.0/24','ASN pinspb.ru (ASN-PINAS-12). '); //73f
$ax += cidrblock($address,'31.184.228.0/23','ASN pinspb.ru (ASN-PINAS-13). '); //73f
$ax += cidrblock($address,'31.184.236.0/24','ASN pinspb.ru (ASN-PINAS-14). '); //73f
$ax += cidrblock($address,'31.184.238.0/23','ASN pinspb.ru (ASN-PINAS-15). '); //73f
$ax += cidrblock($address,'31.184.241.0/24','ASN pinspb.ru (ASN-PINAS-16). '); //73f
$ax += cidrblock($address,'31.184.243.0/24','ASN pinspb.ru (ASN-PINAS-17). '); //73f
$ax += cidrblock($address,'37.9.49.0/24','ASN pinspb.ru (ASN-PINAS-18). '); //73f
$ax += cidrblock($address,'37.9.52.0/23','ASN pinspb.ru (ASN-PINAS-19). '); //73f
$ax += cidrblock($address,'37.9.54.0/24','ASN pinspb.ru (ASN-PINAS-20). '); //73f
$ax += cidrblock($address,'37.9.60.0/23','ASN pinspb.ru (ASN-PINAS-21). '); //73f
$ax += cidrblock($address,'37.139.0.0/19','ASN pinspb.ru (ASN-PINAS-22). '); //73f
$ax += cidrblock($address,'37.139.51.0/24','ASN pinspb.ru (ASN-PINAS-23). '); //73f
$ax += cidrblock($address,'37.139.54.0/23','ASN pinspb.ru (ASN-PINAS-24). '); //73f
$ax += cidrblock($address,'46.161.8.0/22','ASN pinspb.ru (ASN-PINAS-25). '); //73f
$ax += cidrblock($address,'46.161.16.0/21','ASN pinspb.ru (ASN-PINAS-26). '); //73f
$ax += cidrblock($address,'46.161.24.0/22','ASN pinspb.ru (ASN-PINAS-27). '); //73f
$ax += cidrblock($address,'46.161.28.0/23','ASN pinspb.ru (ASN-PINAS-28). '); //73f
$ax += cidrblock($address,'46.161.32.0/21','ASN pinspb.ru (ASN-PINAS-29). '); //73f
$ax += cidrblock($address,'46.161.42.0/24','ASN pinspb.ru (ASN-PINAS-30). '); //73f
$ax += cidrblock($address,'46.161.45.0/24','ASN pinspb.ru (ASN-PINAS-31). '); //73f
$ax += cidrblock($address,'46.161.56.0/21','ASN pinspb.ru (ASN-PINAS-32). '); //73f
$ax += cidrblock($address,'79.133.96.0/20','ASN pinspb.ru (ASN-PINAS-33). '); //73f
$ax += cidrblock($address,'91.201.64.0/24','ASN pinspb.ru (ASN-PINAS-34). '); //73f
$ax += cidrblock($address,'91.220.131.0/24','ASN pinspb.ru (ASN-PINAS-35). '); //73f
$ax += cidrblock($address,'91.243.32.0/19','ASN pinspb.ru (ASN-PINAS-36). '); //73f
$ax += cidrblock($address,'91.243.80.0/20','ASN pinspb.ru (ASN-PINAS-37). '); //73f
$ax += cidrblock($address,'91.243.128.0/19','ASN pinspb.ru (ASN-PINAS-38). '); //73f
$ax += cidrblock($address,'91.243.176.0/20','ASN pinspb.ru (ASN-PINAS-39). '); //73f
$ax += cidrblock($address,'91.244.192.0/20','ASN pinspb.ru (ASN-PINAS-40). '); //73f
$ax += cidrblock($address,'95.85.64.0/18','ASN pinspb.ru (ASN-PINAS-41). '); //73f
$ax += cidrblock($address,'95.181.192.0/18','ASN pinspb.ru (ASN-PINAS-42). '); //73f
$ax += cidrblock($address,'95.215.0.0/22','ASN pinspb.ru (ASN-PINAS-43). '); //73f
$ax += cidrblock($address,'146.185.128.0/18','ASN pinspb.ru (ASN-PINAS-44). '); //73f
$ax += cidrblock($address,'146.185.217.0/24','ASN pinspb.ru (ASN-PINAS-45). '); //73f
$ax += cidrblock($address,'146.185.222.0/24','ASN pinspb.ru (ASN-PINAS-46). '); //73f
$ax += cidrblock($address,'146.185.224.0/21','ASN pinspb.ru (ASN-PINAS-47). '); //73f
$ax += cidrblock($address,'146.185.242.0/24','ASN pinspb.ru (ASN-PINAS-48). '); //73f
$ax += cidrblock($address,'146.185.244.0/23','ASN pinspb.ru (ASN-PINAS-49). '); //73f
$ax += cidrblock($address,'146.185.246.0/24','ASN pinspb.ru (ASN-PINAS-50). '); //73f
$ax += cidrblock($address,'146.185.248.0/24','ASN pinspb.ru (ASN-PINAS-51). '); //73f
$ax += cidrblock($address,'146.185.250.0/23','ASN pinspb.ru (ASN-PINAS-52). '); //73f
$ax += cidrblock($address,'188.143.128.0/17','ASN pinspb.ru (ASN-PINAS-53). '); //73f
$ax += cidrblock($address,'193.107.216.0/22','ASN pinspb.ru (ASN-PINAS-54). '); //73f
$ax += cidrblock($address,'194.11.16.0/24','ASN pinspb.ru (ASN-PINAS-55). '); //73f
$ax += cidrblock($address,'194.11.20.0/23','ASN pinspb.ru (ASN-PINAS-56). '); //73f
$ax += cidrblock($address,'195.2.240.0/23','ASN pinspb.ru (ASN-PINAS-57). '); //73f
$ax += cidrblock($address,'195.22.152.0/23','ASN pinspb.ru (ASN-PINAS-58). '); //73f
$ax += cidrblock($address,'195.211.124.0/22','ASN pinspb.ru (ASN-PINAS-59). '); //73f

//  OVH Networks
//  Not an access provider, allows rampant abuse, hosts badware/bad services.
//  AS16276

$ax += cidrblock($address,'5.39.0.0/17','OVH Networks (ASN-OVH-0). '); //74d
$ax += cidrblock($address,'5.135.0.0/16','OVH Networks (ASN-OVH-1). '); //74d
$ax += cidrblock($address,'8.7.244.0/24','OVH Networks (ASN-OVH-2). '); //74d
$ax += cidrblock($address,'8.18.128.0/24','OVH Networks (ASN-OVH-3). '); //74d
$ax += cidrblock($address,'8.18.136.0/21','OVH Networks (ASN-OVH-4). '); //74d
$ax += cidrblock($address,'8.18.172.0/24','OVH Networks (ASN-OVH-5). '); //74d
$ax += cidrblock($address,'8.20.110.0/24','OVH Networks (ASN-OVH-6). '); //74d
$ax += cidrblock($address,'8.21.41.0/24','OVH Networks (ASN-OVH-7). '); //74d
$ax += cidrblock($address,'8.24.8.0/21','OVH Networks (ASN-OVH-8). '); //74d
$ax += cidrblock($address,'8.26.94.0/24','OVH Networks (ASN-OVH-9). '); //74d
$ax += cidrblock($address,'8.29.224.0/24','OVH Networks (ASN-OVH-10). '); //74d
$ax += cidrblock($address,'8.30.208.0/21','OVH Networks (ASN-OVH-11). '); //74d
$ax += cidrblock($address,'8.33.96.0/21','OVH Networks (ASN-OVH-12). '); //74d
$ax += cidrblock($address,'8.33.128.0/21','OVH Networks (ASN-OVH-13). '); //74d
$ax += cidrblock($address,'8.33.136.0/23','OVH Networks (ASN-OVH-14). '); //74d
$ax += cidrblock($address,'31.201.128.0/17','OVH Networks (ASN-OVH-15). '); //74d
$ax += cidrblock($address,'37.49.226.0/23','OVH Networks (ASN-OVH-16). '); //74d
$ax += cidrblock($address,'37.59.0.0/16','OVH Networks (ASN-OVH-17). '); //74d
$ax += cidrblock($address,'37.60.48.0/20','OVH Networks (ASN-OVH-18). '); //74d
$ax += cidrblock($address,'37.187.0.0/16','OVH Networks (ASN-OVH-19). '); //74d
$ax += cidrblock($address,'37.222.0.0/15','OVH Networks (ASN-OVH-20). '); //74d
$ax += cidrblock($address,'46.105.0.0/16','OVH Networks (ASN-OVH-21). '); //74d
$ax += cidrblock($address,'62.245.0.0/19','OVH Networks (ASN-OVH-22). '); //74d
$ax += cidrblock($address,'87.98.128.0/17','OVH Networks (ASN-OVH-23). '); //74d
$ax += cidrblock($address,'87.253.232.0/24','OVH Networks (ASN-OVH-24). '); //74d
$ax += cidrblock($address,'91.90.88.0/21','OVH Networks (ASN-OVH-25). '); //74d
$ax += cidrblock($address,'91.121.0.0/16','OVH Networks (ASN-OVH-26). '); //74d
$ax += cidrblock($address,'91.218.204.0/22','OVH Networks (ASN-OVH-27). '); //74d
$ax += cidrblock($address,'94.23.0.0/16','OVH Networks (ASN-OVH-28). '); //74d
$ax += cidrblock($address,'103.5.12.0/22','OVH Networks (ASN-OVH-29). '); //74d
$ax += cidrblock($address,'109.190.0.0/16','OVH Networks (ASN-OVH-30). '); //74d
$ax += cidrblock($address,'142.4.192.0/19','OVH Networks (ASN-OVH-31). '); //74d
$ax += cidrblock($address,'176.31.0.0/16','OVH Networks (ASN-OVH-32). '); //74d
$ax += cidrblock($address,'178.32.0.0/15','OVH Networks (ASN-OVH-33). '); //74d
$ax += cidrblock($address,'178.236.224.0/20','OVH Networks (ASN-OVH-34). '); //74d
$ax += cidrblock($address,'185.7.240.0/22','OVH Networks (ASN-OVH-35). '); //74d
$ax += cidrblock($address,'185.10.17.0/24','OVH Networks (ASN-OVH-36). '); //74d
$ax += cidrblock($address,'185.12.32.0/23','OVH Networks (ASN-OVH-37). '); //74d
$ax += cidrblock($address,'188.165.0.0/16','OVH Networks (ASN-OVH-38). '); //74d
$ax += cidrblock($address,'192.95.0.0/18','OVH Networks (ASN-OVH-39). '); //74d
$ax += cidrblock($address,'192.99.0.0/16','OVH Networks (ASN-OVH-40). '); //74d
$ax += cidrblock($address,'193.84.187.0/24','OVH Networks (ASN-OVH-41). '); //74d
$ax += cidrblock($address,'193.104.19.0/24','OVH Networks (ASN-OVH-42). '); //74d
$ax += cidrblock($address,'193.104.56.0/24','OVH Networks (ASN-OVH-43). '); //74d
$ax += cidrblock($address,'193.109.63.0/24','OVH Networks (ASN-OVH-44). '); //74d
$ax += cidrblock($address,'193.200.52.0/23','OVH Networks (ASN-OVH-45). '); //74d
$ax += cidrblock($address,'194.50.82.0/24','OVH Networks (ASN-OVH-46). '); //74d
$ax += cidrblock($address,'195.43.138.0/24','OVH Networks (ASN-OVH-47). '); //74d
$ax += cidrblock($address,'195.60.164.0/23','OVH Networks (ASN-OVH-48). '); //74d
$ax += cidrblock($address,'195.110.30.0/23','OVH Networks (ASN-OVH-49). '); //74d
$ax += cidrblock($address,'195.246.232.0/23','OVH Networks (ASN-OVH-50). '); //74d
$ax += cidrblock($address,'195.246.254.0/23','OVH Networks (ASN-OVH-51). '); //74d
$ax += cidrblock($address,'198.27.64.0/18','OVH Networks (ASN-OVH-52). '); //74d
$ax += cidrblock($address,'198.50.128.0/17','OVH Networks (ASN-OVH-53). '); //74d
$ax += cidrblock($address,'198.100.144.0/20','OVH Networks (ASN-OVH-54). '); //74d
$ax += cidrblock($address,'198.245.48.0/20','OVH Networks (ASN-OVH-55). '); //74d
$ax += cidrblock($address,'213.186.32.0/19','OVH Networks (ASN-OVH-56). '); //74d
$ax += cidrblock($address,'213.251.128.0/18','OVH Networks (ASN-OVH-57). '); //74d

// Redstation & IOMart
// Hosting Death by Captcha .com and .eu CAPTCHA cracking services.
// AS20860, AS35662

$ax += cidrblock($address,'5.77.32.0/19','Redstation / IOMart (ASN-REDIOM-0). '); //74b
$ax += cidrblock($address,'5.133.176.0/21','Redstation / IOMart (ASN-REDIOM-1). '); //74b
$ax += cidrblock($address,'5.152.192.0/19','Redstation / IOMart (ASN-REDIOM-2). '); //74b
$ax += cidrblock($address,'31.3.224.0/19','Redstation / IOMart (ASN-REDIOM-3). '); //74b
$ax += cidrblock($address,'37.157.240.0/21','Redstation / IOMart (ASN-REDIOM-4). '); //74b
$ax += cidrblock($address,'37.220.0.0/19','Redstation / IOMart (ASN-REDIOM-5). '); //74b
$ax += cidrblock($address,'37.235.124.0/22','Redstation / IOMart (ASN-REDIOM-6). '); //74b
$ax += cidrblock($address,'62.128.192.0/19','Redstation / IOMart (ASN-REDIOM-7). '); //74b
$ax += cidrblock($address,'62.233.64.0/18','Redstation / IOMart (ASN-REDIOM-8). '); //74b
$ax += cidrblock($address,'77.245.64.0/20','Redstation / IOMart (ASN-REDIOM-9). '); //74b
$ax += cidrblock($address,'78.129.128.0/17','Redstation / IOMart (ASN-REDIOM-10). '); //74b
$ax += cidrblock($address,'79.143.80.0/22','Redstation / IOMart (ASN-REDIOM-11). '); //74b
$ax += cidrblock($address,'80.84.48.0/20','Redstation / IOMart (ASN-REDIOM-12). '); //74b
$ax += cidrblock($address,'80.243.176.0/20','Redstation / IOMart (ASN-REDIOM-13). '); //74b
$ax += cidrblock($address,'81.94.192.0/20','Redstation / IOMart (ASN-REDIOM-14). '); //74b
$ax += cidrblock($address,'82.145.32.0/19','Redstation / IOMart (ASN-REDIOM-15). '); //74b
$ax += cidrblock($address,'83.142.224.0/21','Redstation / IOMart (ASN-REDIOM-16). '); //74b
$ax += cidrblock($address,'83.223.216.0/22','Redstation / IOMart (ASN-REDIOM-17). '); //74b
$ax += cidrblock($address,'84.22.160.0/19','Redstation / IOMart (ASN-REDIOM-18). '); //74b
$ax += cidrblock($address,'85.232.32.0/19','Redstation / IOMart (ASN-REDIOM-19). '); //74b
$ax += cidrblock($address,'87.117.192.0/18','Redstation / IOMart (ASN-REDIOM-20). '); //74b
$ax += cidrblock($address,'89.106.224.0/21','Redstation / IOMart (ASN-REDIOM-21). '); //74b
$ax += cidrblock($address,'89.207.168.0/21','Redstation / IOMart (ASN-REDIOM-22). '); //74b
$ax += cidrblock($address,'91.199.151.0/24','Redstation / IOMart (ASN-REDIOM-23). '); //74b
$ax += cidrblock($address,'91.207.220.0/23','Redstation / IOMart (ASN-REDIOM-24). '); //74b
$ax += cidrblock($address,'91.212.93.0/24','Redstation / IOMart (ASN-REDIOM-25). '); //74b
$ax += cidrblock($address,'91.215.180.0/22','Redstation / IOMart (ASN-REDIOM-26). '); //74b
$ax += cidrblock($address,'91.225.0.0/22','Redstation / IOMart (ASN-REDIOM-27). '); //74b
$ax += cidrblock($address,'91.238.100.0/24','Redstation / IOMart (ASN-REDIOM-28). '); //74b
$ax += cidrblock($address,'91.245.218.0/24','Redstation / IOMart (ASN-REDIOM-29). '); //74b
$ax += cidrblock($address,'95.129.104.0/21','Redstation / IOMart (ASN-REDIOM-30). '); //74b
$ax += cidrblock($address,'95.154.192.0/18','Redstation / IOMart (ASN-REDIOM-31). '); //74b
$ax += cidrblock($address,'109.73.64.0/20','Redstation / IOMart (ASN-REDIOM-32). '); //74b
$ax += cidrblock($address,'109.75.160.0/21','Redstation / IOMart (ASN-REDIOM-33). '); //74b
$ax += cidrblock($address,'109.169.0.0/18','Redstation / IOMart (ASN-REDIOM-34). '); //74b
$ax += cidrblock($address,'109.169.64.0/19','Redstation / IOMart (ASN-REDIOM-35). '); //74b
$ax += cidrblock($address,'109.200.0.0/19','Redstation / IOMart (ASN-REDIOM-36). '); //74b
$ax += cidrblock($address,'130.185.144.0/21','Redstation / IOMart (ASN-REDIOM-37). '); //74b
$ax += cidrblock($address,'130.185.160.0/21','Redstation / IOMart (ASN-REDIOM-38). '); //74b
$ax += cidrblock($address,'141.0.192.0/21','Redstation / IOMart (ASN-REDIOM-39). '); //74b
$ax += cidrblock($address,'149.3.128.0/20','Redstation / IOMart (ASN-REDIOM-40). '); //74b
$ax += cidrblock($address,'149.255.96.0/22','Redstation / IOMart (ASN-REDIOM-41). '); //74b
$ax += cidrblock($address,'149.255.108.0/22','Redstation / IOMart (ASN-REDIOM-42). '); //74b
$ax += cidrblock($address,'159.255.208.0/21','Redstation / IOMart (ASN-REDIOM-43). '); //74b
$ax += cidrblock($address,'176.227.192.0/19','Redstation / IOMart (ASN-REDIOM-44). '); //74b
$ax += cidrblock($address,'182.54.237.0/24','Redstation / IOMart (ASN-REDIOM-45). '); //74b
$ax += cidrblock($address,'185.5.0.0/22','Redstation / IOMart (ASN-REDIOM-46). '); //74b
$ax += cidrblock($address,'185.17.148.0/22','Redstation / IOMart (ASN-REDIOM-47). '); //74b
$ax += cidrblock($address,'185.19.16.0/22','Redstation / IOMart (ASN-REDIOM-48). '); //74b
$ax += cidrblock($address,'188.227.160.0/19','Redstation / IOMart (ASN-REDIOM-49). '); //74b
$ax += cidrblock($address,'193.200.98.0/23','Redstation / IOMart (ASN-REDIOM-50). '); //74b
$ax += cidrblock($address,'193.201.200.0/23','Redstation / IOMart (ASN-REDIOM-51). '); //74b
$ax += cidrblock($address,'193.227.244.0/23','Redstation / IOMart (ASN-REDIOM-52). '); //74b
$ax += cidrblock($address,'194.1.147.0/24','Redstation / IOMart (ASN-REDIOM-53). '); //74b
$ax += cidrblock($address,'194.1.150.0/24','Redstation / IOMart (ASN-REDIOM-54). '); //74b
$ax += cidrblock($address,'194.24.188.0/23','Redstation / IOMart (ASN-REDIOM-55). '); //74b
$ax += cidrblock($address,'195.62.10.0/23','Redstation / IOMart (ASN-REDIOM-56). '); //74b
$ax += cidrblock($address,'195.177.192.0/23','Redstation / IOMart (ASN-REDIOM-57). '); //74b
$ax += cidrblock($address,'206.187.52.0/22','Redstation / IOMart (ASN-REDIOM-58). '); //74b
$ax += cidrblock($address,'212.38.160.0/19','Redstation / IOMart (ASN-REDIOM-59). '); //74b
$ax += cidrblock($address,'212.84.160.0/19','Redstation / IOMart (ASN-REDIOM-60). '); //74b
$ax += cidrblock($address,'213.238.163.0/24','Redstation / IOMart (ASN-REDIOM-61). '); //74b
$ax += cidrblock($address,'217.26.232.0/21','Redstation / IOMart (ASN-REDIOM-62). '); //74b
$ax += cidrblock($address,'217.77.176.0/20','Redstation / IOMart (ASN-REDIOM-63). '); //74b
$ax += cidrblock($address,'217.147.80.0/20','Redstation / IOMart (ASN-REDIOM-64). '); //74b


// Bytemark Anonymous Proxies
// AS35425

$ax += cidrblock($address,'5.153.224.0/21','Bytemark Anonymous Proxies (ASN-BYTEMARK-0). '); //74b
$ax += cidrblock($address,'46.43.0.0/18','Bytemark Anonymous Proxies (ASN-BYTEMARK-1). '); //74b
$ax += cidrblock($address,'80.68.80.0/20','Bytemark Anonymous Proxies (ASN-BYTEMARK-2). '); //74b
$ax += cidrblock($address,'89.16.160.0/19','Bytemark Anonymous Proxies (ASN-BYTEMARK-3). '); //74b
$ax += cidrblock($address,'91.223.58.0/24','Bytemark Anonymous Proxies (ASN-BYTEMARK-4). '); //74b
$ax += cidrblock($address,'212.110.160.0/19','Bytemark Anonymous Proxies (ASN-BYTEMARK-5). '); //74b
$ax += cidrblock($address,'213.138.96.0/19','Bytemark Anonymous Proxies (ASN-BYTEMARK-6). '); //74b

// Plus Server AG
// AS8972

$ax += cidrblock($address,'62.75.128.0/17','Plus Server, not an access provider (ASN-PLSSRV-0). '); //74b
$ax += cidrblock($address,'80.86.80.0/20','Plus Server, not an access provider (ASN-PLSSRV-1). '); //74b
$ax += cidrblock($address,'85.25.0.0/16','Plus Server, not an access provider (ASN-PLSSRV-2). '); //74b
$ax += cidrblock($address,'188.138.0.0/17','Plus Server, not an access provider (ASN-PLSSRV-3). '); //74b
$ax += cidrblock($address,'217.118.16.0/20','Plus Server, not an access provider (ASN-PLSSRV-4). '); //74b
$ax += cidrblock($address,'217.172.160.0/19','Plus Server, not an access provider (ASN-PLSSRV-5). '); //74b

// TrendMicro
// AS16880

$ax += cidrblock($address,'66.180.80.0/20','Trend Micro. Follows their users around, and attempts to get into restricted / private parts of websites. Privacy risk & Replay Attack (ASN-TRENDM-0). '); //74c
$ax += cidrblock($address,'149.2.139.0/24','Trend Micro. Follows their users around, and attempts to get into restricted / private parts of websites. Privacy risk & Replay Attack (ASN-TRENDM-1). '); //74c
$ax += cidrblock($address,'150.70.0.0/16','Trend Micro. Follows their users around, and attempts to get into restricted / private parts of websites. Privacy risk & Replay Attack (ASN-TRENDM-2). '); //74c
$ax += cidrblock($address,'216.99.128.0/20','Trend Micro. Follows their users around, and attempts to get into restricted / private parts of websites. Privacy risk & Replay Attack (ASN-TRENDM-3). '); //74c
$ax += cidrblock($address,'216.104.0.0/19','Trend Micro. Follows their users around, and attempts to get into restricted / private parts of websites. Privacy risk & Replay Attack (ASN-TRENDM-4). '); //74c

// Hetzner Online AG
// AS24940

$ax += cidrblock($address,'5.9.0.0/16','Hetzner (ASN-HETZ-0). '); //74c
$ax += cidrblock($address,'46.4.0.0/16','Hetzner (ASN-HETZ-1). '); //74c
$ax += cidrblock($address,'78.46.0.0/15','Hetzner (ASN-HETZ-2). '); //74c
$ax += cidrblock($address,'85.10.192.0/18','Hetzner (ASN-HETZ-3). '); //74c
$ax += cidrblock($address,'88.198.0.0/16','Hetzner (ASN-HETZ-4). '); //74c
$ax += cidrblock($address,'91.220.49.0/24','Hetzner (ASN-HETZ-5). '); //74c
$ax += cidrblock($address,'91.233.8.0/22','Hetzner (ASN-HETZ-6). '); //74c
$ax += cidrblock($address,'136.243.0.0/16','Hetzner (ASN-HETZ-7). '); //74c
$ax += cidrblock($address,'138.201.0.0/16','Hetzner (ASN-HETZ-8). '); //74c
$ax += cidrblock($address,'144.76.0.0/16','Hetzner (ASN-HETZ-9). '); //74c
$ax += cidrblock($address,'148.251.0.0/16','Hetzner (ASN-HETZ-10). '); //74c
$ax += cidrblock($address,'176.9.0.0/16','Hetzner (ASN-HETZ-11). '); //74c
$ax += cidrblock($address,'176.102.168.0/21','Hetzner (ASN-HETZ-12). '); //74c
$ax += cidrblock($address,'178.63.0.0/16','Hetzner (ASN-HETZ-13). '); //74c
$ax += cidrblock($address,'185.12.64.0/22','Hetzner (ASN-HETZ-14). '); //74c
$ax += cidrblock($address,'188.40.0.0/16','Hetzner (ASN-HETZ-15). '); //74c
$ax += cidrblock($address,'193.25.170.0/23','Hetzner (ASN-HETZ-16). '); //74c
$ax += cidrblock($address,'193.28.90.0/24','Hetzner (ASN-HETZ-17). '); //74c
$ax += cidrblock($address,'193.110.6.0/23','Hetzner (ASN-HETZ-18). '); //74c
$ax += cidrblock($address,'193.223.77.0/24','Hetzner (ASN-HETZ-19). '); //74c
$ax += cidrblock($address,'194.42.180.0/22','Hetzner (ASN-HETZ-20). '); //74c
$ax += cidrblock($address,'194.42.184.0/22','Hetzner (ASN-HETZ-21). '); //74c
$ax += cidrblock($address,'194.145.226.0/24','Hetzner (ASN-HETZ-22). '); //74c
$ax += cidrblock($address,'195.13.45.0/24','Hetzner (ASN-HETZ-23). '); //74c
$ax += cidrblock($address,'197.242.84.0/22','Hetzner (ASN-HETZ-24). '); //74c
$ax += cidrblock($address,'213.133.96.0/19','Hetzner (ASN-HETZ-25). '); //74c
$ax += cidrblock($address,'213.239.192.0/18','Hetzner (ASN-HETZ-26). '); //74c

// ServerStack, Inc.
// AS46652

$ax += cidrblock($address,'37.139.0.0/21','ServerStack, Inc. Not an access provider ISP. (ASN-SERVERSTACK-0). '); //74d
$ax += cidrblock($address,'69.55.48.0/20','ServerStack, Inc. Not an access provider ISP. (ASN-SERVERSTACK-1). '); //74d
$ax += cidrblock($address,'82.196.0.0/20','Digital Ocean, Inc. Not an access provider ISP. (ASN-SERVERSTACK-2). '); //74d
$ax += cidrblock($address,'141.0.168.0/21','ServerStack, Inc. Not an access provider ISP. (ASN-SERVERSTACK-3). '); //74d
$ax += cidrblock($address,'185.14.184.0/22','Digital Ocean, Inc. Not an access provider ISP. (ASN-SERVERSTACK-4). '); //74d
$ax += cidrblock($address,'192.34.56.0/21','Digital Ocean, Inc. Not an access provider ISP. (ASN-SERVERSTACK-5). '); //74d
$ax += cidrblock($address,'192.81.208.0/20','Digital Ocean, Inc. Not an access provider ISP. (ASN-SERVERSTACK-6). '); //74d
$ax += cidrblock($address,'192.241.128.0/20','Digital Ocean, Inc. Not an access provider ISP. (ASN-SERVERSTACK-7). '); //74d
$ax += cidrblock($address,'198.199.64.0/20','Digital Ocean, Inc. Not an access provider ISP. (ASN-SERVERSTACK-8). '); //74d
$ax += cidrblock($address,'198.199.80.0/21','Digital Ocean, Inc. Not an access provider ISP. (ASN-SERVERSTACK-9). '); //74d
$ax += cidrblock($address,'198.199.88.0/22','Digital Ocean, Inc. Not an access provider ISP. (ASN-SERVERSTACK-10). '); //74d
$ax += cidrblock($address,'198.199.120.0/21','Digital Ocean, Inc. Not an access provider ISP. (ASN-SERVERSTACK-11). '); //74d
$ax += cidrblock($address,'198.211.96.0/19','Digital Ocean, Inc. Not an access provider ISP. (ASN-SERVERSTACK-12). '); //74d
$ax += cidrblock($address,'208.68.36.0/22','Digital Ocean, Inc. Not an access provider ISP. (ASN-SERVERSTACK-13). '); //74d

// Root SA
// AS5577

$ax += cidrblock($address,'31.184.232.0/23','Root SA http://sitevet.com/db/asn/AS5577 (ASN-ROOTSA-0). ');
$ax += cidrblock($address,'31.184.244.0/23','Root SA http://sitevet.com/db/asn/AS5577 (ASN-ROOTSA-1). ');
$ax += cidrblock($address,'31.220.29.0/24','Root SA http://sitevet.com/db/asn/AS5577 (ASN-ROOTSA-2). ');
$ax += cidrblock($address,'37.114.43.0/24','Root SA http://sitevet.com/db/asn/AS5577 (ASN-ROOTSA-3). ');
$ax += cidrblock($address,'62.122.74.0/23','Root SA http://sitevet.com/db/asn/AS5577 (ASN-ROOTSA-4). ');
$ax += cidrblock($address,'83.243.8.0/21','Root SA http://sitevet.com/db/asn/AS5577 (ASN-ROOTSA-5). ');
$ax += cidrblock($address,'85.121.2.0/24','Root SA http://sitevet.com/db/asn/AS5577 (ASN-ROOTSA-6). ');
$ax += cidrblock($address,'91.220.84.0/24','Root SA http://sitevet.com/db/asn/AS5577 (ASN-ROOTSA-7). ');
$ax += cidrblock($address,'93.170.132.0/23','Root SA http://sitevet.com/db/asn/AS5577 (ASN-ROOTSA-8). ');
$ax += cidrblock($address,'93.186.79.0/24','Root SA http://sitevet.com/db/asn/AS5577 (ASN-ROOTSA-9). ');
$ax += cidrblock($address,'94.242.192.0/18','Root SA http://sitevet.com/db/asn/AS5577 (ASN-ROOTSA-10). ');
$ax += cidrblock($address,'185.5.45.0/24','Root SA http://sitevet.com/db/asn/AS5577 (ASN-ROOTSA-11). ');
$ax += cidrblock($address,'188.42.0.0/16','Root SA http://sitevet.com/db/asn/AS5577 (ASN-ROOTSA-12). ');
$ax += cidrblock($address,'195.24.72.0/21','Root SA http://sitevet.com/db/asn/AS5577 (ASN-ROOTSA-13). ');
$ax += cidrblock($address,'195.26.4.0/23','Root SA http://sitevet.com/db/asn/AS5577 (ASN-ROOTSA-14). ');
$ax += cidrblock($address,'212.114.56.0/24','Root SA http://sitevet.com/db/asn/AS5577 (ASN-ROOTSA-15). ');
$ax += cidrblock($address,'212.117.160.0/19','Root SA http://sitevet.com/db/asn/AS5577 (ASN-ROOTSA-16). ');

// XEEX network.
// AS27524

$ax += cidrblock($address,"8.3.210.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-0). "); //74d repaired 75b
$ax += cidrblock($address,"12.179.248.0/22","Xeex communications, not an access provider, AS27524 (ASN-XEEX-1). "); //74d repaired 75b
$ax += cidrblock($address,"38.64.68.0/22","Xeex communications, not an access provider, AS27524 (ASN-XEEX-2). "); //74d repaired 75b
$ax += cidrblock($address,"50.7.128.0/19","Xeex communications, not an access provider, AS27524 (ASN-XEEX-3). "); //74d repaired 75b
$ax += cidrblock($address,"63.216.76.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-4). "); //74d repaired 75b
$ax += cidrblock($address,"63.216.246.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-5). "); //74d repaired 75b
$ax += cidrblock($address,"63.217.27.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-6). "); //74d repaired 75b
$ax += cidrblock($address,"63.218.20.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-7). "); //74d repaired 75b
$ax += cidrblock($address,"63.219.21.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-8). "); //74d repaired 75b
$ax += cidrblock($address,"63.220.57.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-9). "); //74d repaired 75b
$ax += cidrblock($address,"63.221.5.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-10). "); //74d repaired 75b
$ax += cidrblock($address,"63.221.232.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-11). "); //74d repaired 75b
$ax += cidrblock($address,"64.145.80.0/20","Xeex communications, not an access provider, AS27524 (ASN-XEEX-12). "); //74d repaired 75b
$ax += cidrblock($address,"64.156.175.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-13). "); //74d repaired 75b
$ax += cidrblock($address,"66.17.156.0/23","Xeex communications, not an access provider, AS27524 (ASN-XEEX-14). "); //74d repaired 75b
$ax += cidrblock($address,"66.172.60.0/23","Xeex communications, not an access provider, AS27524 (ASN-XEEX-15). "); //74d repaired 75b
$ax += cidrblock($address,"66.227.12.0/22","Xeex communications, not an access provider, AS27524 (ASN-XEEX-16). "); //74d repaired 75b
$ax += cidrblock($address,"67.220.64.0/20","Xeex communications, not an access provider, AS27524 (ASN-XEEX-17). "); //74d repaired 75b
$ax += cidrblock($address,"68.64.160.0/20","Xeex communications, not an access provider, AS27524 (ASN-XEEX-18). "); //74d repaired 75b
$ax += cidrblock($address,"69.26.160.0/19","Xeex communications, not an access provider, AS27524 (ASN-XEEX-19). "); //74d repaired 75b
$ax += cidrblock($address,"72.13.16.0/20","Xeex communications, not an access provider, AS27524 (ASN-XEEX-20). "); //74d repaired 75b
$ax += cidrblock($address,"72.20.63.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-21). "); //74d repaired 75b
$ax += cidrblock($address,"72.34.97.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-22). "); //74d repaired 75b
$ax += cidrblock($address,"72.34.98.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-23). "); //74d repaired 75b
$ax += cidrblock($address,"74.63.92.0/22","Xeex communications, not an access provider, AS27524 (ASN-XEEX-24). "); //74d repaired 75b
$ax += cidrblock($address,"86.104.11.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-25). "); //74d repaired 75b
$ax += cidrblock($address,"86.104.220.0/22","Xeex communications, not an access provider, AS27524 (ASN-XEEX-26). "); //74d repaired 75b
$ax += cidrblock($address,"89.40.16.0/22","Xeex communications, not an access provider, AS27524 (ASN-XEEX-27). "); //74d repaired 75b
$ax += cidrblock($address,"89.40.71.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-28). "); //74d repaired 75b
$ax += cidrblock($address,"89.43.62.0/23","Xeex communications, not an access provider, AS27524 (ASN-XEEX-29). "); //74d repaired 75b
$ax += cidrblock($address,"89.46.100.0/22","Xeex communications, not an access provider, AS27524 (ASN-XEEX-30). "); //74d repaired 75b
$ax += cidrblock($address,"92.114.4.0/22","Xeex communications, not an access provider, AS27524 (ASN-XEEX-31). "); //74d repaired 75b
$ax += cidrblock($address,"96.6.96.0/20","Xeex communications, not an access provider, AS27524 (ASN-XEEX-32). "); //74d repaired 75b
$ax += cidrblock($address,"96.7.144.0/20","Xeex communications, not an access provider, AS27524 (ASN-XEEX-33). "); //74d repaired 75b
$ax += cidrblock($address,"108.179.64.0/18","Xeex communications, not an access provider, AS27524 (ASN-XEEX-34). "); //74d repaired 75b
$ax += cidrblock($address,"113.212.64.0/19","Xeex communications, not an access provider, AS27524 (ASN-XEEX-35). "); //74d repaired 75b
$ax += cidrblock($address,"151.192.0.0/16","Xeex communications, not an access provider, AS27524 (ASN-XEEX-36). "); //74d repaired 75b
$ax += cidrblock($address,"154.37.66.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-37). "); //74d repaired 75b
$ax += cidrblock($address,"162.213.128.0/22","Xeex communications, not an access provider, AS27524 (ASN-XEEX-38). "); //74d repaired 75b
$ax += cidrblock($address,"163.182.0.0/19","Xeex communications, not an access provider, AS27524 (ASN-XEEX-39). "); //74d repaired 75b
$ax += cidrblock($address,"163.182.32.0/21","Xeex communications, not an access provider, AS27524 (ASN-XEEX-40). "); //74d repaired 75b
$ax += cidrblock($address,"168.205.0.0/16","Xeex communications, not an access provider, AS27524 (ASN-XEEX-41). "); //74d repaired 75b
$ax += cidrblock($address,"173.231.192.0/18","Xeex communications, not an access provider, AS27524 (ASN-XEEX-42). "); //74d repaired 75b
$ax += cidrblock($address,"173.249.192.0/18","Xeex communications, not an access provider, AS27524 (ASN-XEEX-43). "); //74d repaired 75b
$ax += cidrblock($address,"194.28.156.0/22","Xeex communications, not an access provider, AS27524 (ASN-XEEX-44). "); //74d repaired 75b
$ax += cidrblock($address,"198.13.124.0/22","Xeex communications, not an access provider, AS27524 (ASN-XEEX-45). "); //74d repaired 75b
$ax += cidrblock($address,"198.16.64.0/18","Xeex communications, not an access provider, AS27524 (ASN-XEEX-46). "); //74d repaired 75b
$ax += cidrblock($address,"199.114.212.0/22","Xeex communications, not an access provider, AS27524 (ASN-XEEX-47). "); //74d repaired 75b
$ax += cidrblock($address,"199.249.179.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-48). "); //74d repaired 75b
$ax += cidrblock($address,"199.249.180.0/23","Xeex communications, not an access provider, AS27524 (ASN-XEEX-49). "); //74d repaired 75b
$ax += cidrblock($address,"199.249.182.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-50). "); //74d repaired 75b
$ax += cidrblock($address,"199.255.236.0/22","Xeex communications, not an access provider, AS27524 (ASN-XEEX-51). "); //74d repaired 75b
$ax += cidrblock($address,"204.8.33.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-52). "); //74d repaired 75b
$ax += cidrblock($address,"204.8.35.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-53). "); //74d repaired 75b
$ax += cidrblock($address,"204.11.18.0/23","Xeex communications, not an access provider, AS27524 (ASN-XEEX-54). "); //74d repaired 75b
$ax += cidrblock($address,"204.45.224.0/19","Xeex communications, not an access provider, AS27524 (ASN-XEEX-55). "); //74d repaired 75b
$ax += cidrblock($address,"204.71.16.176/29","Xeex communications, not an access provider, AS27524 (ASN-XEEX-56). "); //74d repaired 75b
$ax += cidrblock($address,"205.134.238.0/23","Xeex communications, not an access provider, AS27524 (ASN-XEEX-57). "); //74d repaired 75b
$ax += cidrblock($address,"205.177.3.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-58). "); //74d repaired 75b
$ax += cidrblock($address,"205.252.0.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-59). "); //74d repaired 75b
$ax += cidrblock($address,"206.161.11.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-60). "); //74d repaired 75b
$ax += cidrblock($address,"206.161.141.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-61). "); //74d repaired 75b
$ax += cidrblock($address,"206.226.64.0/18","Xeex communications, not an access provider, AS27524 (ASN-XEEX-62). "); //74d repaired 75b
$ax += cidrblock($address,"207.0.203.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-63). "); //74d repaired 75b
$ax += cidrblock($address,"207.126.64.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-64). "); //74d repaired 75b
$ax += cidrblock($address,"207.176.22.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-65). "); //74d repaired 75b
$ax += cidrblock($address,"207.226.11.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-66). "); //74d repaired 75b
$ax += cidrblock($address,"207.226.112.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-67). "); //74d repaired 75b
$ax += cidrblock($address,"207.245.198.0/23","Xeex communications, not an access provider, AS27524 (ASN-XEEX-68). "); //74d repaired 75b
$ax += cidrblock($address,"207.246.198.0/23","Xeex communications, not an access provider, AS27524 (ASN-XEEX-69). "); //74d repaired 75b
$ax += cidrblock($address,"208.51.60.0/22","Xeex communications, not an access provider, AS27524 (ASN-XEEX-70). "); //74d repaired 75b
$ax += cidrblock($address,"208.77.20.0/22","Xeex communications, not an access provider, AS27524 (ASN-XEEX-71). "); //74d repaired 75b
$ax += cidrblock($address,"208.78.139.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-72). "); //74d repaired 75b
$ax += cidrblock($address,"208.90.0.0/21","Xeex communications, not an access provider, AS27524 (ASN-XEEX-73). "); //74d repaired 75b
$ax += cidrblock($address,"209.159.140.0/23","Xeex communications, not an access provider, AS27524 (ASN-XEEX-74). "); //74d repaired 75b
$ax += cidrblock($address,"209.242.192.0/19","Xeex communications, not an access provider, AS27524 (ASN-XEEX-75). "); //74d repaired 75b
$ax += cidrblock($address,"209.245.124.0/24","Xeex communications, not an access provider, AS27524 (ASN-XEEX-76). "); //74d repaired 75b
$ax += cidrblock($address,"216.59.0.0/19","Xeex communications, not an access provider, AS27524 (ASN-XEEX-77). "); //74d repaired 75b
$ax += cidrblock($address,"216.59.48.0/21","Xeex communications, not an access provider, AS27524 (ASN-XEEX-78). "); //74d repaired 75b
$ax += cidrblock($address,"216.59.128.0/18","Xeex communications, not an access provider, AS27524 (ASN-XEEX-79). "); //74d repaired 75b
$ax += cidrblock($address,"216.151.128.0/19","Xeex communications, not an access provider, AS27524 (ASN-XEEX-80). "); //74d repaired 75b
$ax += cidrblock($address,"216.152.240.0/20","Xeex communications, not an access provider, AS27524 (ASN-XEEX-81). "); //74d repaired 75b
$ax += cidrblock($address,"216.156.142.0/23","Xeex communications, not an access provider, AS27524 (ASN-XEEX-82). "); //74d repaired 75b


//  iWeb Technologies Inc.
//  AS32613

$ax += cidrblock($address,'38.108.70.0/24','iWeb Technologies Inc. Not an access provider ISP (ASN-IWEB-0). '); //74d
$ax += cidrblock($address,'38.108.82.0/24','iWeb Technologies Inc. Not an access provider ISP (ASN-IWEB-1). '); //74d
$ax += cidrblock($address,'64.15.128.0/19','iWeb Technologies Inc. Not an access provider ISP (ASN-IWEB-2). '); //74d
$ax += cidrblock($address,'66.11.39.0/24','iWeb Technologies Inc. Not an access provider ISP (ASN-IWEB-3). '); //74d
$ax += cidrblock($address,'66.234.16.0/20','iWeb Technologies Inc. Not an access provider ISP (ASN-IWEB-4). '); //74d
$ax += cidrblock($address,'67.205.64.0/18','iWeb Technologies Inc. Not an access provider ISP (ASN-IWEB-5). '); //74d
$ax += cidrblock($address,'70.38.0.0/17','iWeb Technologies Inc. Not an access provider ISP (ASN-IWEB-6). '); //74d
$ax += cidrblock($address,'72.55.128.0/18','iWeb Technologies Inc. Not an access provider ISP (ASN-IWEB-7). '); //74d
$ax += cidrblock($address,'74.113.72.0/23','iWeb Technologies Inc. Not an access provider ISP (ASN-IWEB-8). '); //74d
$ax += cidrblock($address,'108.163.128.0/18','iWeb Technologies Inc. Not an access provider ISP (ASN-IWEB-9). '); //74d
$ax += cidrblock($address,'174.141.228.0/22','iWeb Technologies Inc. Not an access provider ISP (ASN-IWEB-10). '); //74d
$ax += cidrblock($address,'174.141.232.0/23','iWeb Technologies Inc. Not an access provider ISP (ASN-IWEB-11). '); //74d
$ax += cidrblock($address,'174.142.0.0/16','iWeb Technologies Inc. Not an access provider ISP (ASN-IWEB-12). '); //74d
$ax += cidrblock($address,'184.107.0.0/16','iWeb Technologies Inc. Not an access provider ISP (ASN-IWEB-13). '); //74d
$ax += cidrblock($address,'189.91.32.0/23','iWeb Technologies Inc. Not an access provider ISP (ASN-IWEB-14). '); //74d
$ax += cidrblock($address,'192.219.254.0/24','iWeb Technologies Inc. Not an access provider ISP (ASN-IWEB-15). '); //74d
$ax += cidrblock($address,'198.50.96.0/19','iWeb Technologies Inc. Not an access provider ISP (ASN-IWEB-16). '); //74d
$ax += cidrblock($address,'198.72.96.0/19','iWeb Technologies Inc. Not an access provider ISP (ASN-IWEB-17). '); //74d
$ax += cidrblock($address,'199.84.182.0/24','iWeb Technologies Inc. Not an access provider ISP (ASN-IWEB-18). '); //74d
$ax += cidrblock($address,'204.19.249.0/24','iWeb Technologies Inc. Not an access provider ISP (ASN-IWEB-19). '); //74d
$ax += cidrblock($address,'204.19.251.0/24','iWeb Technologies Inc. Not an access provider ISP (ASN-IWEB-20). '); //74d
$ax += cidrblock($address,'204.19.253.0/24','iWeb Technologies Inc. Not an access provider ISP (ASN-IWEB-21). '); //74d
$ax += cidrblock($address,'204.19.254.0/24','iWeb Technologies Inc. Not an access provider ISP (ASN-IWEB-22). '); //74d
$ax += cidrblock($address,'205.236.34.0/24','iWeb Technologies Inc. Not an access provider ISP (ASN-IWEB-23). '); //74d
$ax += cidrblock($address,'206.123.20.0/23','iWeb Technologies Inc. Not an access provider ISP (ASN-IWEB-24). '); //74d
$ax += cidrblock($address,'209.172.32.0/19','iWeb Technologies Inc. Not an access provider ISP (ASN-IWEB-25). '); //74d


//  Reliable Hosting Services
//  AS29713

$ax += cidrblock($address,'199.15.248.0/21','Reliable Hosting Services. Not an access provider ISP. (ASN-RELIA-0). '); //74d
$ax += cidrblock($address,'208.73.20.0/22','Reliable Hosting Services. Not an access provider ISP. (ASN-RELIA-1). '); //74d


// Westhost
// AS29854

$ax += cidrblock($address,'31.220.5.0/24','Westhost, not an access provider ISP (ASN-WESTHOST-0). '); //74d
$ax += cidrblock($address,'50.115.112.0/20','Westhost, not an access provider ISP (ASN-WESTHOST-1). '); //74d
$ax += cidrblock($address,'67.212.224.0/20','Westhost, not an access provider ISP (ASN-WESTHOST-2). '); //74d
$ax += cidrblock($address,'68.169.32.0/20','Westhost, not an access provider ISP (ASN-WESTHOST-3). '); //74d
$ax += cidrblock($address,'69.36.160.0/19','Westhost, not an access provider ISP (ASN-WESTHOST-4). '); //74d
$ax += cidrblock($address,'173.255.128.0/22','Westhost, not an access provider ISP (ASN-WESTHOST-5). '); //74d
$ax += cidrblock($address,'174.127.104.0/21','Westhost, not an access provider ISP (ASN-WESTHOST-6). '); //74d
$ax += cidrblock($address,'174.127.112.0/21','Westhost, not an access provider ISP (ASN-WESTHOST-7). '); //74d
$ax += cidrblock($address,'192.102.82.0/24','Westhost, not an access provider ISP (ASN-WESTHOST-8). '); //74d
$ax += cidrblock($address,'198.105.208.0/20','Westhost, not an access provider ISP (ASN-WESTHOST-9). '); //74d
$ax += cidrblock($address,'199.189.104.0/21','Westhost, not an access provider ISP (ASN-WESTHOST-10). '); //74d
$ax += cidrblock($address,'199.195.192.0/21','Westhost, not an access provider ISP (ASN-WESTHOST-11). '); //74d
$ax += cidrblock($address,'204.147.96.0/20','Westhost, not an access provider ISP (ASN-WESTHOST-12). '); //74d
$ax += cidrblock($address,'206.130.96.0/19','Westhost, not an access provider ISP (ASN-WESTHOST-13). '); //74d
$ax += cidrblock($address,'206.190.128.0/19','Westhost, not an access provider ISP (ASN-WESTHOST-14). '); //74d
$ax += cidrblock($address,'206.209.240.0/20','Westhost, not an access provider ISP (ASN-WESTHOST-15). '); //74d
$ax += cidrblock($address,'208.131.128.0/19','Westhost, not an access provider ISP (ASN-WESTHOST-16). '); //74d
$ax += cidrblock($address,'209.95.32.0/19','Westhost, not an access provider ISP (ASN-WESTHOST-17). '); //74d
$ax += cidrblock($address,'209.236.64.0/20','Westhost, not an access provider ISP (ASN-WESTHOST-18). '); //74d

// Bezeq International
// AS8551

$ax += cidrblock($address,'23.34.224.0/20','BEZEQ-INT (ASN-BEZEQ-0). '); //74d
$ax += cidrblock($address,'31.25.112.0/23','BEZEQ-INT (ASN-BEZEQ-1). '); //74d
$ax += cidrblock($address,'31.168.0.0/16','BEZEQ-INT (ASN-BEZEQ-2). '); //74d
$ax += cidrblock($address,'62.219.0.0/16','BEZEQ-INT (ASN-BEZEQ-3). '); //74d
$ax += cidrblock($address,'79.176.0.0/13','BEZEQ-INT (ASN-BEZEQ-4). '); //74d
$ax += cidrblock($address,'80.74.96.0/20','BEZEQ-INT (ASN-BEZEQ-5). '); //74d
$ax += cidrblock($address,'81.218.0.0/16','BEZEQ-INT (ASN-BEZEQ-6). '); //74d
$ax += cidrblock($address,'82.80.0.0/15','BEZEQ-INT (ASN-BEZEQ-7). '); //74d
$ax += cidrblock($address,'84.108.0.0/14','BEZEQ-INT (ASN-BEZEQ-8). '); //74d
$ax += cidrblock($address,'85.114.96.0/21','BEZEQ-INT (ASN-BEZEQ-9). '); //74d
$ax += cidrblock($address,'85.130.128.0/17','BEZEQ-INT (ASN-BEZEQ-10). '); //74d
$ax += cidrblock($address,'91.192.200.0/22','BEZEQ-INT (ASN-BEZEQ-11). '); //74d
$ax += cidrblock($address,'91.228.248.0/24','BEZEQ-INT (ASN-BEZEQ-12). '); //74d
$ax += cidrblock($address,'91.246.218.0/24','BEZEQ-INT (ASN-BEZEQ-13). '); //74d
$ax += cidrblock($address,'92.122.128.0/20','BEZEQ-INT (ASN-BEZEQ-14). '); //74d
$ax += cidrblock($address,'95.101.4.0/22','BEZEQ-INT (ASN-BEZEQ-15). '); //74d
$ax += cidrblock($address,'109.64.0.0/14','BEZEQ-INT (ASN-BEZEQ-16). '); //74d
$ax += cidrblock($address,'147.235.228.0/23','BEZEQ-INT (ASN-BEZEQ-17). '); //74d
$ax += cidrblock($address,'184.27.128.0/23','BEZEQ-INT (ASN-BEZEQ-18). '); //74d
$ax += cidrblock($address,'192.114.11.0/24','BEZEQ-INT (ASN-BEZEQ-19). '); //74d
$ax += cidrblock($address,'192.114.40.0/21','BEZEQ-INT (ASN-BEZEQ-20). '); //74d
$ax += cidrblock($address,'192.114.64.0/20','BEZEQ-INT (ASN-BEZEQ-21). '); //74d
$ax += cidrblock($address,'192.114.80.0/22','BEZEQ-INT (ASN-BEZEQ-22). '); //74d
$ax += cidrblock($address,'192.114.144.0/22','BEZEQ-INT (ASN-BEZEQ-23). '); //74d
$ax += cidrblock($address,'192.115.16.0/20','BEZEQ-INT (ASN-BEZEQ-24). '); //74d
$ax += cidrblock($address,'192.115.56.0/21','BEZEQ-INT (ASN-BEZEQ-25). '); //74d
$ax += cidrblock($address,'192.115.104.0/22','BEZEQ-INT (ASN-BEZEQ-26). '); //74d
$ax += cidrblock($address,'192.115.128.0/21','BEZEQ-INT (ASN-BEZEQ-27). '); //74d
$ax += cidrblock($address,'192.115.184.0/21','BEZEQ-INT (ASN-BEZEQ-28). '); //74d
$ax += cidrblock($address,'192.116.4.0/23','BEZEQ-INT (ASN-BEZEQ-29). '); //74d
$ax += cidrblock($address,'192.116.10.0/23','BEZEQ-INT (ASN-BEZEQ-30). '); //74d
$ax += cidrblock($address,'192.116.12.0/22','BEZEQ-INT (ASN-BEZEQ-31). '); //74d
$ax += cidrblock($address,'192.117.96.0/19','BEZEQ-INT (ASN-BEZEQ-32). '); //74d
$ax += cidrblock($address,'192.117.232.0/21','BEZEQ-INT (ASN-BEZEQ-33). '); //74d
$ax += cidrblock($address,'192.118.88.0/22','BEZEQ-INT (ASN-BEZEQ-34). '); //74d
$ax += cidrblock($address,'192.118.112.0/22','BEZEQ-INT (ASN-BEZEQ-35). '); //74d
$ax += cidrblock($address,'192.118.132.0/22','BEZEQ-INT (ASN-BEZEQ-36). '); //74d
$ax += cidrblock($address,'193.138.92.0/24','BEZEQ-INT (ASN-BEZEQ-37). '); //74d
$ax += cidrblock($address,'194.114.146.0/23','BEZEQ-INT (ASN-BEZEQ-38). '); //74d
$ax += cidrblock($address,'194.153.101.0/24','BEZEQ-INT (ASN-BEZEQ-39). '); //74d
$ax += cidrblock($address,'195.22.148.0/23','BEZEQ-INT (ASN-BEZEQ-40). '); //74d
$ax += cidrblock($address,'195.177.108.0/22','BEZEQ-INT (ASN-BEZEQ-41). '); //74d
$ax += cidrblock($address,'195.200.92.0/23','BEZEQ-INT (ASN-BEZEQ-42). '); //74d
$ax += cidrblock($address,'195.213.229.0/24','BEZEQ-INT (ASN-BEZEQ-43). '); //74d
$ax += cidrblock($address,'206.82.140.0/24','BEZEQ-INT (ASN-BEZEQ-44). '); //74d
$ax += cidrblock($address,'207.117.93.0/24','BEZEQ-INT (ASN-BEZEQ-45). '); //74d
$ax += cidrblock($address,'212.25.64.0/18','BEZEQ-INT (ASN-BEZEQ-46). '); //74d
$ax += cidrblock($address,'212.179.0.0/16','BEZEQ-INT (ASN-BEZEQ-47). '); //74d
$ax += cidrblock($address,'213.31.203.0/24','BEZEQ-INT (ASN-BEZEQ-48). '); //74d
$ax += cidrblock($address,'213.31.208.0/23','BEZEQ-INT (ASN-BEZEQ-49). '); //74d
$ax += cidrblock($address,'217.22.112.0/22','BEZEQ-INT (ASN-BEZEQ-50). '); //74d
$ax += cidrblock($address,'217.22.116.0/23','BEZEQ-INT (ASN-BEZEQ-51). '); //74d
$ax += cidrblock($address,'217.194.200.0/22','BEZEQ-INT (ASN-BEZEQ-52). '); //74d

//  DataShack, LC & WholeSale Internet, Inc.
//  AS33387

$ax += cidrblock($address,'63.141.224.0/19','DataShack, LC. Not an access provider ISP. (ASN-DATASHACK-0). '); //74d
$ax += cidrblock($address,'69.197.185.0/24','WholeSale Internet, Inc. Not an access provider ISP. (ASN-DATASHACK-1). '); //74d
$ax += cidrblock($address,'74.91.16.0/20','DataShack, LC. Not an access provider ISP. (ASN-DATASHACK-2). '); //74d
$ax += cidrblock($address,'142.54.160.0/19','DataShack, LC. Not an access provider ISP. (ASN-DATASHACK-3). '); //74d
$ax += cidrblock($address,'173.208.138.0/24','Hosting Inc.  Not an access provider ISP. (ASN-DATASHACK-4). '); //74d
$ax += cidrblock($address,'173.208.214.0/23','WholeSale Internet, Inc. Not an access provider ISP. (ASN-DATASHACK-5). '); //74d
$ax += cidrblock($address,'173.208.216.0/24','WholeSale Internet, Inc. Not an access provider ISP. (ASN-DATASHACK-6). '); //74d
$ax += cidrblock($address,'173.208.218.0/24','WholeSale Internet, Inc. Not an access provider ISP. (ASN-DATASHACK-7). '); //74d
$ax += cidrblock($address,'173.208.225.0/24','WholeSale Internet, Inc. Not an access provider ISP. (ASN-DATASHACK-8). '); //74d
$ax += cidrblock($address,'173.208.226.0/24','WholeSale Internet, Inc. Not an access provider ISP. (ASN-DATASHACK-9). '); //74d
$ax += cidrblock($address,'173.208.228.0/24','WholeSale Internet, Inc. Not an access provider ISP. (ASN-DATASHACK-10). '); //74d
$ax += cidrblock($address,'192.151.144.0/20','DataShack, LC. Not an access provider ISP. (ASN-DATASHACK-11). '); //74d
$ax += cidrblock($address,'192.187.96.0/19','DataShack, LC. Not an access provider ISP. (ASN-DATASHACK-12). '); //74d
$ax += cidrblock($address,'198.204.224.0/19','DataShack, LC. Not an access provider ISP. (ASN-DATASHACK-13). '); //74d
$ax += cidrblock($address,'199.168.96.0/21','DataShack, LC. Not an access provider ISP. (ASN-DATASHACK-14). '); //74d

// CoS International
// AS7914

$ax += cidrblock($address,'12.9.239.0/24','Known hostile network (ASN-CSI-0). '); //74d
$ax += cidrblock($address,'192.216.201.0/24','Known hostile network (ASN-CSI-1). '); //74d
$ax += cidrblock($address,'198.77.154.0/23','Known hostile network (ASN-CSI-2). '); //74d
$ax += cidrblock($address,'198.95.10.0/24','Known hostile network (ASN-CSI-3). '); //74d
$ax += cidrblock($address,'205.180.15.0/24','Known hostile network (ASN-CSI-4). '); //74d
$ax += cidrblock($address,'205.227.165.0/24','Known hostile network (ASN-CSI-5). '); //74d
$ax += cidrblock($address,'208.29.5.0/24','Known hostile network (ASN-CSI-6). '); //74d
$ax += cidrblock($address,'208.30.51.0/24','Known hostile network (ASN-CSI-7). '); //74d
$ax += cidrblock($address,'208.33.13.0/24','Known hostile network (ASN-CSI-8). '); //74d

// Avante Hosting
// AS36137

$ax += cidrblock($address,'31.187.67.0/24','Avante Hosting, not an access provider (ASN-AVANTE-0). '); //74d
$ax += cidrblock($address,'31.187.72.0/21','Avante Hosting, not an access provider (ASN-AVANTE-1). '); //74d
$ax += cidrblock($address,'31.187.80.0/20','Avante Hosting, not an access provider (ASN-AVANTE-2). '); //74d
$ax += cidrblock($address,'31.220.64.0/18','Avante Hosting, not an access provider (ASN-AVANTE-3). '); //74d
$ax += cidrblock($address,'66.248.192.0/19','Avante Hosting, not an access provider (ASN-AVANTE-4). '); //74d
$ax += cidrblock($address,'72.18.69.0/24','Avante Hosting, not an access provider (ASN-AVANTE-5). '); //74d
$ax += cidrblock($address,'77.237.226.0/23','Avante Hosting, not an access provider (ASN-AVANTE-6). '); //74d
$ax += cidrblock($address,'77.237.228.0/23','Avante Hosting, not an access provider (ASN-AVANTE-7). '); //74d
$ax += cidrblock($address,'77.237.248.0/23','Avante Hosting, not an access provider (ASN-AVANTE-8). '); //74d
$ax += cidrblock($address,'77.237.251.0/24','Avante Hosting, not an access provider (ASN-AVANTE-9). '); //74d
$ax += cidrblock($address,'77.237.252.0/22','Avante Hosting, not an access provider (ASN-AVANTE-10). '); //74d
$ax += cidrblock($address,'192.119.144.0/20','Avante Hosting, not an access provider (ASN-AVANTE-11). '); //74d
$ax += cidrblock($address,'192.161.192.0/18','Avante Hosting, not an access provider (ASN-AVANTE-12). '); //74d
$ax += cidrblock($address,'192.241.8.0/21','Avante Hosting, not an access provider (ASN-AVANTE-13). '); //74d
$ax += cidrblock($address,'198.52.128.0/17','Avante Hosting, not an access provider (ASN-AVANTE-14). '); //74d
$ax += cidrblock($address,'199.195.156.0/22','Avante Hosting, not an access provider (ASN-AVANTE-15). '); //74d
$ax += cidrblock($address,'204.16.20.0/22','Avante Hosting, not an access provider (ASN-AVANTE-16). '); //74d

// One and One Hosting
// AS8560

$ax += cidrblock($address,'50.21.176.0/20','One and One hosting, not an access provider (ASN-ONEANDONE-0). '); //75a
$ax += cidrblock($address,'62.116.162.0/23','One and One hosting, not an access provider (ASN-ONEANDONE-1). '); //75a
$ax += cidrblock($address,'70.35.192.0/20','One and One hosting, not an access provider (ASN-ONEANDONE-2). '); //75a
$ax += cidrblock($address,'74.208.0.0/16','One and One hosting, not an access provider (ASN-ONEANDONE-3). '); //75a
$ax += cidrblock($address,'82.165.0.0/16','One and One hosting, not an access provider (ASN-ONEANDONE-4). '); //75a
$ax += cidrblock($address,'87.106.0.0/16','One and One hosting, not an access provider (ASN-ONEANDONE-5). '); //75a
$ax += cidrblock($address,'108.175.0.0/20','One and One hosting, not an access provider (ASN-ONEANDONE-6). '); //75a
$ax += cidrblock($address,'195.20.224.0/19','One and One hosting, not an access provider (ASN-ONEANDONE-7). '); //75a
$ax += cidrblock($address,'198.71.48.0/20','One and One hosting, not an access provider (ASN-ONEANDONE-8). '); //75a
$ax += cidrblock($address,'198.251.64.0/20','One and One hosting, not an access provider (ASN-ONEANDONE-9). '); //75a
$ax += cidrblock($address,'212.227.0.0/16','One and One hosting, not an access provider (ASN-ONEANDONE-10). '); //75a
$ax += cidrblock($address,'213.165.64.0/19','One and One hosting, not an access provider (ASN-ONEANDONE-11). '); //75a
$ax += cidrblock($address,'216.250.112.0/20','One and One hosting, not an access provider (ASN-ONEANDONE-12). '); //75a
$ax += cidrblock($address,'217.72.192.0/20','One and One hosting, not an access provider (ASN-ONEANDONE-13). '); //75a
$ax += cidrblock($address,'217.160.0.0/16','One and One hosting, not an access provider (ASN-ONEANDONE-14). '); //75a

// Swift Networks Limited
// AS36923

$ax += cidrblock($address,'41.58.0.0/16','Swift Networks Limited is blocked by the system administrator, Nigeria, nuf said (ASN-AS36923-0). '); //75a
$ax += cidrblock($address,'41.189.0.0/19','Swift Networks Limited is blocked by the system administrator, Nigeria, nuf said (ASN-AS36923-1). '); //75a
$ax += cidrblock($address,'41.221.160.0/20','Swift Networks Limited is blocked by the system administrator, Nigeria, nuf said (ASN-AS36923-2). '); //75a
$ax += cidrblock($address,'41.222.64.0/21','Swift Networks Limited is blocked by the system administrator, Nigeria, nuf said (ASN-AS36923-3). '); //75a


// HostDime.com, Inc. , #1 Host Exploit rank.
// AS33182

$ax += cidrblock($address,"5.226.171.0/24","HostDime.com Inc, #1 HE Rank (ASN-AS33182-0). ");
$ax += cidrblock($address,"8.10.120.0/24","HostDime.com Inc, #1 HE Rank (ASN-AS33182-1). ");
$ax += cidrblock($address,"8.19.188.0/22","HostDime.com Inc, #1 HE Rank (ASN-AS33182-2). ");
$ax += cidrblock($address,"8.33.160.0/20","HostDime.com Inc, #1 HE Rank (ASN-AS33182-3). ");
$ax += cidrblock($address,"23.239.129.0/24","HostDime.com Inc, #1 HE Rank (ASN-AS33182-4). ");
$ax += cidrblock($address,"37.46.120.0/24","HostDime.com Inc, #1 HE Rank (ASN-AS33182-5). ");
$ax += cidrblock($address,"64.37.48.0/20","HostDime.com Inc, #1 HE Rank (ASN-AS33182-6). ");
$ax += cidrblock($address,"64.72.112.0/20","HostDime.com Inc, #1 HE Rank (ASN-AS33182-7). ");
$ax += cidrblock($address,"64.132.144.0/24","HostDime.com Inc, #1 HE Rank (ASN-AS33182-8). ");
$ax += cidrblock($address,"65.248.144.0/24","HostDime.com Inc, #1 HE Rank (ASN-AS33182-9). ");
$ax += cidrblock($address,"66.7.192.0/19","HostDime.com Inc, #1 HE Rank (ASN-AS33182-10). ");
$ax += cidrblock($address,"66.193.174.0/23","HostDime.com Inc, #1 HE Rank (ASN-AS33182-11). ");
$ax += cidrblock($address,"66.193.230.0/23","HostDime.com Inc, #1 HE Rank (ASN-AS33182-12). ");
$ax += cidrblock($address,"66.194.40.0/23","HostDime.com Inc, #1 HE Rank (ASN-AS33182-13). ");
$ax += cidrblock($address,"66.194.152.0/23","HostDime.com Inc, #1 HE Rank (ASN-AS33182-14). ");
$ax += cidrblock($address,"66.194.238.0/23","HostDime.com Inc, #1 HE Rank (ASN-AS33182-15). ");
$ax += cidrblock($address,"66.195.16.0/22","HostDime.com Inc, #1 HE Rank (ASN-AS33182-16). ");
$ax += cidrblock($address,"66.195.124.0/22","HostDime.com Inc, #1 HE Rank (ASN-AS33182-17). ");
$ax += cidrblock($address,"66.195.240.0/22","HostDime.com Inc, #1 HE Rank (ASN-AS33182-18). ");
$ax += cidrblock($address,"66.195.252.0/24","HostDime.com Inc, #1 HE Rank (ASN-AS33182-19). ");
$ax += cidrblock($address,"67.23.224.0/19","HostDime.com Inc, #1 HE Rank (ASN-AS33182-20). ");
$ax += cidrblock($address,"69.80.224.0/20","HostDime.com Inc, #1 HE Rank (ASN-AS33182-21). ");
$ax += cidrblock($address,"72.29.64.0/19","HostDime.com Inc, #1 HE Rank (ASN-AS33182-22). ");
$ax += cidrblock($address,"103.13.240.0/22","HostDime.com Inc, #1 HE Rank (ASN-AS33182-23). ");
$ax += cidrblock($address,"109.73.160.0/21","HostDime.com Inc, #1 HE Rank (ASN-AS33182-24). ");
$ax += cidrblock($address,"109.73.168.0/22","HostDime.com Inc, #1 HE Rank (ASN-AS33182-25). ");
$ax += cidrblock($address,"109.73.172.0/23","HostDime.com Inc, #1 HE Rank (ASN-AS33182-26). ");
$ax += cidrblock($address,"109.73.175.0/24","HostDime.com Inc, #1 HE Rank (ASN-AS33182-27). ");
$ax += cidrblock($address,"129.75.0.0/18","HostDime.com Inc, #1 HE Rank (ASN-AS33182-28). ");
$ax += cidrblock($address,"129.75.64.0/24","HostDime.com Inc, #1 HE Rank (ASN-AS33182-29). ");
$ax += cidrblock($address,"129.75.67.0/24","HostDime.com Inc, #1 HE Rank (ASN-AS33182-30). ");
$ax += cidrblock($address,"129.75.72.0/21","HostDime.com Inc, #1 HE Rank (ASN-AS33182-31). ");
$ax += cidrblock($address,"129.75.80.0/20","HostDime.com Inc, #1 HE Rank (ASN-AS33182-32). ");
$ax += cidrblock($address,"129.75.96.0/20","HostDime.com Inc, #1 HE Rank (ASN-AS33182-33). ");
$ax += cidrblock($address,"129.75.120.0/21","HostDime.com Inc, #1 HE Rank (ASN-AS33182-34). ");
$ax += cidrblock($address,"129.75.128.0/21","HostDime.com Inc, #1 HE Rank (ASN-AS33182-35). ");
$ax += cidrblock($address,"129.75.140.0/22","HostDime.com Inc, #1 HE Rank (ASN-AS33182-36). ");
$ax += cidrblock($address,"129.75.152.0/21","HostDime.com Inc, #1 HE Rank (ASN-AS33182-37). ");
$ax += cidrblock($address,"129.75.168.0/21","HostDime.com Inc, #1 HE Rank (ASN-AS33182-38). ");
$ax += cidrblock($address,"129.75.192.0/18","HostDime.com Inc, #1 HE Rank (ASN-AS33182-39). ");
$ax += cidrblock($address,"129.134.32.0/19","HostDime.com Inc, #1 HE Rank (ASN-AS33182-40). ");
$ax += cidrblock($address,"129.134.64.0/18","HostDime.com Inc, #1 HE Rank (ASN-AS33182-41). ");
$ax += cidrblock($address,"129.134.128.0/19","HostDime.com Inc, #1 HE Rank (ASN-AS33182-42). ");
$ax += cidrblock($address,"129.134.160.0/20","HostDime.com Inc, #1 HE Rank (ASN-AS33182-43). ");
$ax += cidrblock($address,"129.134.208.0/21","HostDime.com Inc, #1 HE Rank (ASN-AS33182-44). ");
$ax += cidrblock($address,"129.134.224.0/19","HostDime.com Inc, #1 HE Rank (ASN-AS33182-45). ");
$ax += cidrblock($address,"162.221.184.0/21","HostDime.com Inc, #1 HE Rank (ASN-AS33182-46). ");
$ax += cidrblock($address,"179.48.64.0/19","HostDime.com Inc, #1 HE Rank (ASN-AS33182-47). ");
$ax += cidrblock($address,"184.171.240.0/20","HostDime.com Inc, #1 HE Rank (ASN-AS33182-48). ");
$ax += cidrblock($address,"185.38.44.0/22","HostDime.com Inc, #1 HE Rank (ASN-AS33182-49). ");
$ax += cidrblock($address,"190.123.196.0/24","HostDime.com Inc, #1 HE Rank (ASN-AS33182-50). ");
$ax += cidrblock($address,"198.49.64.0/20","HostDime.com Inc, #1 HE Rank (ASN-AS33182-51). ");
$ax += cidrblock($address,"198.136.48.0/20","HostDime.com Inc, #1 HE Rank (ASN-AS33182-52). ");
$ax += cidrblock($address,"199.166.30.0/23","HostDime.com Inc, #1 HE Rank (ASN-AS33182-53). ");
$ax += cidrblock($address,"199.168.184.0/21","HostDime.com Inc, #1 HE Rank (ASN-AS33182-54). ");
$ax += cidrblock($address,"200.106.144.0/24","HostDime.com Inc, #1 HE Rank (ASN-AS33182-55). ");
$ax += cidrblock($address,"201.151.147.0/24","HostDime.com Inc, #1 HE Rank (ASN-AS33182-56). ");
$ax += cidrblock($address,"201.163.118.0/24","HostDime.com Inc, #1 HE Rank (ASN-AS33182-57). ");
$ax += cidrblock($address,"208.184.146.0/23","HostDime.com Inc, #1 HE Rank (ASN-AS33182-58). ");
$ax += cidrblock($address,"209.148.83.0/24","HostDime.com Inc, #1 HE Rank (ASN-AS33182-59). ");
$ax += cidrblock($address,"209.148.85.0/24","HostDime.com Inc, #1 HE Rank (ASN-AS33182-60). ");


// New Dream Network, LLC, #2 Host Exploit rank.
// AS26347

$ax += cidrblock($address,'64.90.32.0/19','New Dream Network LLC, #2 HE Rank (ASN-AS26347-0). '); //75a
$ax += cidrblock($address,'64.111.96.0/19','New Dream Network LLC, #2 HE Rank (ASN-AS26347-1). '); //75a
$ax += cidrblock($address,'66.33.192.0/19','New Dream Network LLC, #2 HE Rank (ASN-AS26347-2). '); //75a
$ax += cidrblock($address,'67.205.0.0/18','New Dream Network LLC, #2 HE Rank (ASN-AS26347-3). '); //75a
$ax += cidrblock($address,'69.163.128.0/17','New Dream Network LLC, #2 HE Rank (ASN-AS26347-4). '); //75a
$ax += cidrblock($address,'75.119.192.0/19','New Dream Network LLC, #2 HE Rank (ASN-AS26347-5). '); //75a
$ax += cidrblock($address,'173.236.128.0/17','New Dream Network LLC, #2 HE Rank (ASN-AS26347-6). '); //75a
$ax += cidrblock($address,'205.196.208.0/20','New Dream Network LLC, #2 HE Rank (ASN-AS26347-7). '); //75a
$ax += cidrblock($address,'208.97.128.0/18','New Dream Network LLC, #2 HE Rank (ASN-AS26347-8). '); //75a
$ax += cidrblock($address,'208.113.128.0/17','New Dream Network LLC, #2 HE Rank (ASN-AS26347-9). '); //75a


// GoDaddy.com, LLC, #18 Host Exploit rank.
// AS26496

$ax += cidrblock($address,'37.148.200.0/21','GoDaddy.com LLC, #18 HE Rank  (ASN-AS26496-0). '); //75a
$ax += cidrblock($address,'46.252.192.0/20','GoDaddy.com LLC, #18 HE Rank  (ASN-AS26496-1). '); //75a
$ax += cidrblock($address,'50.62.0.0/15','GoDaddy.com LLC, #18 HE Rank  (ASN-AS26496-2). '); //75a
$ax += cidrblock($address,'63.240.0.0/15','GoDaddy.com LLC, #18 HE Rank  (ASN-AS26496-3). '); //75a
$ax += cidrblock($address,'64.202.160.0/19','GoDaddy.com LLC, #18 HE Rank  (ASN-AS26496-4). '); //75a
$ax += cidrblock($address,'66.210.39.0/24','GoDaddy.com LLC, #18 HE Rank  (ASN-AS26496-5). '); //75a
$ax += cidrblock($address,'68.178.128.0/17','GoDaddy.com LLC, #18 HE Rank  (ASN-AS26496-6). '); //75a
$ax += cidrblock($address,'72.167.0.0/16','GoDaddy.com LLC, #18 HE Rank  (ASN-AS26496-7). '); //75a
$ax += cidrblock($address,'97.74.0.0/16','GoDaddy.com LLC, #18 HE Rank  (ASN-AS26496-8). '); //75a
$ax += cidrblock($address,'103.1.172.0/22','GoDaddy.com LLC, #18 HE Rank  (ASN-AS26496-9). '); //75a
$ax += cidrblock($address,'118.139.160.0/19','GoDaddy.com LLC, #18 HE Rank  (ASN-AS26496-10). '); //75a
$ax += cidrblock($address,'146.255.32.0/20','GoDaddy.com LLC, #18 HE Rank  (ASN-AS26496-11). '); //75a
$ax += cidrblock($address,'160.153.0.0/16','GoDaddy.com LLC, #18 HE Rank  (ASN-AS26496-12). '); //75a
$ax += cidrblock($address,'166.62.0.0/17','GoDaddy.com LLC, #18 HE Rank  (ASN-AS26496-13). '); //75a
$ax += cidrblock($address,'173.201.0.0/16','GoDaddy.com LLC, #18 HE Rank  (ASN-AS26496-14). '); //75a
$ax += cidrblock($address,'182.50.128.0/19','GoDaddy.com LLC, #18 HE Rank  (ASN-AS26496-15). '); //75a
$ax += cidrblock($address,'184.168.0.0/16','GoDaddy.com LLC, #18 HE Rank  (ASN-AS26496-16). '); //75a
$ax += cidrblock($address,'185.7.248.0/22','GoDaddy.com LLC, #18 HE Rank  (ASN-AS26496-17). '); //75a
$ax += cidrblock($address,'188.121.32.0/19','GoDaddy.com LLC, #18 HE Rank  (ASN-AS26496-18). '); //75a
$ax += cidrblock($address,'192.169.128.0/17','GoDaddy.com LLC, #18 HE Rank  (ASN-AS26496-19). '); //75a
$ax += cidrblock($address,'192.186.192.0/18','GoDaddy.com LLC, #18 HE Rank  (ASN-AS26496-20). '); //75a
$ax += cidrblock($address,'198.12.128.0/17','GoDaddy.com LLC, #18 HE Rank  (ASN-AS26496-21). '); //75a
$ax += cidrblock($address,'198.71.128.0/17','GoDaddy.com LLC, #18 HE Rank  (ASN-AS26496-22). '); //75a
$ax += cidrblock($address,'203.124.96.0/19','GoDaddy.com LLC, #18 HE Rank  (ASN-AS26496-23). '); //75a
$ax += cidrblock($address,'208.109.0.0/16','GoDaddy.com LLC, #18 HE Rank  (ASN-AS26496-24). '); //75a
$ax += cidrblock($address,'216.69.128.0/18','GoDaddy.com LLC, #18 HE Rank  (ASN-AS26496-25). '); //75a


// PVNT Networks, #116 Host Exploit rank.
// AS21788

$ax += cidrblock($address,'64.120.128.0/17','PVNT Networks, #116 HE Rank (ASN-AS21788-0). '); //75a
$ax += cidrblock($address,'64.191.0.0/17','PVNT Networks, #116 HE Rank (ASN-AS21788-1). '); //75a
$ax += cidrblock($address,'66.96.192.0/18','PVNT Networks, #116 HE Rank (ASN-AS21788-2). '); //75a
$ax += cidrblock($address,'66.197.128.0/17','PVNT Networks, #116 HE Rank (ASN-AS21788-3). '); //75a
$ax += cidrblock($address,'96.9.128.0/18','PVNT Networks, #116 HE Rank (ASN-AS21788-4). '); //75a
$ax += cidrblock($address,'100.42.48.0/20','PVNT Networks, #116 HE Rank (ASN-AS21788-5). '); //75a
$ax += cidrblock($address,'108.175.144.0/20','PVNT Networks, #116 HE Rank (ASN-AS21788-6). '); //75a
$ax += cidrblock($address,'173.212.192.0/18','PVNT Networks, #116 HE Rank (ASN-AS21788-7). '); //75a
$ax += cidrblock($address,'184.22.0.0/16','PVNT Networks, #116 HE Rank (ASN-AS21788-8). '); //75a
$ax += cidrblock($address,'184.82.0.0/16','PVNT Networks, #116 HE Rank (ASN-AS21788-9). '); //75a
$ax += cidrblock($address,'198.58.80.0/20','PVNT Networks, #116 HE Rank (ASN-AS21788-10). '); //75a

// CariNet, Inc.  dedicated / cloud servers
// AS10439
// This is an optional block. Network does security scans for non-hostile purposes.
// Uncomment 5 lines below to activate.

//$ax += cidrblock($address,'66.240.192.0/18','CariNet, Inc. Not an access provider ISP. (ASN-CARINET-0). '); //75b
//$ax += cidrblock($address,'71.6.128.0/17','CariNet, Inc. Not an access provider ISP. (ASN-CARINET-1). '); //75b
//$ax += cidrblock($address,'209.126.128.0/17','CariNet, Inc. Not an access provider ISP. (ASN-CARINET-2). '); //75b
//$ax += cidrblock($address,'216.75.0.0/18','CariNet, Inc. Not an access provider ISP. (ASN-CARINET-3). '); //75b
//$ax += cidrblock($address,'216.98.128.0/19','CariNet, Inc. Not an access provider ISP. (ASN-CARINET-4). '); //75b

// BestHosting
// AS42655

$ax += cidrblock($address,'31.41.216.0/21','Network known to associate with malware, source: http://www.google.com/safebrowsing/diagnostic?site=AS:42655&hl=en (ASN-BESTHOSTING-0). '); //75b
$ax += cidrblock($address,'194.28.172.0/22','Network known to associate with malware, source: http://www.google.com/safebrowsing/diagnostic?site=AS:42655&hl=en (ASN-BESTHOSTING-1). '); //75b
$ax += cidrblock($address,'195.248.234.0/23','Network known to associate with malware, source: http://www.google.com/safebrowsing/diagnostic?site=AS:42655&hl=en (ASN-BESTHOSTING-2). '); //75b

///*** HOST EXPLOIT CYBERDEFCON REPORT RANGES ***

// These blocks are of the top 10 worst networks in the areas of Infected Hosts, spam,
// and attacks. Data is derived with deep respect, and gratefulness from:
// http://hostexploit.com/blog/14-reports/3543-world-hosts-report-september-2013.html
// http://robtex.com (for the BGP info)
// http://forums.modem-help.co.uk/aggregate.php for the data cleaning (Used elsewhere in this file too!)
// And igknight for the footwork http://www.igknight-photography.com/

// Note: Some ranges already in the main blocks, so they are not duplicated here.


// ** INFECTED WEB SITES

// Tata Institute
// AS132524
$ax += cidrblock($address,'158.144.28.0/23','Tata Institute, Bothost and/or Server Farm. Not an access provider ISP (ASN-AS132524-0). '); //75a
$ax += cidrblock($address,'158.144.32.0/22','Tata Institute, Bothost and/or Server Farm. Not an access provider ISP (ASN-AS132524-1). '); //75a

// Hostinger International
// AS47583
$ax += cidrblock($address,'31.170.160.0/21','Hostinger International, Bothost and/or Server Farm. Not an access provider ISP (ASN-AS47583-0). '); //75a
$ax += cidrblock($address,'31.220.0.0/17','Hostinger International, Bothost and/or Server Farm. Not an access provider ISP (ASN-AS47583-1). '); //75a
$ax += cidrblock($address,'93.188.160.0/21','Hostinger International, Bothost and/or Server Farm. Not an access provider ISP (ASN-AS47583-2). '); //75a
$ax += cidrblock($address,'185.28.20.0/22','Hostinger International, Bothost and/or Server Farm. Not an access provider ISP (ASN-AS47583-3). '); //75a
$ax += cidrblock($address,'212.1.208.0/21','Hostinger International, Bothost and/or Server Farm. Not an access provider ISP (ASN-AS47583-4). '); //75a

// Landis Holdings Inc
// AS11042 
$ax += cidrblock($address,'69.73.128.0/18','Landis Holdings Inc, Bothost and/or Server Farm. Not an access provider ISP (ASN-AS11042-0). '); //75a
$ax += cidrblock($address,'209.140.16.0/20','Landis Holdings Inc, Bothost and/or Server Farm. Not an access provider ISP (ASN-AS11042-1). '); //75a
$ax += cidrblock($address,'209.217.224.0/19','Landis Holdings Inc, Bothost and/or Server Farm. Not an access provider ISP (ASN-AS11042-2). '); //75a

// Dattatec.com
// AS27823
$ax += cidrblock($address,'200.58.96.0/19','Bothost and/or Server Farm. Not an access provider ISP (ASN-AS27823-0). '); //75a

// Vautron Rechenzentrum AG
// AS25504
$ax += cidrblock($address,'46.151.160.0/21','Bothost and/or Server Farm. Not an access provider ISP (ASN-AS25504-0). '); //75a
$ax += cidrblock($address,'83.243.56.0/21','Bothost and/or Server Farm. Not an access provider ISP (ASN-AS25504-1). '); //75a
$ax += cidrblock($address,'89.200.168.0/21','Bothost and/or Server Farm. Not an access provider ISP (ASN-AS25504-2). '); //75a
$ax += cidrblock($address,'91.198.21.0/24','Bothost and/or Server Farm. Not an access provider ISP (ASN-AS25504-3). '); //75a
$ax += cidrblock($address,'91.223.141.0/24','Bothost and/or Server Farm. Not an access provider ISP (ASN-AS25504-4). '); //75a
$ax += cidrblock($address,'91.223.145.0/24','Bothost and/or Server Farm. Not an access provider ISP (ASN-AS25504-5). '); //75a
$ax += cidrblock($address,'91.247.144.0/23','Bothost and/or Server Farm. Not an access provider ISP (ASN-AS25504-6). '); //75a
$ax += cidrblock($address,'94.102.208.0/20','Bothost and/or Server Farm. Not an access provider ISP (ASN-AS25504-7). '); //75a
$ax += cidrblock($address,'109.235.56.0/21','Bothost and/or Server Farm. Not an access provider ISP (ASN-AS25504-8). '); //75a
$ax += cidrblock($address,'151.252.48.0/20','Bothost and/or Server Farm. Not an access provider ISP (ASN-AS25504-9). '); //75a
$ax += cidrblock($address,'158.58.144.0/21','Bothost and/or Server Farm. Not an access provider ISP (ASN-AS25504-10). '); //75a
$ax += cidrblock($address,'193.150.4.0/23','Bothost and/or Server Farm. Not an access provider ISP (ASN-AS25504-11). '); //75a
$ax += cidrblock($address,'193.254.184.0/21','Bothost and/or Server Farm. Not an access provider ISP (ASN-AS25504-12). '); //75a
$ax += cidrblock($address,'195.191.92.0/23','Bothost and/or Server Farm. Not an access provider ISP (ASN-AS25504-13). '); //75a


// ** SPAM HOSTS

// Telecommunication Infrastructure Company
// AS48159
$ax += cidrblock($address,'2.144.0.0/14','Telecommunication Infrastructure Company, spammy network (ASN-AS48159-0). '); //75a
$ax += cidrblock($address,'2.176.0.0/12','Telecommunication Infrastructure Company, spammy network (ASN-AS48159-1). '); //75a ASN-PkT-06
$ax += cidrblock($address,'5.112.0.0/12','Telecommunication Infrastructure Company, spammy network (ASN-AS48159-2). '); //75a
$ax += cidrblock($address,'5.232.0.0/13','Telecommunication Infrastructure Company, spammy network (ASN-AS48159-3). '); //75a
$ax += cidrblock($address,'37.128.240.0/20','Telecommunication Infrastructure Company, spammy network (ASN-AS48159-4). '); //75a
$ax += cidrblock($address,'46.100.0.0/16','Telecommunication Infrastructure Company, spammy network (ASN-AS48159-5). '); //75a
$ax += cidrblock($address,'78.38.0.0/15','Telecommunication Infrastructure Company, spammy network (ASN-AS48159-6). '); //75a
$ax += cidrblock($address,'85.185.0.0/16','Telecommunication Infrastructure Company, spammy network (ASN-AS48159-7). '); //75a
$ax += cidrblock($address,'89.144.128.0/18','Telecommunication Infrastructure Company, spammy network (ASN-AS48159-8). '); //75a
$ax += cidrblock($address,'92.50.0.0/18','Telecommunication Infrastructure Company, spammy network (ASN-AS48159-9). '); //75a
$ax += cidrblock($address,'95.82.0.0/18','Telecommunication Infrastructure Company, spammy network (ASN-AS48159-10). '); //75a
$ax += cidrblock($address,'176.221.16.0/20','Telecommunication Infrastructure Company, spammy network (ASN-AS48159-11). '); //75a
$ax += cidrblock($address,'178.251.208.0/21','Telecommunication Infrastructure Company, spammy network (ASN-AS48159-12). '); //75a
$ax += cidrblock($address,'185.11.88.0/22','Telecommunication Infrastructure Company, spammy network (ASN-AS48159-13). '); //75a
$ax += cidrblock($address,'188.34.0.0/16','Telecommunication Infrastructure Company, spammy network (ASN-AS48159-14). '); //75a

// Telefonica del Peru S.A.A.
// AS6147
$ax += cidrblock($address,'96.6.128.0/17','Telefonica del Peru S.A.A., spammy network (ASN-AS6147-0). '); //75a
$ax += cidrblock($address,'181.64.0.0/14','Telefonica del Peru S.A.A., spammy network (ASN-AS6147-1). '); //75a
$ax += cidrblock($address,'181.224.200.0/22','Telefonica del Peru S.A.A., spammy network (ASN-AS6147-2). '); //75a
$ax += cidrblock($address,'181.224.224.0/19','Telefonica del Peru S.A.A., spammy network (ASN-AS6147-3). '); //75a
$ax += cidrblock($address,'184.24.0.0/13','Telefonica del Peru S.A.A., spammy network (ASN-AS6147-4). '); //75a
$ax += cidrblock($address,'190.40.0.0/14','Telefonica del Peru S.A.A., spammy network (ASN-AS6147-5). '); //75a
$ax += cidrblock($address,'190.232.0.0/13','Telefonica del Peru S.A.A., spammy network (ASN-AS6147-6). '); //75a
$ax += cidrblock($address,'200.4.192.0/18','Telefonica del Peru S.A.A., spammy network (ASN-AS6147-7). '); //75a
$ax += cidrblock($address,'200.10.64.0/19','Telefonica del Peru S.A.A., spammy network (ASN-AS6147-8). '); //75a
$ax += cidrblock($address,'200.10.188.0/24','Telefonica del Peru S.A.A., spammy network (ASN-AS6147-9). '); //75a
$ax += cidrblock($address,'200.11.48.0/20','Telefonica del Peru S.A.A., spammy network (ASN-AS6147-10). '); //75a
$ax += cidrblock($address,'200.37.0.0/16','Telefonica del Peru S.A.A., spammy network (ASN-AS6147-11). '); //75a
$ax += cidrblock($address,'200.48.0.0/16','Telefonica del Peru S.A.A., spammy network (ASN-AS6147-12). '); //75a
$ax += cidrblock($address,'200.60.0.0/16','Telefonica del Peru S.A.A., spammy network (ASN-AS6147-13). '); //75a
$ax += cidrblock($address,'200.106.0.0/17','Telefonica del Peru S.A.A., spammy network (ASN-AS6147-14). '); //75a
$ax += cidrblock($address,'200.107.128.0/18','Telefonica del Peru S.A.A., spammy network (ASN-AS6147-15). '); //75a
$ax += cidrblock($address,'200.121.0.0/16','Telefonica del Peru S.A.A., spammy network (ASN-AS6147-16). '); //75a
$ax += cidrblock($address,'201.230.0.0/16','Telefonica del Peru S.A.A., spammy network (ASN-AS6147-17). '); //75a
$ax += cidrblock($address,'201.240.0.0/16','Telefonica del Peru S.A.A., spammy network (ASN-AS6147-18). '); //75a

// Mobin Net Communication
// AS50810
$ax += cidrblock($address,'2.176.0.0/12','Mobin Net Communication, spammy network (ASN-AS50810-0). '); //75a
$ax += cidrblock($address,'5.52.0.0/16','Mobin Net Communication, spammy network (ASN-AS50810-1). '); //75a
$ax += cidrblock($address,'5.201.128.0/17','Mobin Net Communication, spammy network (ASN-AS50810-2). '); //75a
$ax += cidrblock($address,'31.47.32.0/19','Mobin Net Communication, spammy network (ASN-AS50810-3). '); //75a
$ax += cidrblock($address,'37.98.0.0/17','Mobin Net Communication, spammy network (ASN-AS50810-4). '); //75a
$ax += cidrblock($address,'79.175.128.0/18','Mobin Net Communication, spammy network (ASN-AS50810-5). '); //75a
$ax += cidrblock($address,'91.133.128.0/17','Mobin Net Communication, spammy network (ASN-AS50810-6). '); //75a
$ax += cidrblock($address,'130.255.192.0/18','Mobin Net Communication, spammy network (ASN-AS50810-7). '); //75a
$ax += cidrblock($address,'178.131.0.0/16','Mobin Net Communication, spammy network (ASN-AS50810-8). '); //75a
$ax += cidrblock($address,'185.3.124.0/22','Mobin Net Communication, spammy network (ASN-AS50810-9). '); //75a
$ax += cidrblock($address,'185.22.28.0/22','Mobin Net Communication, spammy network (ASN-AS50810-10). '); //75a

// Tata Indicom
// AS55740
$ax += cidrblock($address,'14.96.0.0/14','Tata Indicom, spammy network (ASN-AS55740-0). '); //75a

// sfip84
// AS57879
$ax += cidrblock($address,'37.143.48.0/20','Bothost and/or Server Farm. Not an access provider ISP (ASN-AS57879-0). '); //75a
$ax += cidrblock($address,'185.3.248.0/22','Bothost and/or Server Farm. Not an access provider ISP (ASN-AS57879-1). '); //75a

// Cablecision, S.A. de C.V.
// AS28548
$ax += cidrblock($address,'189.216.0.0/15','Cablecision, S.A. de C.V. spammy network (ASN-AS28548-0). '); //75a
$ax += cidrblock($address,'200.77.160.0/20','Cablecision, S.A. de C.V. spammy network (ASN-AS28548-1). '); //75a
$ax += cidrblock($address,'201.141.0.0/16','Cablecision, S.A. de C.V. spammy network (ASN-AS28548-2). '); //75a

// Comteco Ltda
// AS27839
$ax += cidrblock($address,'181.114.64.0/19','Comteco Ltda, spammy network (ASN-AS27839-0). '); //75a
$ax += cidrblock($address,'181.177.128.0/18','Comteco Ltda, spammy network (ASN-AS27839-1). '); //75a
$ax += cidrblock($address,'190.11.64.0/19','Comteco Ltda, spammy network (ASN-AS27839-2). '); //75a
$ax += cidrblock($address,'190.102.48.0/21','Comteco Ltda, spammy network (ASN-AS27839-3). '); //75a
$ax += cidrblock($address,'190.106.240.0/20','Comteco Ltda, spammy network (ASN-AS27839-4). '); //75a
$ax += cidrblock($address,'190.107.32.0/19','Comteco Ltda, spammy network (ASN-AS27839-5). '); //75a
$ax += cidrblock($address,'200.58.64.0/19','Comteco Ltda, spammy network (ASN-AS27839-6). '); //75a
$ax += cidrblock($address,'200.107.240.0/21','Comteco Ltda, spammy network (ASN-AS27839-7). '); //75a

// Three Hutchison
// AS45727
$ax += cidrblock($address,'23.0.0.0/12','Three Hutchison, spammy network (ASN-AS45727-0). '); //75a
$ax += cidrblock($address,'103.10.64.0/22','Three Hutchison, spammy network (ASN-AS45727-1). '); //75a
$ax += cidrblock($address,'180.214.232.0/22','Three Hutchison, spammy network (ASN-AS45727-2). '); //75a
$ax += cidrblock($address,'202.67.32.0/20','Three Hutchison, spammy network (ASN-AS45727-3). '); //75a
$ax += cidrblock($address,'223.255.224.0/21','Three Hutchison, spammy network (ASN-AS45727-4). '); //75a

// Esfahan Telecommunication
// AS58085
$ax += cidrblock($address,'37.254.0.0/15','Esfahan Telecommunication, spammy network (ASN-AS58085-0). '); //75a

// MTN SUDAN
// AS36972
$ax += cidrblock($address,'41.223.160.0/22','MTN SUDAN, spammy network (ASN-AS36972-0). '); //75a
$ax += cidrblock($address,'197.254.224.0/24','MTN SUDAN, spammy network (ASN-AS36972-1). '); //75a


// ** CURRENT EVENTS HOSTS (Exploit hacking)

// Leaseweb USA
// AS30633
$ax += cidrblock($address,'91.242.214.0/23','Leaseweb USA, known bad hosting provide, not an access provider ISP (ASN-AS30633-0). '); //75a
$ax += cidrblock($address,'108.59.0.0/20','Leaseweb USA, known bad hosting provide, not an access provider ISP (ASN-AS30633-1). '); //75a
$ax += cidrblock($address,'162.210.192.0/21','Leaseweb USA, known bad hosting provide, not an access provider ISP (ASN-AS30633-2). '); //75a
$ax += cidrblock($address,'162.219.212.0/22','Leaseweb USA, known bad hosting provide, not an access provider ISP (ASN-AS30633-3). '); //75a
$ax += cidrblock($address,'185.28.68.0/22','Leaseweb USA, known bad hosting provide, not an access provider ISP (ASN-AS30633-4). '); //75a
$ax += cidrblock($address,'192.96.200.0/21','Leaseweb USA, known bad hosting provide, not an access provider ISP (ASN-AS30633-5). '); //75a
$ax += cidrblock($address,'198.7.56.0/21','Leaseweb USA, known bad hosting provide, not an access provider ISP (ASN-AS30633-6). '); //75a
$ax += cidrblock($address,'199.58.84.0/22','Leaseweb USA, known bad hosting provide, not an access provider ISP (ASN-AS30633-7). '); //75a
$ax += cidrblock($address,'199.115.112.0/21','Leaseweb USA, known bad hosting provide, not an access provider ISP (ASN-AS30633-8). '); //75a
$ax += cidrblock($address,'207.244.64.0/18','Leaseweb USA, known bad hosting provide, not an access provider ISP (ASN-AS30633-9). '); //75a
$ax += cidrblock($address,'209.58.128.0/18','Leaseweb USA, known bad hosting provide, not an access provider ISP (ASN-AS30633-10). '); //75a
$ax += cidrblock($address,'209.192.128.0/17','Leaseweb USA, known bad hosting provide, not an access provider ISP (ASN-AS30633-11). '); //75a
$ax += cidrblock($address,'212.7.192.0/19','Leaseweb USA, known bad hosting provide, not an access provider ISP (ASN-AS30633-12). '); //75a

// Antarktida-Plus
// AS51699
// AS51699 has not been visible in the global routing table since September 17, 2013 (Report points out that AS51699 is normally #1 in this report)

// PE Shattah Zia G.Naman
// AS34023
$ax += cidrblock($address,'193.105.154.0/24','PE Shattah Zia G.Naman, known bad host (ASN-AS34023-0). '); //75a

// FriendFinder Networks
// AS32527
$ax += cidrblock($address,'69.165.96.0/20','FriendFinder Networks, known bad host (ASN-AS32527-0). '); //75a
$ax += cidrblock($address,'208.88.176.0/21','FriendFinder Networks, known bad host (ASN-AS32527-1). '); //75a

// City Telecom
// AS48271
$ax += cidrblock($address,'212.2.224.0/19','City Telecom, known bad host (ASN-AS48271-0). '); //75a

// O2 Sp. Z.O.O.
// AS31080
$ax += cidrblock($address,'193.17.41.0/24','O2 Sp. Z.O.O. known bad host (ASN-AS31080-0). '); //75a
$ax += cidrblock($address,'193.222.135.0/24','O2 Sp. Z.O.O. known bad host (ASN-AS31080-1). '); //75a

// Hostinger International
// AS47583
$ax += cidrblock($address,'31.170.160.0/21','Hostinger International, known bad host, not an access provider ISP (ASN-AS47583-0). '); //75a
$ax += cidrblock($address,'31.220.0.0/17','Hostinger International, known bad host, not an access provider ISP (ASN-AS47583-1). '); //75a
$ax += cidrblock($address,'93.188.160.0/21','Hostinger International, known bad host, not an access provider ISP (ASN-AS47583-2). '); //75a
$ax += cidrblock($address,'185.28.20.0/22','Hostinger International, known bad host, not an access provider ISP (ASN-AS47583-3). '); //75a
$ax += cidrblock($address,'212.1.208.0/21','Hostinger International, known bad host, not an access provider ISP (ASN-AS47583-4). '); //75a

// Excite Japan Co. LTD.
// AS45682
$ax += cidrblock($address,'180.235.96.0/21','Excite Japan Co. LTD. known bad host, not an access provider ISP (ASN-AS45682-0). '); //75a

// MediaFire LLC
// AS46179
$ax += cidrblock($address,'199.91.152.0/21','MediaFire LLC known bad host, not an access provider ISP (ASN-AS46179-0). '); //75a
$ax += cidrblock($address,'205.196.120.0/22','MediaFire LLC known bad host, not an access provider ISP (ASN-AS46179-1). '); //75a

// H1 LLC
// AS6870
$ax += cidrblock($address,'80.243.128.0/20','H1 LLC, known bad host (ASN-AS6870-0). '); //75a
$ax += cidrblock($address,'91.105.232.0/21','H1 LLC, known bad host (ASN-AS6870-1). '); //75a
$ax += cidrblock($address,'91.212.150.0/24','H1 LLC, known bad host (ASN-AS6870-2). '); //75a
$ax += cidrblock($address,'93.170.0.0/15','H1 LLC, known bad host (ASN-AS6870-3). '); //75a
$ax += cidrblock($address,'95.46.0.0/15','H1 LLC, known bad host (ASN-AS6870-4). '); //75a
$ax += cidrblock($address,'185.4.64.0/22','H1 LLC, known bad host (ASN-AS6870-5). '); //75a
$ax += cidrblock($address,'188.64.168.0/21','H1 LLC, known bad host (ASN-AS6870-6). '); //75a
$ax += cidrblock($address,'194.33.180.0/24','H1 LLC, known bad host (ASN-AS6870-7). '); //75a

///*** END HOST EXPLOIT CYBERDEFCON REPORT RANGES ***


// *More, and smaller bad networks to avoid...

$ax += cidrblock($address,'70.39.128.0/17','packetexchange is a cloud service, not an access provider. '); //75a

$ax += cidrblock($address,'91.236.74.0/23','ELAN-AS Spamslingers (ELAN-AS). '); //75a

$ax += cidrblock($address,'173.0.0.0/20','ProXPN, anonymous proxy/vpn network (ProXPN). '); //75a

$ax += cidrblock($address,'192.196.192.0/20','Siftlogic LLC is not authorized to access our server. '); //74d

$ax += cidrblock($address,'202.46.32.0/19','ShenZhen Sunrise Technology Co, bot like activity '); //74a fixed 74c

$ax += cidrblock($address,'67.198.128.0/20','Krypt Technologies'); //72b
$ax += cidrblock($address,'98.126.0.0/16','Krypt Technologies'); //72b

$ax += cidrblock($address,'31.170.16.0/21','Ad Technology SIA AS49191-1. '); //72d
$ax += cidrblock($address,'188.92.72.0/21','Ad Technology SIA AS49191-2. '); //72d

$ax += iprange($address,'195.216.160.0','195.216.191.255','a JUNIK. ');
$ax += iprange($address,'213.182.192.0','213.182.223.255','b JUNIK. ');

$ax += iprange($address,'87.245.192.0','87.245.255.255','RETN. ');

$ax += iprange($address,'64.116.161.0','64.116.161.255','a Eveloz. ');
$ax += iprange($address,'64.117.234.0','64.117.234.255','b Eveloz. ');
$ax += iprange($address,'190.122.160.0','190.122.175.255','c Eveloz. ');
$ax += iprange($address,'190.123.32.0','190.123.47.255','d Eveloz. ');
$ax += iprange($address,'200.63.40.0','200.63.47.255','e Eveloz. ');
$ax += iprange($address,'200.105.34.0','200.105.44.255','f Eveloz. ');
$ax += iprange($address,'200.115.128.0','200.115.159.255','g Eveloz. ');
$ax += iprange($address,'201.218.208.0','201.218.208.255','h Eveloz. ');

$ax += iprange($address,'66.186.0.0','66.186.31.255','a Alchemy Communications. ');
$ax += iprange($address,'66.226.0.0','66.226.31.255','b Alchemy Communications. ');
$ax += iprange($address,'72.26.96.0','72.26.127.255','c Alchemy Communications. ');
$ax += iprange($address,'205.144.160.0','205.144.175.255','d Alchemy Communications. ');
$ax += iprange($address,'208.76.216.0','208.76.219.255','e Alchemy Communications. ');
$ax += iprange($address,'208.118.48.0','208.118.63.255','f Alchemy Communications. ');
$ax += iprange($address,'209.132.192.0','209.132.255.255','g Alchemy Communications. ');
$ax += iprange($address,'216.250.112.0','216.250.127.255','h Alchemy Communications. ');

$ax += cidrblock($address,'46.229.160.0/20','Semrush Botnetwork (SEM-01). '); //74d

$ax += cidrblock($address,'46.19.168.0/23','Network has ethical issues (ASN-6Li-2H-0). '); //74d
$ax += cidrblock($address,'208.74.204.0/22','Network has ethical issues (ASN-6Li-2H-1). '); //74d

// END SECTION SKIP
}

// *RBN is the Russian Business Network, the internet's answer to the Chicago Outfit.
//  Mention a cybercrime, and they are up to their necks in it.

//  RBN Hostname Blocks

$ax += inmatch($hoster,'keyserver','RBN. ');
$ax += inmatch($hoster,'keymachine','RBN. ');
$ax += inmatch($hoster,'keyweb','RBN. ');
$ax += inmatch($hoster,'oliro','RBN. ');
$ax += inmatch($hoster,'filmefashion','RBN. ');
$ax += rmatch($hoster,'idknet.com','RBN. ');
$ax += rmatch($hoster,'poltava.ua','RBN. ');
$ax += rmatch($hoster,'utel.net.ua','RBN. ');
$ax += rmatch($hoster,'infobox.ru','RBN. ');
$ax += rmatch($hoster,'infobox.org','RBN. ');
$ax += rmatch($hoster,'vdswin.com','RBN. ');
$ax += rmatch($hoster,'rbn.com.ua','RBN. ');
$ax += rmatch($hoster,'hc.ru','RBN. ');
$ax += rmatch($hoster,'power-web34.net','RBN. ');
$ax += rmatch($hoster,'temka.biz','RBN. ');
$ax += rmatch($hoster,'dl-hosting.com','RBN. ');
$ax += rmatch($hoster,'tagdance.de','RBN. ');
$ax += rmatch($hoster,'efdns.de','RBN. ');
$ax += rmatch($hoster,'keyaccount.de','RBN. ');
$ax += rmatch($hoster,'ahost01.de','RBN. ');
$ax += rmatch($hoster,'em-zwo.de','RBN. ');
$ax += rmatch($hoster,'amplilogic.com','RBN. ');
$ax += rmatch($hoster,'creatoor.com','RBN. ');
$ax += rmatch($hoster,'x-svr.com','RBN. ');
$ax += rmatch($hoster,'keymars64.de','RBN. ');
$ax += rmatch($hoster,'haebdler-treff.de','RBN. ');
$ax += rmatch($hoster,'traders-briefing.de','RBN. ');
$ax += rmatch($hoster,'hosting-ie.com','RBN. ');
$ax += rmatch($hoster,'mail.adc.de','RBN. ');
$ax += rmatch($hoster,'ethymos.com.br','RBN. ');
$ax += rmatch($hoster,'softel.com.pl','RBN. ');
$ax += rmatch($hoster,'astranight.com','RBN. ');
$ax += rmatch($hoster,'ipilum.com','RBN. ');
$ax += rmatch($hoster,'vilitas.de','RBN. ');
$ax += rmatch($hoster,'rootbash.de','RBN. ');
$ax += rmatch($hoster,'securewebserver.de','RBN. ');
$ax += rmatch($hoster,'w-4.de','RBN. ');
$ax += rmatch($hoster,'corbina.ru','RBN. ');
$ax += rmatch($hoster,'prommorpg.com','RBN. ');
$ax += rmatch($hoster,'relan.ru','RBN. ');
$ax += rmatch($hoster,'volia.net','RBN. ');
$ax += rmatch($hoster,'dedibox.fr','RBN. ');
$ax += rmatch($hoster,'laycat.com','RBN. ');
$ax += rmatch($hoster,'kyklo.com','RBN. ');
$ax += rmatch($hoster,'aceleo.com','RBN. ');
$ax += rmatch($hoster,'majordomo.ru','RBN. ');
$ax += rmatch($hoster,'sovam.net.ua','RBN. ');
$ax += rmatch($hoster,'limt.ru','RBN. ');
$ax += rmatch($hoster,'netorn.ru','RBN. ');
$ax += rmatch($hoster,'netorn.net','RBN. ');
$ax += rmatch($hoster,'cpms.ru','RBN. ');
$ax += rmatch($hoster,'itns.ru','RBN. ');
$ax += rmatch($hoster,'kuzbass.net','RBN. ');
$ax += rmatch($hoster,'kemhost.net','RBN. ');
$ax += rmatch($hoster,'spb.ru','RBN. ');
$ax += rmatch($hoster,'elsv-v.ru','RBN. ');
$ax += rmatch($hoster,'cosmonova.net.ua','RBN. ');
$ax += rmatch($hoster,'borderfreehosting.com','RBN. ');
$ax += rmatch($hoster,'uxxicom.com','RBN. ');
$ax += rmatch($hoster,'starlogic.biz','RBN. ');
$ax += rmatch($hoster,'totalstat.ru','RBN. ');
$ax += rmatch($hoster,'hostrov.net','RBN. ');
$ax += rmatch($hoster,'nasza-klasa.pl','RBN. ');
$ax += rmatch($hoster,'datapoint.ru','RBN. ');
//$ax += rmatch($hoster,'orange.sk','RBN. '); Removed 74c, good behavior.
$ax += rmatch($hoster,'cssgroup.lv','RBN. ');
$ax += rmatch($hoster,'odessa.ua','RBN. ');
$ax += rmatch($hoster,'profithost.net','RBN. ');
$ax += rmatch($hoster,'mtu-net.ru','RBN. ');
$ax += rmatch($hoster,'volia.ua','RBN. ');
$ax += rmatch($hoster,'nigma.ru','RBN. '); //65c Sovintel


// RBN IP and IP Range Blocks 

$ax += iprange($address,'77.51.0.0','77.51.59.255','RBN. ');
$ax += iprange($address,'77.92.88.0','77.92.89.255','RBN. ');
$ax += iprange($address,'77.105.0.0','77.105.63.255','RBN. ');
$ax += iprange($address,'78.24.24.234','78.25.191.255','RBN. '); //split 72
$ax += iprange($address,'78.26.0.0','78.26.255.255','RBN. '); //split 72
$ax += iprange($address,'78.37.128.0','78.37.191.255','RBN. ');
$ax += iprange($address,'78.110.175.0','78.110.175.255','RBN. ');
$ax += iprange($address,'78.129.202.0','78.129.203.255','RBN. ');
$ax += iprange($address,'78.157.140.0','78.157.143.255','RBN. ');
$ax += iprange($address,'79.174.64.0','79.174.95.255','RBN. ');
$ax += iprange($address,'79.175.64.0','79.175.127.255','RBN. ');
// $ax += iprange($address,'81.23.0.0','81.23.47.255','RBN. '); // split 71h disposed 74e
// $ax += iprange($address,'81.23.64.0','81.24.127.255','RBN. '); // split 71h disposed 74a
$ax += iprange($address,'83.167.98.0','83.167.100.255','RBN. ');
$ax += iprange($address,'83.167.104.0','83.167.109.255','RBN. ');
$ax += iprange($address,'83.167.127.0','83.167.127.255','RBN. ');
$ax += iprange($address,'85.249.0.0','85.251.255.255','RBN. ');
$ax += iprange($address,'89.108.64.0','89.108.127.255','RBN. ');
$ax += iprange($address,'89.113.72.0','89.113.79.255','RBN. ');
$ax += iprange($address,'89.254.192.0','89.254.255.255','RBN. ');
$ax += iprange($address,'91.204.72.0','91.204.75.255','RBN. ');
$ax += iprange($address,'91.205.65.0','91.205.127.255','RBN. ');
$ax += iprange($address,'91.205.168.0','91.205.168.255','RBN. ');
$ax += cidrblock($address,'91.212.124.0/24','RBN. ');
$ax += iprange($address,'91.212.196.0','91.212.255.255','RBN. ');
$ax += iprange($address,'92.38.128.0','92.38.255.255','RBN. ');
$ax += iprange($address,'92.241.0.0','92.241.191.255','RBN. ');
$ax += iprange($address,'93.174.88.0','93.174.94.255','RBN. ');
$ax += iprange($address,'94.102.48.0','94.102.51.255','RBN. ');
$ax += iprange($address,'94.142.128.0','94.142.129.255','RBN. ');
$ax += iprange($address,'94.181.0.0','94.181.255.255','RBN. ');
$ax += iprange($address,'109.121.0.0','109.121.63.255','RBN. ');
$ax += iprange($address,'188.134.0.0','188.134.15.255','RBN. ');
$ax += iprange($address,'193.53.87.0','193.53.89.255','RBN. ');
$ax += cidrblock($address,'193.105.210.0/24','RBN. '); //70e
$ax += iprange($address,'193.109.248.0','193.109.249.255','RBN. ');
$ax += iprange($address,'193.189.126.0','193.189.127.255','RBN. ');
$ax += iprange($address,'194.106.188.0','194.106.191.255','RBN. ');
$ax += iprange($address,'194.165.42.0','194.165.42.255','RBN. ');
$ax += iprange($address,'195.2.252.0','195.2.253.255','RBN. ');
$ax += iprange($address,'195.88.0.0','195.88.255.255','RBN. ');
$ax += iprange($address,'195.189.80.0','195.189.83.255','RBN. ');
$ax += iprange($address,'208.64.24.0','208.64.27.255','RBN. ');
$ax += iprange($address,'212.15.65.0','212.15.255.255','RBN. ');
$ax += iprange($address,'212.152.60.128','212.152.63.255','RBN. ');
$ax += iprange($address,'213.219.192.0','213.219.255.255','RBN. ');
$ax += iprange($address,'213.248.0.0','213.248.63.255','RBN. ');



// *HTTP_Referer Scans

// http_referer bombs

$ax += inmatch($fromhost,'<? ','Php Script Execution Attempt (REF-001). '); //71a split
$ax += inmatch($fromhost,'<?php','Php Script Break Attempt (REF-002). '); //71a changed
$ax += inmatch($fromhost,'drop table','SQL injection attempt (REF-003). ');
$ax += inmatch($fromhost,' href','http url injection (REF-004). ');
$ax += inmatch($fromhost,'<iframe','iframe injection (REF-005). ');
$ax += inmatch($fromhost,'<script','http javascript (wedge end/script start) injection (REF-006). ');
$ax += inmatch($fromhost,'/script>','http javascript (wedge start/script end) injection (REF-007). ');
$ax += lmatch($fromhost,';','RFI attack/SQL injection thru referer logging (REF-008). ');
$ax += inmatch($fromhost,'[url=','bbcode URL injection (REF-009). ');
$ax += inmatch($fromhost,'[/url','bbcode URL injection (REF-010). ');
$ax += inmatch($fromhostsws,'code(','REFEX 01. '); //70a
$ax += inmatch($fromhostsws,'unction(','REFEX 02. '); //70a
$ax += inmatch($fromhostsws,'nt(','REFEX 03. '); //70a
$ax += inmatch($fromhostsws,'ex(','REFEX 04. '); //70a
$ax += inmatch($fromhostsws,'eregi(','REFEX 05. '); //70a
$ax += inmatch($fromhostsws,'if(','REFEX 06. '); //70a
$ax += inmatch($fromhostsws,'exists(','REFEX 07. '); //70a
$ax += inmatch($fromhost,'drop table','REFEX 08. '); //70a
$ax += inmatch($fromhostsws,'while(','REFEX 09. '); //70a
$ax += inmatch($fromhostsws,'start(','REFEX 10. '); //70a
$ax += inmatch($fromhostsws,'restore(','REFEX 11. '); //70a
$ax += inmatch($fromhostsws,'open(','REFEX 12. '); //70a
$ax += inmatch($fromhostsws,'contents(','REFEX 13. '); //70a
$ax += inmatch($fromhostsws,'escape(','REFEX 14. '); //70a
$ax += inmatch($fromhostsws,'write(','REFEX 15. '); //70a
$ax += inmatch($fromhostsws,'_once(','REFEX 16. '); //70a
$ax += inmatch($fromhostsws,"_once'",'REFEX 16.1. '); //72b
$ax += inmatch($fromhostsws,'_once"','REFEX 16.2. '); //72b
$ax += inmatch($fromhostsws,'_once$','REFEX 16.3. '); //74b
$ax += inmatch($fromhostsws,'_once<','REFEX 16.4. '); //74b
$ax += inmatch($fromhostsws,'ereg(','REFEX 17. '); //70a
$ax += inmatch($fromhostsws,'rot13(','REFEX 18. '); //70a
$ax += inmatch($fromhostsws,'plode(','REFEX 19. '); //70a
$ax += inmatch($fromhostsws,'ashes(','REFEX 20. '); //70a
$ax += inmatch($fromhostsws,'place(','REFEX 21. '); //70a
$ax += inmatch($fromhostsws,'puts(','REFEX 23. '); //70a
$ax += inmatch($fromhostsws,'read(','REFEX 24. '); //70a
//$ax += inmatch($fromhostsws,'file(','REFEX 25. '); //70a pending removal 71b
$ax += inmatch($fromhostsws,'able(','REFEX 26. '); //70a
$ax += inmatch($fromhostsws,'getc(','REFEX 27. '); //70a
$ax += inmatch($fromhostsws,'getcsv(','REFEX 28. '); //70a
$ax += inmatch($fromhostsws,'gets(','REFEX 29. '); //70a
$ax += inmatch($fromhostsws,'getss(','REFEX 30. '); //70a
$ax += inmatch($fromhostsws,'exec(','REFEX 31. '); //70a
$ax += inmatch($fromhostsws,'gzinflate(','REFEX 32. '); //70a
$ax += inmatch($fromhostsws,'thru(','REFEX 33. '); //70a
$ax += inmatch($fromhostsws,'echo(','REFEX 34. '); //70a
$ax += inmatch($fromhostsws,'system(','REFEX 35. '); //70a
$ax += inmatch($fromhostsws,'include(','REFEX 36. '); //70a
$ax += inmatch($fromhostsws,"include'",'REFEX 36.1. '); //72b
$ax += inmatch($fromhostsws,'include"','REFEX 36.2. '); //72b
$ax += inmatch($fromhostsws,'include$','REFEX 36.3. '); //74b
$ax += inmatch($fromhostsws,'include<','REFEX 36.4. '); //74b
$ax += inmatch($fromhostsws,'require(','REFEX 37. '); //70a
$ax += inmatch($fromhostsws,"require'",'REFEX 37.1. '); //72b
$ax += inmatch($fromhostsws,'require"','REFEX 37.2. '); //72b
$ax += inmatch($fromhostsws,'require$','REFEX 37.3. '); //74b
$ax += inmatch($fromhostsws,'require<','REFEX 37.4. '); //74b
$ax += inmatch($fromhostsws,'asc(','REFEX 38. '); //70c
$ax += inmatch($fromhostsws,'chr(','REFEX 39. '); //70c
$ax += inmatch($fromhostsws,'len(','REFEX 40. '); //70c
$ax += inmatch($fromhostsws,'length(','REFEX 41. '); //70c
$ax += inmatch($fromhostsws,"('')",'REFEX 43. '); //70c
$ax += inmatch($fromhostsws,'("")','REFEX 44. '); //70c
$ax += minmatch($fromhost,'`',1,'Backtick execution attempt detected REFEX-45. '); //72b
$ax += inmatch($fromhostsws,'eval(','REFEX 46. '); //72b
$ax += inmatch($fromhostsws,'assert(','REFEX 47. '); //72b
$ax += inmatch($fromhostsws,'function(','REFEX 48. '); //72b
$ax += inmatch($fromhostsws,'unserialize(','REFEX 49. '); //72b
$ax += inmatch($fromhostsws,'dotnet_load(','REFEX 50. '); //72b
$ax += inmatch($fromhostsws,'$_GET[','REFEX 51. '); //72b
$ax += inmatch($fromhost,'.php++','Referer code injection thru referer logging attempt, ++ after php, should be ? or + (REF-011). ');
$ax += inmatch($fromhost,'result:+%0','Unprintable ASCII Injection/Execution attempt thru referer logging (REF-012). ');
$ax += inmatch($fromhost,'result:+%1','Unprintable ASCII Injection/Execution attempt thru referer logging (REF-013). ');
$ax += inmatch($fromhost,'result:+%8','Unprintable ASCII Injection/Execution attempt thru referer logging (REF-014). ');
$ax += inmatch($fromhost,'result:+%9','Unprintable ASCII Injection/Execution attempt thru referer logging (REF-015). ');
$ax += inmatch($fromhost,'result:+%a','Unprintable ASCII Injection/Execution attempt thru referer logging (REF-016). ');
$ax += inmatch($fromhost,'result:+%b','Unprintable ASCII Injection/Execution attempt thru referer logging (REF-017). ');
$ax += inmatch($fromhost,'result:+%c','Unprintable ASCII Injection/Execution attempt thru referer logging (REF-018). ');
$ax += inmatch($fromhost,'result:+%d','Unprintable ASCII Injection/Execution attempt thru referer logging (REF-019). ');
$ax += inmatch($fromhost,'result:+%e','Unprintable ASCII Injection/Execution attempt thru referer logging (REF-020). ');
$ax += inmatch($fromhost,'result:+%f','Unprintable ASCII Injection/Execution attempt thru referer logging (REF-021). ');
$ax += inmatch($fromhost,'%0','Unprintable ASCII Illegal in URL (REF-022). '); //70c
$ax += inmatch($fromhost,'%1','Unprintable ASCII Illegal in URL (REF-023). '); //70c



// If coming from own site, skip these spam word detections. 56e

$temp = 'http://' . $thishost ;
$temp2 = 'https://' . $thishost ;
if (!(substr_count($fromhost,$temp) || substr_count($fromhost,$temp2) || substr_count($fromhost,'http://www.facebook.com') || substr_count($fromhost,'http://www.google.') || substr_count($fromhost,'http://search.yahoo.com/search'))){

  //modified in 66h for sloppy referring hosts.

  // Bad Referrers

  $ax += inmatch($fromhost,'filseclab','Firewall pollutes serverlogs with spam ads (BADREF-001). ');
  $ax += inmatch($fromhost,'web-ads','General HTTP_REFERER spam detection, please paste address in fresh window/tab and try again (BADREF-002). ');
  $ax += inmatch($fromhost,'investblog',"Investment scam, we don't link from there (BADREF-003). ");
  $ax += inmatch($fromhost,'aimtrust',"Investment scam, we don't link from there (BADREF-004). ");
  $ax += inmatch($fromhost,'justfree.com','Referer spam, just gone (BADREF-005). ');
  $ax += inmatch($fromhost,'cat-tree-house.com','Referer spam (BADREF-006). ');
  $ax += inmatch($fromhost,'cash-blog','Referer spam cash-blog, cashed-out (BADREF-007). ');
  $ax += inmatch($fromhost,'iforexvideo','Referer spam cash-blog, i-for-ex-you (BADREF-008). ');
  $ax += inmatch($fromhost,'bankinfodata.net','Referer spam cash-blog, i-for-ex-you (BADREF-009). ');
  $ax += inmatch($fromhost,'mskhirakurves','You came from a http_referer slandering pharmacy scam/porn/linksite (BADREF-010). ');
  $ax += inmatch($fromhost,'healingstartswithus','You came from a http_referer slandering pharmacy scam/porn/linksite (BADREF-011). ');
  $ax += inmatch($fromhost,'sobacos','You came from a http_referer slandering pharmacy scam/porn/linksite (BADREF-012). ');
  $ax += inmatch($fromhost,'icetv.ru','You came from a http_referer slandering pharmacy scam/porn/linksite (BADREF-013). ');
  $ax += inmatch($fromhost,'gayxzone','You came from a http_referer slandering pharmacy scam/porn/linksite (BADREF-014). ');
  $ax += inmatch($fromhost,'.xzone','You came from a http_referer slandering pharmacy scam/porn/linksite (BADREF-015). ');
  $ax += inmatch($fromhost,'pyce.info','You came from a http_referer slandering pharmacy scam/porn/linksite (BADREF-016). ');
  $ax += inmatch($fromhost,'dvd5.com.ua','You came from a http_referer slandering pharmacy scam/porn/linksite (BADREF-017). ');
  $ax += inmatch($fromhost,'facialforum.net','You came from a http_referer slandering pharmacy scam/porn/linksite (BADREF-018). ');
  $ax += inmatch($fromhost,'doctoryuval.com','You came from a http_referer slandering pharmacy scam/porn/linksite (BADREF-019). ');
  $ax += inmatch($fromhost,'eyeglassesonlineshop','You came from a http_referer slandering pharmacy scam/porn/linksite (BADREF-020). ');
  $ax += inmatch($fromhost,'webscutest.com','You came from a http_referer slandering pharmacy scam/porn/linksite (BADREF-021). ');
  $ax += inmatch($fromhost,'powernetshop.at','You came from a http_referer slandering pharmacy scam/porn/linksite (BADREF-022). ');
  $ax += inmatch($fromhost,'adultfriendfinder','You came from a http_referer slandering pharmacy scam/porn/linksite (BADREF-023). ');
  $ax += inmatch($fromhost,'starlogic.biz','Referer spamming for customers is a bad idea - bogus hosting RBN (BADREF-024). ');
  $ax += inmatch($fromhost,'typegetrich','Type and get rich? Not if we can help it. Go away kid, ya bother me (BADREF-025). ');
  $ax += inmatch($fromhost,'3w1.eu','Strange Polish referer spam. Not linked from there. Claims to be a pagerank site (BADREF-026). ');
  $ax += inmatch($fromhost,'refblock.com',"Bad referer. Anonymity is a bad thing in the security industry. Come in straight, or don't come at all (BADREF-027). ");
  $ax += inmatch($fromhost,'netvibes.com','You came from a http_referer slandering pharmacy scam/porn/linksite (BADREF-028). '); //65c
  $ax += inmatch($fromhost,'trafficfaker.com','Traffic faking, stat swelling, referer dropping, not welcome here (BADREF-029). '); //70b
  $ax += inmatch($fromhost,'evuln.com','Vulnerability Scanner (BADREF-030). '); //72a
  $ax += inmatch($fromhost,'autosurf','No automatic surfing please (BADREF-031). '); //73b
  $ax += regexmatch($fromhost,":80(?:\D|$)",'Bad http_referer! (BADREF-032). '); //74c
//  $ax += inmatch($fromhost,'diesel.net.ru','Known refspam host found in HTTP_REFERER, please paste URL in a new browser window (BADREF-033). '); //74c
//  $ax += inmatch($fromhost,'rustelekom.net','Known refspam host found in HTTP_REFERER, please paste URL in a new browser window (BADREF-034). '); //74c
  $ax += inmatch($fromhost,'massagemiracle','Referer Spam detected. Have a happy ending (BADREF-034). '); //74d
  $ax += inmatch($fromhost,'myyogamassage','Referer Spam detected. Have a happy ending (BADREF-036). '); //74d
  $ax += inmatch($fromhost,'killmalware.com','Vulnerability Scanner (BADREF-037). '); //74d
  $ax += inmatch($fromhost,'deltasearch','<b>HTTP_REFERER detection of MALWARE Delta Search. Your machine is heavily infected with MALWARE. Please go to http://malwaretips.com/blogs/delta-virus-removal/ and follow the removal instructions before you try to access this site, or use any password on your system again! This site has blocked you to protect your login.</b> (BADREF-038.0). '); //74d
  $ax += inmatch($fromhost,'delta-search','<b>HTTP_REFERER detection of MALWARE Delta Search. Your machine is heavily infected with MALWARE. Please go to http://malwaretips.com/blogs/delta-virus-removal/ and follow the removal instructions before you try to access this site, or use any password on your system again! This site has blocked you to protect your login.</b> (BADREF-038.1). '); //74d
  $ax += minmatch($fromhost,'http://',2,'You came from way too many websites at once! (BADREF-039). '); //74d
  $ax += inmatch($fromhost,'netcomber.com','You came from a site which provides this site no benefit (BADREF-040). '); //74d
  

// Scan words.

  $ax += inmatch($fromhost,'pharma.','You came from a http_referer slandering pharmacy scam/porn/linksite (REFSPAM-001). ');
  $ax += inmatch($fromhost,'drugstore','You came from a http_referer slandering pharmacy scam/porn/linksite (REFSPAM-002). ');
  $ax += inmatch($fromhost,'drugs.com/','You came from a http_referer slandering pharmacy scam/porn/linksite (REFSPAM-003). ');
  if (!((inmatch($fromhost,'ssex','')) || (inmatch($fromhost,'middlessex','')))){$ax += inmatch($fromhost,'sex.','You came from a http_referer slandering pharmacy scam/porn/linksite (REFSPAM-004). ');}
  if (!((inmatch($fromhost,'ssex','')) || (inmatch($fromhost,'middlessex','')))){$ax += inmatch($fromhost,'.sex','You came from a http_referer slandering pharmacy scam/porn/linksite (REFSPAM-005). ');}
  $ax += inmatch($fromhost,'adult.','You came from a http_referer slandering pharmacy scam/porn/linksite (REFSPAM-006). ');
  $ax += inmatch($fromhost,'.adult','You came from a http_referer slandering pharmacy scam/porn/linksite (REFSPAM-007). ');
  $ax += inmatch($fromhost,'drugs-','You came from a http_referer slandering pharmacy scam/porn/linksite (REFSPAM-008). ');
  $ax += inmatch($fromhost,'.box.net','You came from a http_referer slandering pharmacy scam/porn/linksite (REFSPAM-009). '); //67b
  $ax += inmatch($fromhost,'meet-women','You came from a http_referer slandering pharmacy scam/porn/linksite (REFSPAM-010). ');
  $ax += inmatch($fromhost,'-24h.','HTTP_REFERER pollution of serverlogs with spam ad word -24h., we do not link from there (REFSPAM-011). ');
  $ax += inmatch($fromhost,'pillz','HTTP_REFERER pollution of serverlogs with spam ad word pillz, we do not link from there (REFSPAM-012). ');
  $ax += inmatch($fromhost,'geriforte','HTTP_REFERER pollution of serverlogs with spam ad word geriforte, we do not link from there (REFSPAM-013). ');
  $ax += inmatch($fromhost,'derma','HTTP_REFERER pollution of serverlogs with spam ad word derma, we do not link from there (REFSPAM-014). ');
  $ax += inmatch($fromhost,'vitol','HTTP_REFERER pollution of serverlogs with spam ad word vitol, we do not link from there (REFSPAM-015). ');
  $ax += inmatch($fromhost,'laxative','HTTP_REFERER pollution of serverlogs with spam ad word laxative, we do not link from there (REFSPAM-016). ');
  $ax += inmatch($fromhost,'ginkgo','HTTP_REFERER pollution of serverlogs with spam ad word ginkgo, we do not link from there (REFSPAM-017). ');
  $ax += inmatch($fromhost,'ginko','HTTP_REFERER pollution of serverlogs with spam ad word ginko, we do not link from there (REFSPAM-018). ');
  $ax += inmatch($fromhost,'biloba','HTTP_REFERER pollution of serverlogs with spam ad word biloba, we do not link from there (REFSPAM-019). ');
  $ax += inmatch($fromhost,'melaleuca','HTTP_REFERER pollution of serverlogs with spam ad word melaleuca, we do not link from there (REFSPAM-020). ');
  $ax += inmatch($fromhost,'levitra','HTTP_REFERER pollution of serverlogs with spam ad word levitra, we do not link from there (REFSPAM-021). ');
  $ax += inmatch($fromhost,'nolvadex','HTTP_REFERER pollution of serverlogs with spam ad word nolvadex, we do not link from there (REFSPAM-022). ');
  $ax += inmatch($fromhost,'paxil','HTTP_REFERER pollution of serverlogs with spam ad word paxil, we do not link from there (REFSPAM-023). ');
  $ax += inmatch($fromhost,'plavix','HTTP_REFERER pollution of serverlogs with spam ad word paxil, we do not link from there (REFSPAM-024). ');
  $ax += inmatch($fromhost,'deltasone','HTTP_REFERER pollution of serverlogs with spam ad word deltasone, we do not link from there (REFSPAM-025). ');
  $ax += inmatch($fromhost,'sterapred','HTTP_REFERER pollution of serverlogs with spam ad word sterapred, we do not link from there (REFSPAM-026). ');
  $ax += inmatch($fromhost,'synthroid','HTTP_REFERER pollution of serverlogs with spam ad word synthroid, we do not link from there (REFSPAM-027). ');
  $ax += inmatch($fromhost,'lipitor','HTTP_REFERER pollution of serverlogs with spam ad word lipitor, we do not link from there (REFSPAM-028). ');
  $ax += inmatch($fromhost,'lexap','HTTP_REFERER pollution of serverlogs with spam ad word lexap, we do not link from there (REFSPAM-029). ');
  $ax += inmatch($fromhost,'cialis ','HTTP_REFERER pollution of serverlogs with spam ad word cialis, we do not link from there (REFSPAM-030). ');
  $ax += inmatch($fromhost,'viagra','HTTP_REFERER pollution of serverlogs with spam ad word viagra, we do not link from there (REFSPAM-031). ');
  $ax += inmatch($fromhost,'porn','HTTP_REFERER pollution of serverlogs with spam ad word porn, we do not link from there (REFSPAM-032). ');
  $ax += inmatch($fromhost,'pr0n','HTTP_REFERER pollution of serverlogs with spam ad word pr0n, we do not link from there (REFSPAM-033). ');
  $ax += inmatch($fromhost,'boob','HTTP_REFERER pollution of serverlogs with spam ad word boob, we do not link from there (REFSPAM-034). ');
  $ax += inmatch($fromhost,'tentacle','HTTP_REFERER pollution of serverlogs with spam ad word tentacle, we do not link from there (REFSPAM-035). ');
  $ax += inmatch($fromhost,'slimy','HTTP_REFERER pollution of serverlogs with spam ad word slimy, we do not link from there (REFSPAM-036). ');
  $ax += inmatch($fromhost,'hentai','HTTP_REFERER pollution of serverlogs with spam ad word hentai, we do not link from there (REFSPAM-037). ');
  $ax += inmatch($fromhost,'cigar','HTTP_REFERER pollution of serverlogs with spam ads ad word cigar, we do not link from there (REFSPAM-038). ');
//  $ax += inmatch($fromhost,'smoke','HTTP_REFERER pollution of serverlogs with spam ads ad word smoke, we do not link from there (REFSPAM-039). '); //Removed 71
  $ax += inmatch($fromhost,'menthol','HTTP_REFERER pollution of serverlogs with spam ads ad word smoke, we do not link from there (REFSPAM-040). ');
  $ax += inmatch($fromhost,'propecia','HTTP_REFERER pollution of serverlogs with spam ads ad word propecia, we do not link from there (REFSPAM-041). ');
  $ax += inmatch($fromhost,'rogaine','HTTP_REFERER pollution of serverlogs with spam ads ad word rogaine, we do not link from there (REFSPAM-042). ');
  $ax += inmatch($fromhost,'erotic','HTTP_REFERER pollution of serverlogs with spam ads ad word erotic, we do not link from there (REFSPAM-043). ');
  $ax += inmatch($fromhost,'erotik','HTTP_REFERER pollution of serverlogs with spam ads ad word erotik, we do not link from there (REFSPAM-044). ');
  $ax += inmatch($fromhost,'lesbian','HTTP_REFERER pollution of serverlogs with spam ads ad word lesbian, we do not link from there (REFSPAM-045). ');
  $ax += inmatch($fromhost,'bdsm','HTTP_REFERER pollution of serverlogs with spam ads ad word bdsm, we do not link from there (REFSPAM-046). ');
  $ax += inmatch($fromhost,'lolita','HTTP_REFERER pollution of serverlogs with spam ads ad word lolita, we do not link from there (REFSPAM-047). ');
  $ax += inmatch($fromhost,'nude','HTTP_REFERER pollution of serverlogs with spam ads ad word nude, we do not link from there (REFSPAM-048). ');
  $ax += inmatch($fromhost,' kiddy','HTTP_REFERER pollution of serverlogs with spam ads ad word kiddy, we do not link from there (REFSPAM-049). ');
  $ax += inmatch($fromhost,'bestiality','HTTP_REFERER pollution of serverlogs with spam ads ad word bestiality, we do not link from there (REFSPAM-050). ');
  $ax += inmatch($fromhost,'beastiality','HTTP_REFERER pollution of serverlogs with spam ads ad word beastiality, we do not link from there (REFSPAM-051). ');
  $ax += inmatch($fromhost,'shemale','HTTP_REFERER pollution of serverlogs with spam ads ad word shemale, we do not link from there (REFSPAM-052). ');
  $ax += inmatch($fromhost,'incest','HTTP_REFERER pollution of serverlogs with spam ads ad word incest, we do not link from there (REFSPAM-053). ');
  $ax += inmatch($fromhost,'neurontin','HTTP_REFERER pollution of serverlogs with spam ads ad word neurontin, we do not link from there (REFSPAM-054). ');
  $ax += inmatch($fromhost,'gabapentin','HTTP_REFERER pollution of serverlogs with spam ads ad word gabapentin, we do not link from there (REFSPAM-055). ');
  $ax += inmatch($fromhost,'avelox','HTTP_REFERER pollution of serverlogs with spam ads ad word avelox, we do not link from there (REFSPAM-056). '); //65c
  $ax += inmatch($fromhost2,'/TOPSITES','HTTP_REFERER pollution of serverlogs with spam ads ad word topsites, we do not link from there (REFSPAM-057). ');
  $ax += inmatch($fromhost,'naked','HTTP_REFERER pollution of serverlogs with spam ads ad word naked, we do not link from there (REFSPAM-058). '); //70d
  $ax += inmatch($fromhost,'finddotcom','HTTP_REFERER pollution of serverlogs with spam ad for finddotcom.com (REFSPAM-059). ');
  $ax += inmatch($fromhost,'kamagra','HTTP_REFERER pollution of serverlogs with spam ad word kamagra, we do not link from there (REFSPAM-060). ');
  $ax += inmatch($fromhost,'liker.profile','liker.profile HTTP_REFERER spam-stuffer detection (REFSPAM-061). '); //74a
  $ax += inmatch($fromhost,'prosti','HTTP_REFERER pollution of serverlogs with spam ad word prosti, we do not link from there (REFSPAM-062). '); //74a
  $ax += inmatch($fromhost,'forex','HTTP_REFERER pollution of serverlogs with spam ad word forex, we do not link from there (REFSPAM-063). '); //74a
  $ax += inmatch($fromhost,'xanax','HTTP_REFERER pollution of serverlogs with spam ad word xanax, we do not link from there (REFSPAM-064). '); //74a

}

// $_POST parsing...

// Check Ajax Opt-Out outside of whitlisting protection.

if($zbajaxoptout){
  $ax += inmatch($querydec,'aatestaa','AJAX opt-out active test. ');
}


// Look for variables being misset.

if ($zbwhitelisted != 1){

// * Next section only runs if ajax_optout is set to true in zbblock.ini

  if($zbajaxoptout){

    $ax += inmatch($rawpost,'<','POST unescaped < POST-008. ');
    $ax += inmatch($rawpost,'>','POST unescaped > POST-009. ');
    $ax += inmatch($rawpost,'(','POST unescaped ( POST-010. ');
    $ax += inmatch($rawpost,')','POST unescaped ) POST-011. ');
    $ax += inmatch($rawpost,'"','POST unescaped " POST-012. ');
    $ax += inmatch($rawpost,"'","POST unescaped ' POST-013. ");
    $ax += inmatch($rawpost,';','POST unescaped ; POST-014. ');
    $ax += inmatch($rawpost,'#','POST unescaped # POST-057. ');
    $ax += inmatch($rawpost,"echo'","POST print attempt POST-033. ");
    $ax += inmatch($rawpostsws,'wgethttp://','POST RFI POST-034. ');
    $ax += inmatch($rawpostsws,'lwp-downloadhttp://','POST RFI POST-035. ');
    $ax += inmatch($rawpostsws,'fetchhttp://','POST RFI POST-036. ');
    $ax += inmatch($rawpostsws,'wgetftp://','POST RFI POST-037. ');
    $ax += inmatch($rawpost,'lwp-download ftp://','POST RFI POST-038. ');
    $ax += inmatch($rawpost,'fetch ftp://','POST RFI POST-039. ');
    $ax += inmatch($rawpost,'wget https://','POST RFI POST-040. ');
    $ax += inmatch($rawpost,'lwp-download https://','POST RFI POST-041. ');
    $ax += inmatch($rawpostsws,'fetchhttps://','POST RFI POST-042. ');
    $ax += inmatch($rawpostsws,'<methodCall>','POST RFI POST-044. ');
    $ax += inmatch($rawpostsws,'<methodcall>','POST RFI POST-045. ');
    $ax += inmatch($rawpostsws,'<methodName>','POST RFI POST-046. ');
    $ax += inmatch($rawpostsws,'<methodname>','POST RFI POST-047. ');
    $ax += inmatch($rawpostsws,'<params>','POST RFI POST-048. ');
    $ax += inmatch($rawpostsws,'<param>','POST RFI POST-049. ');
    $ax += inmatch($rawpostsws,'<value>','POST RFI POST-050. ');
    $ax += inmatch($rawpostsws,'<name>','POST RFI POST-051. ');
	$ax += inmatch($rawpost,"=[\\",'POST BBCESC POST-054. ');  //63d moved 71
	$ax += inmatch($rawpost,'%5C]','POST BBCESC POST-055. '); //63d moved 71
	$ax += inmatch($rawpostsws,'()','POST EX POST-095. '); //70c moved 71
  }

// * These should be good for all.

  $ax += inmatch($lcpost,'&path=http','POST RFI POST-001. ');
  $ax += inmatch($lcpost,'&path=ftp','POST RFI POST-002. ');
  $ax += inmatch($lcpost,'&path=gopher','POST RFI POST-003. ');
  $ax += inmatch($lcpost,'&path=mms','POST RFI POST-004. ');
  $ax += inmatch($lcpost,'&path=rstp','POST RFI POST-005. ');
  $ax += inmatch($lcpost,'&path=rtp','POST RFI POST-006. ');
  $ax += inmatch($lcpost,'&path=telnet','POST RFI POST-007. ');
  $ax += inmatch($rawpostsws,'=ftp:','POST RFI POST-002.1. ');
  $ax += inmatch($rawpostsws,'=gopher:','POST RFI POST-003.1 . ');
  $ax += inmatch($rawpostsws,'=mms:','POST RFI POST-004.1 . ');
  $ax += inmatch($rawpostsws,'=rstp:','POST RFI POST-005.1 . ');
  $ax += inmatch($rawpostsws,'=rtp:','POST RFI POST-006.1 . ');
  $ax += inmatch($rawpostsws,'=telnet:','POST RFI POST-007.1 . ');
  $ax += inmatch($rawpostsws,'eval(','POST EX POST-015. ');
  $ax += inmatch($rawpostsws,'assert(','POST EX POST-015.1. '); //72b
  $ax += inmatch($rawpostsws,'gzinflate(','POST CLOAK POST-016. ');
  $ax += inmatch($rawpostsws,'thru(','POST EX POST-018. '); //67c Strengthened
  $ax += inmatch($rawpostsws,'echo(','POST EX POST-019. ');
  $ax += inmatch($rawpostsws,'system(','POST EX POST-020. ');
  if(!((lmatch($requesturi,'/mobiquo/mobiquo.php','tapatalk bypasssssss. ')) || lmatch($requesturi,'/forum/mobiquo/mobiquo.php','tapatalk bypasssssss. ') )){
    $ax += inmatch($rawpost,'<? ','POST EX POST-021. '); //71a split
    $ax += inmatch($rawpost,'<?php','POST EX POST-022. '); //71a changed
  }
  $ax += inmatch($lcpost,'&modez=','POST BOTCOM POST-023. ');
  $ax += inmatch($lcpost,'=shellz','POST BOTCOM POST-024. ');
  $ax += inmatch($lcpost,'=scannerz','POST BOTCOM POST-025. ');
  $ax += inmatch($lcpost,'=botz','POST BOTCOM POST-026. ');
  $ax += inmatch($lcpost,'=psybnc','POST BOTCOM POST-027. ');
  $ax += inmatch($rawpostsws,'include(','POST RFI POST-028. ');
  $ax += inmatch($rawpostsws,"include'",'POST RFI POST-028.1. '); //72b
  $ax += inmatch($rawpostsws,'include"','POST RFI POST-028.2. '); //72b
  $ax += inmatch($rawpostsws,'include$','POST RFI POST-028.3. '); //74b
  $ax += inmatch($rawpostsws,'include<','POST RFI POST-028.4. '); //74b
  $ax += inmatch($rawpostsws,'php_uname(','POST INJ POST-029. ');
  $ax += inmatch($rawpostsws,'exec(','POST EX POST-030. ');
  $ax += inmatch($rawpost,'=%5Bphp%5D','POST BBCEX POST-031.0. '); // Codefix/Split 63d
  $ax += inmatch($rawpost,'=%5bphp%5d','POST BBCEX POST-031.1. '); // Codefix/Split 63d
  $ax += inmatch($lcpost,'=[php]','POST BBCEX POST-032. '); // Search variable changed 63d
  $ax += inmatch($rawpostsws,'require(','POST RFI POST-052. '); //63a
  $ax += inmatch($rawpostsws,"require'",'POST RFI POST-052.1. '); //72b
  $ax += inmatch($rawpostsws,'require"','POST RFI POST-052.2. '); //72b
  $ax += inmatch($rawpostsws,'require$','POST RFI POST-052.3. '); //74b
  $ax += inmatch($rawpostsws,'require<','POST RFI POST-052.4. '); //74b
  $ax += inmatch($rawpost,"\\]",'POST BBCESC escaping POST-053. '); //63d
  $ax += inmatch($rawpost,"=[\\",'POST BBCESC POST-054. ');  //63d
  $ax += inmatch($rawpost,'%5C]','POST BBCESC POST-055. '); //63d
  $ax += inmatch($rawpost,'=[%5C','POST BBCESC POST-056. '); //63d
  $ax += inmatch($rawpostsws,'<script','POST JS POST-058. '); //66a
  $ax += inmatch($rawpostsws,'</script','POST JS POST-059. '); //66a
  $ax += inmatch($rawpostsws,'unction(','POST EX POST-060. '); //66a
  $ax += inmatch($rawpostsws,'nt(','POST EX POST-061. '); //66a
  $ax += inmatch($rawpostsws,'varstopit=','POST INJ POST-062. '); //66a
  $ax += inmatch($rawpostsws,'ex(','POST EX POST-063. '); //66b
  $ax += inmatch($rawpostsws,'eregi(','POST EX POST-064. '); //66b
  $ax += inmatch($rawpostsws,'if(','POST EX POST-065. '); //66b
  $ax += inmatch($rawpostsws,'exists(','POST EX POST-066. '); //67a strengthened
  $ax += inmatch($rawpostsws,'while(','POST EX POST-068. '); //66b
  $ax += inmatch($rawpostsws,'start(','POST EX POST-069. '); //67a strengthened
  $ax += inmatch($rawpostsws,'restore(','POST EX POST-070. '); //67a strengthened
  $ax += inmatch($rawpostsws,'open(','POST EX POST-072. '); //67a strengthened
  $ax += inmatch($rawpostsws,'contents(','POST EX POST-073. '); //66d
  $ax += inmatch($rawpostsws,'escape(','POST CLOAK POST-074. '); //66d
  $ax += inmatch($rawpostsws,'write(','POST EX POST-075. '); //66d
  $ax += inmatch($rawpostsws,'_once(','POST EX POST-076. '); //66o
  $ax += inmatch($rawpostsws,'_once"','POST EX POST-076.1. '); //72b
  $ax += inmatch($rawpostsws,"_once'",'POST EX POST-076.2. '); //72b
  $ax += inmatch($rawpostsws,'_once$','POST EX POST-076.3. '); //74b
  $ax += inmatch($rawpostsws,'_once<','POST EX POST-076.4. '); //74b
  $ax += inmatch($rawpostsws,'ereg(','POST EX POST-077. '); //67a
  $ax += inmatch($rawpostsws,'rot13(','POST CLOAK POST-078. '); //67c
  $ax += inmatch($rawpostsws,'plode(','POST CLOAK POST-079. '); //67c
  $ax += inmatch($rawpostsws,'ashes(','POST CLOAK POST-080. '); //67c
  $ax += inmatch($rawpostsws,'place(','POST CLOAK POST-081. '); //67c
  $ax += inmatch($rawpostsws,'puts(','POST EX POST-083. '); //67c
  $ax += inmatch($rawpostsws,'read(','POST EX POST-084. '); //67c
  $ax += inmatch($rawpostsws,'file(','POST EX POST-085. '); //67c
  $ax += inmatch($rawpostsws,'able(','POST EX POST-086. '); //67c
  $ax += inmatch($rawpostsws,'getc(','POST EX POST-087. '); //67c
  $ax += inmatch($rawpostsws,'getcsv(','POST EX POST-088. '); //67c
  $ax += inmatch($rawpostsws,'gets(','POST EX POST-089. '); //67c
  $ax += inmatch($rawpostsws,'getss(','POST EX POST-090. '); //67c
  $ax += inmatch($rawpostsws,'asc(','POST EX POST-091. '); //70c
  $ax += inmatch($rawpostsws,'chr(','POST EX POST-092. '); //70c
  $ax += inmatch($rawpostsws,'len(','POST EX POST-093. '); //70c
  $ax += inmatch($rawpostsws,'length(','POST EX POST-094. '); //70c
  $ax += inmatch($rawpostsws,"('')",'POST EX POST-096. '); //70c
  $ax += inmatch($rawpostsws,'("")','POST EX POST-097. '); //70c
  $ax += inmatch($rawpost,'8585072011','POST CRASH ATTEMPT POST-098. Please break death number with spaces every 3 chars. '); //69c shortened
  $ax += inmatch($rawpostsws,'<pre ','POST EX POST-099. '); //71c
  $ax += inmatch($rawpostsws,'/pre>','POST EX POST-100. '); //71c
  $ax += inmatch($rawpostsws,'charcode(88,83,83)','XSS Attempt, please break Char and Code apart with an x. POST-101. '); //71d
  $ax += minmatch($rawpost,'`',1,'Backtick execution attempt detected POST-102. '); //72b
  $ax += inmatch($rawpostsws,'function(','POST EX POST-103. '); //72b
  $ax += inmatch($rawpostsws,'unserialize(','POST EX POST-104. '); //72b
  $ax += inmatch($rawpostsws,'dotnet_load(','POST EX POST-105. '); //72b
  $ax += inmatch($rawpostsws,'$_GET[','POST EX POST-106. '); //72b
  $ax += regexmatch($rawpost,"(?:6\D*1\D*6\D*6\D*9\D*4\D*7\D*8\D*5)",'Spam detection (POST-107). '); //74d
  }

// *Filename Captures, mostly useful for those that hook their 404 page - 74d

$reqfilearr = explode('?',$lcrequesturi,2);
if (lmatch($reqfilearr[0],'/','')){
  // Illegal filename checks begin here

  $ax += inmatch($reqfilearr[0],'*','Wildcard found in URL (FNAME-01). '); //74d

  // Illegal filename checks end here
}


// *Bot INSTA-BANs

$ax += inmatch($rawpostsws,'&author_name=%5b','Bot Detection, INSTA-BAN (IB-001). '); //69d (strengthened)
$ax += inmatch($rawpostsws,'&author_name=[','Bot Detection, INSTA-BAN (IB-002). '); //69d (strengthened)
$ax += inmatch($dblrequesturidec,'/././','Bot Detection, INSTA-BAN (IB-003). '); //69b mod 74a, 74b
$ax += inmatch($dblrequesturidec,'/../../','Bot Detection, INSTA-BAN (IB-004). '); //69b mod 74a, 74b
$ax += inmatch($dblrequesturidec,'//.//.//','Bot Detection, INSTA-BAN (IB-005). '); //69b mod 74a, 74b
$ax += inmatch($dblrequesturidec,'//..//..//','Bot Detection, INSTA-BAN (IB-006). '); //69b mod 74a, 74b
$ax += inmatch($dblrequesturidec,"\\.\\.\\",'Bot Detection, INSTA-BAN (IB-007). '); //71b mod 74a, 74b
$ax += inmatch($dblrequesturidec,"\\..\\..\\",'Bot Detection, INSTA-BAN (IB-008). '); //71b mod 74a, 74b
$ax += inmatch($dblrequesturidec,"\\\\.\\\\.\\\\",'Bot Detection, INSTA-BAN (IB-009). '); //71b mod 74a, 74b
$ax += inmatch($dblrequesturidec,"\\\\..\\\\..\\\\",'Bot Detection, INSTA-BAN (IB-010). '); //71b mod 74a, 74b
$ax += inmatch($lcuseragent,'windows 95','Windows 95 is unusable. Bot Detection, INSTA-BAN (IB-011). ');
$ax += inmatch($querydec,'phpbb_path]','Path hack. INSTA-BAN (IB-012). '); //69c
$ax += rmatch($querydec,'p=test??','Robot Probe. INSTA-BAN (IB-013). '); //70b
$ax += inmatch($lcpostsws,'query_string=insertinto','Hack attempt, INSTA-BAN (IB-014). '); //70b
$ax += inmatch($querydec,'action=execute','Hack attempt, INSTA-BAN (IB-015). '); //70b
$ax += inmatch($lcuseragent,'ourbrowser','Abusive spider, INSTA-BAN (IB-016). '); //70c
$ax += inmatch($lcuseragent,'(some name)','Abusive spider, INSTA-BAN (IB-017). '); //70c
//if((inmatch($lcpostsws,'"pma_config"','')) && (inmatch($lcpostsws,'"source"',''))){$ax = 1; $whyblockout = $whyblockout . 'You nutcase! I told you not to quote that post! You should be INSTA - BANNED, but this will just be your warning (IB-018). ';} //71a
if((inmatch($lcpostsws,'"pma_config"','')) && (inmatch($lcpostsws,'"source"',''))){$ax = 1; $whyblockout = $whyblockout . 'Hack detection. PMA-1 (IB-019). ';} //71a
if(($hoster == 'localhost') && ($address != '127.0.0.1')){$ax += 1; $whyblockout = $whyblockout . 'Local host spoof attack. INSTA-BAN (IB-020). ';}
if($hoster == '.'){$ax += 1; $whyblockout = $whyblockout . 'Domain error. INSTA-BAN (IB-21). ';} //71c
if((inmatch($querydec,'union','')) && (inmatch($querydec,'select','')) && (inmatch($querydec,'jos_users',''))){ $ax += 1; $whyblockout = $whyblockout . 'INSTA-BAN (IB-022). ';} //70d
$ax += inmatch($querydec,'0x31303235343830303536','Blind poke detected. INSTA-BAN (IB-023). '); //71a
$ax += inmatch($requesturi,'.bak.php','Bot Detection, INSTA-BAN (IB-024). '); //71b
// $ax += rmatch($hoster,'adsl','Fake tld. INSTA-BAN (IB-025). '); //71b REMOVED 72b due to reliance of questionable DNS.
$ax += inmatch($rawpostsws,"('zwnobyai",'Injector. INSTA-BAN (IB-026). '); //71b
$ax += inmatch($rawpostsws,'("zwnobyai','Injector. INSTA-BAN (IB-027). '); //71b
$ax += inmatch($rawpostsws,"('awyoznvu",'Injector. INSTA-BAN (IB-028). '); //71d
$ax += inmatch($rawpostsws,'("awyoznvu','Injector. INSTA-BAN (IB-029). '); //71d
//$ax += lmatch($querydec,'-','PHP hack probing attempt. INSTA-BAN (IB-030). '); //71d Moved back to (QU-253)
$ax += inmatch($query2,'?-','PHP hack probing attempt. INSTA-BAN (IB-031). '); //71d
$ax += inmatch($query2,'&-','PHP hack probing attempt. INSTA-BAN (IB-032). '); //71d
$ax += lmatch($rawpost,'/?-','PHP hack probing attempt. INSTA-BAN (IB-033). '); //71d
$ax += inmatch($rawpostsws,'code(','POST CLOAK POST-071. INSTA-BAN (IB-034). '); //69a strengthened 71b strengthened futher
$ax += inmatch($dblrequesturidec,'/proc/self','Bot Detection, INSTA-BAN (IB-0035). '); //74b
$ax += inmatch($dblrequesturidec,'/etc/passwd','Bot Detection, INSTA-BAN (IB-0036). '); //74b
$ax += inmatch($dblrequesturidec,'/ucp./ucp.','Bot Detection, INSTA-BAN (IB-0037). '); //74b
$ax += inmatch($dblrequesturidec,'/hnap1/','Home Network Administration Protocol, INSTA-BAN  (IB-0038). '); //74c
$ax += inmatch($dblrequesturidec,'/teadevinfo/','D-Link Router firmware files, INSTA-BAN  (IB-0039). '); //74c
$ax += inmatch($dblrequesturidec,'/phppath','Bot Detection, INSTA-BAN (IB-0040.0). '); //74c mod 74d
$ax += inmatch($dblrequesturidec,'phppath/','Bot Detection, INSTA-BAN (IB-0040.1). '); //74c mod 74d
$ax += inmatch($lcrequesturi,'-d+','Hack Detection, INSTA-BAN (IB-0041). '); //74c
$ax += inmatch($dblrequesturidec,'writetofile.php','Hack Detection, INSTA-BAN (IB-0042). '); //74c mod 74d
$ax += inmatch($dblrequesturidec,'pst.php','Hack Detection, INSTA-BAN (IB-0043). '); //74c mod 74d
$ax += inmatch($dblrequesturidec,'/scripts','Hack Detection, INSTA-BAN (IB-0044.0). '); //74c mod 74d
$ax += inmatch($dblrequesturidec,'scripts/','Hack Detection, INSTA-BAN (IB-0044.1). '); //74c mod 74d
$ax += inmatch($dblrequesturidec,'mysqldumper','Hack Detection, INSTA-BAN (IB-0045). '); //74d
$ax += inmatch($dblrequesturidec,'w00tw00t','Hack Detection, INSTA-BAN (IB-0046). '); //74d
$ax += inmatch($dblrequesturidec,'anti-sec','Hack Detection, INSTA-BAN (IB-0047). '); //74d
$ax += inmatch($dblrequesturidec,'nosuichfile','Hack Detection, INSTA-BAN (IB-0048). '); //74d
$ax += inmatch($dblrequesturidec,'/adobe/','Hack Detection, INSTA-BAN (IB-0049). '); //74d
$ax += inmatch($dblrequesturidec,'/vood','Hack Detection, INSTA-BAN (IB-0050). '); //74d
$ax += inmatch($dblrequesturidec,'jmx-console','Hack Detection, INSTA-BAN (IB-0051). '); //74d
$ax += inmatch($dblrequesturidec,'e9xmkgg5h6','Hack Detection, INSTA-BAN (IB-0052). '); //74d
$ax += inmatch($requesturi,'/get?mac','Hacking attempt, INSTA-BAN (IB-0053). '); //74d
$ax += inmatch($requesturi,'/get?fwversion','Hacking attempt, INSTA-BAN (IB-0054). '); //74d
$ax += inmatch($requesturi,'shrift.php','Hacking attempt, INSTA-BAN (IB-0055). '); //74d
$ax += inmatch($serialpost,'a'.':2:{s:3:"log";s:5:"admin";s:3:"pwd";s:0:"";}','Hacking attempt, INSTA-BAN (IB-0057). '); //74d
$ax += inmatch($serialpost,'s'.':19:"print-439573653*57;"','Hacking attempt, INSTA-BAN (IB-0058). '); //74d
//if (!(rmatch($requesturi,'/wp-admin/options.php',''))){$ax += inmatch($serialpost,'s'.':3:"asc";','Hacking attempt, INSTA-BAN (IB-0059). ');} //74d mothballed 75c
$ax += inmatch($serialpost,'s'.':3:"cmd";','Hacking attempt, INSTA-BAN (IB-0060). '); //74d
$ax += inmatch($serialpost,'s'.':3:"dir";','Hacking attempt, INSTA-BAN (IB-0061). '); //74d
$ax += inmatch($serialpost,'s'.':3:"php";','Hacking attempt, INSTA-BAN (IB-0063). '); //74d
$ax += inmatch($querydec,'&version=1576','Joomla Hack attempt, INSTA-BAN (IB-0064). '); //75a
$ax += inmatch($rawpostsws,'@$_['.']=@!+_','Oh, so you think you are cute? INSTA-BAN for trying to inject a backdoor! (IB-0065.0). '); //74e mod 75d
$ax += inmatch($rawpostsws,'$_['.'$__','Oh, so you think you are cute? INSTA-BAN for trying to inject a backdoor! (IB-0065.1). '); //74e mod 75d
$ax += lmatch($rawpost,'/â\\x80¦x.php','Bot Probe INSTA-BAN (IB-0066.0). '); //75a
$ax += lmatch($requesturi,'/%E2%80%A6x.php','Bot Probe INSTA-BAN (IB-0066.1). '); //75a
$ax += lmatch($rawpost,'json={"fn":"folderRename"','Bot Attack INSTA-BAN (IB-0067). '); //75b
$ax += inmatch($requesturi,'/cfide/','Hacking attempt, INSTA-BAN (IB-0068). '); //75b



// Phishing for wp-config
$ax += regexmatch($requesturi,"wp-config\.(?:bak|old|orig|php|save)",'Phishing WordPress config file. INSTA-BAN (IB-0045). ');

// *Bot Commands
$ax += inmatch($querydec,'modez=','Common bot command qualifier. INSTA-BAN (CMD-01). '); //69c uprated to insta-ban.
$ax += inmatch($querydec,'=shellz','Common bot command. INSTA-BAN (CMD-02). '); //69c uprated to insta-ban.
$ax += inmatch($querydec,'=scannerz','Common bot command. INSTA-BAN (CMD-03). '); //69c uprated to insta-ban.
$ax += inmatch($querydec,'=botz','Common bot command. INSTA-BAN (CMD-04). '); //69c uprated to insta-ban.
$ax += inmatch($querydec,'=psybnc','Common bot command. INSTA-BAN (CMD-05). '); //69c uprated to insta-ban.
$ax += inmatch($querydec,'tasya=','Common bot command. INSTA-BAN (CMD-06). '); //72a
$ax += inmatch($querydec,'osc=','Common bot command. INSTA-BAN (CMD-07). '); //72a
$ax += inmatch($query,'?cmd=','Nesting attack. Remote bot command mode (CMD-08). INSTA-BAN. '); //69c
$ax += inmatch($query,'?&cmd=','Nesting attack. Remote bot command mode (CMD-09). INSTA-BAN. '); //69c
$ax += inmatch($query,'?&','Nesting attack. Malformed. INSTA-BAN (CMD-10). '); //69c


// *SPECIAL SIGNATURES

if (count($_REQUEST) >= 500){$ax += 1; $whyblockout = $whyblockout . 'Hack attempt. Over 500 variables ingested. INSTA-BAN. REDLIST. ';} //70e Adjusted up 73b

// *Test Triggers to test functions. (Errors will abort processing before here)

/// Quoting turns off the post check xtestx
if (!(substr_count($rawpost,'%22xxtestxx%22') > 0)){
  $ax += inmatch($rawpost,'xxtestxx','POST Test Trigger to test function. '); //66n
}

$ax += inmatch($query,'xtestx','QUERY Test Trigger to test function. '); //error in 66n
$ax += minmatch($query,'mtestm',1,'Test Trigger to test multiple match function. ');

?>