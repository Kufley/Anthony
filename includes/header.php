<?php if (file_exists($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php')) require($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php'); ?>
<?php include($config['absolute_path'].'includes/meta.php'); ?>
<link href="<?php echo $config['site_url'];?>css/anthony_wilson.css" rel="stylesheet" type="text/css" />
<link href="<?php echo $config['site_url'];?>fonts/stylesheet.css" rel="stylesheet" type="text/css" />
<link href='http://fonts.googleapis.com/css?family=Abel' rel='stylesheet' type='text/css' />
<link href="https://fonts.googleapis.com/css?family=Open+Sans:300,400,600,700,800" rel="stylesheet">
<!--<link href="--><?php //echo $config['site_url'];?><!--css/bootstrap.css" rel="stylesheet"/>-->
<!--START FOR BANNER SLIDESHOW -->
<link rel="shortcut icon" href="images/favicon.ico" type="image/x-icon" />

<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js"></script>

<script src="<?php echo $config['site_url'];?>js/jquery.cross-slide.js" type="text/javascript"></script>
<script type="text/javascript" src="<?php echo $config['site_url'];?>js/banner.js" ></script>

<!--END FOR BANNER SLIDESHOW -->
<!--NILBDNETWORK.COM-->
<script type="text/javascript">
  var _gaq = _gaq || [];
  _gaq.push(['_setAccount', 'UA-37814635-1']);
  _gaq.push(['_trackPageview']);
  (function() {
    var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
    ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
  })();
</script>
<!--NILBDNETWORK.COM-->
<script src="<?php echo $config['site_url'];?>js/script.js"></script> 
<script type="text/javascript" src="<?php echo $config['site_url'];?>js/dcommon_functions_usingjq.js"></script>
    <script type="text/javascript" src="<?php echo $config['site_url'];?>scroll/jsscroll.js"></script>
    <link rel="stylesheet" href="<?php echo $config['site_url'];?>scroll/scroll.css" type="text/css" />
    <?php include_once('popup_manager/open_popup_js.php');?>
<link href="<?php echo $config['site_url'];?>popup_manager/popup.css" rel="stylesheet" type="text/css" />

<!--START FOR JQUERY SCROLL-->
<link href="<?php echo $config['site_url'];?>js/scroll/style/jquery.mCustomScrollbar.css" rel="stylesheet" type="text/css" />

<!--END FOR JQUERY SCROLL-->

<link href="<?php echo $config['site_url'];?>css/style-new.css" rel="stylesheet" type="text/css" />
<script>
    (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
            (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
        m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
    })(window,document,'script','https://www.google-analytics.com/analytics.js','ga');

    ga('create', 'UA-88227544-1', 'auto');
    ga('send', 'pageview');

</script>

</head>

<body>
<div id="wrapper">
	<div id="container" class="container-wrapper">
    	<!--HEADER AREA START-->
    	<div class="header clearfix">
        
        	<div class="header_left">
            	<div class="header_top"><a href="index.php">Weight Loss Happens</a></div>
                <div class="header_bottom"><a href="index.php">With The Right Strategy!</a></div>
            </div>
            
            
            <div class="header_right">
            	<a href="free-consultation.php"><img src="<?php echo $config['site_url'];?>images/free_consultation.png" alt="free_consultation" border="0" /></a>
            </div>
        </div>
		<div class="header-white"></div>
        <!--HEADER AREA END-->
        
        <!--BANNER AREA START-->
        <div class="banner">
            <div class="banner01"><div id="fadeshow1"></div></div>
            <div class="banner01"><div id="fadeshow2"></div></div>
            <div class="banner01"><div id="fadeshow3"></div></div>
            <div class="banner01"><div id="fadeshow4"></div></div>
            <div class="banner01"><div id="fadeshow5"></div></div>
            <div class="banner01"><div id="fadeshow6"></div></div>
            <div class="banner01"><div id="fadeshow7"></div></div>
        </div>
        <!--BANNER AREA END-->
        
        <!--TOP MENU AREA START-->
         <div class="top_menu_area">
             <div class="top_nav">
                 <ul>
                    <li> <a id="home" href="index.php">Home</a></li>
                    <li> <a id="about_anthony" href="about-anthony.php">About Anthony</a></li>
                    <li> <a id="services" href="services.php">Services</a></li>
                    <li> <a id="executive_weight_loss" href="coaching-programs.php">Weight Loss Coaching Programs</a></li>
                    <li> <a id="weight_loss_articles" href="weight-loss-articles.php">Articles</a></li>
                    <li> <a id="successst" href="success.php">Success Stories</a></li>
                    <li> <a id="contactus" href="contactus.php">Contact Anthony</a></li>
                 </ul>
                
            </div>
        
        </div>
        <!--TOP MENU AREA END-->