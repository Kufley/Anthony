<?php if (file_exists($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php')) require($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php'); ?>        <!--FOOTER AREA START-->
        <div class="footer_area clearfix">
        	<div class="west_islip">Anthony Wilson, RD, MS</div>
            <div class="footer_nav">
            	<a href="index.php">Home</a>  |  
                <a href="about-anthony.php">About Anthony</a>  |  
                <a href="services.php">Services</a>  |  
                <a href="coaching-programs.php">Coaching Programs</a>  |  
                <a href="weight-loss-articles.php">Weight Loss Articles</a>  |
                <a href="success.php">Success Stories</a>  |
                <a href="contactus.php">Contact Anthony</a>
            </div>
            <div class="reserved_area">	
         	<div class="reserved_left">All Copyright <?php echo @date('Y');?>. &copy; Reserved Anthony Wilson Consulting</div>
            <div class="reserved_right">
            	Web Development <a href="http://Wisitech.com" target="_blank">Wisitech</a>
            </div>
         </div>
            <div class="west_islip">
                DISCLAIMER: This site does not provide medical advice, diagnosis, or treatment. The services and information on this site are for informational purposes only and do not constitute medical advice or a recommendation for your specific condition or situation. Consult with your primary care physician and get approval from them before you make any changes to your lifestyle and before starting any exercise, nutrition, diet, or weight loss program.
				<p>*Anthony Wilson Consulting reserves the right to deny a free consultation to anyone for any reason.</p>
            </div>
        </div>
        <!--FOOTER AREA END-->
    </div>
    <!----------->
    <div id="content">Scroll &darr;</div>
<a href="#" id="back-to-top" title="Back to top">&uarr;</a>
<style>
    #back-to-top {
    position: fixed;
    bottom: 40px;
    right: 40px;
    z-index: 9999;
    width: 32px;
    height: 32px;
    text-align: center;
    line-height: 30px;
    background: #f5f5f5;
    color: #444;
    cursor: pointer;
    border: 0;
    border-radius: 2px;
    text-decoration: none;
    transition: opacity 0.2s ease-out;
    opacity: 0;
}
#back-to-top:hover {
    background: #e9ebec;
}
#back-to-top.show {
    opacity: 1;
}
#content {
    height: 2000px;
}
</style>
<script>
if ($('#back-to-top').length) {
    var scrollTrigger = 100, // px
        backToTop = function () {
            var scrollTop = $(window).scrollTop();
            if (scrollTop > scrollTrigger) {
                $('#back-to-top').addClass('show');
            } else {
                $('#back-to-top').removeClass('show');
            }
        };
    backToTop();
    $(window).on('scroll', function () {
        backToTop();
    });
    $('#back-to-top').on('click', function (e) {
        e.preventDefault();
        $('html,body').animate({
            scrollTop: 0
        }, 700);
    });
}
</script>
    <!----------->
          
  <!--Start Script from here-->
    <script src="<?php echo $config['site_url'];?>js/scroll/jquery-ui-1.8.21.custom.min.js"></script>
<script src="<?php echo $config['site_url'];?>js/scroll/jquery.mousewheel.min.js"></script>
<script src="<?php echo $config['site_url'];?>js/scroll/jquery.mCustomScrollbar.js"></script>
    <script type="text/javascript" src="<?php echo $config['site_url'];?>js/bootstrap.min.js"></script> 
<script>
    $(document).ready(function() {

            setTimeout(function () {
                var id = '#dialog';

//Get the screen height and width
                var maskHeight = $(document).height();
                var maskWidth = $(window).width();

//Set heigth and width to mask to fill up the whole screen
                $('#mask').css({'width': maskWidth, 'height': maskHeight});

//transition effect
                $('#mask').fadeIn(500);


//Get the window height and width
                var winH = $(window).height();
                var winW = $(window).width();

//Set the popup window to center
                $(id).css('top', winH / 2 - $(id).height() / 2);
                $(id).css('left', winW / 2 - $(id).width() / 2);

//transition effect
                $(id).fadeIn(1000);

//if close button is clicked
                $('.window .close').click(function (e) {
//Cancel the link behavior
                    e.preventDefault();

                    $('#mask').hide();
                    $('.window').hide();
                });

//if mask is clicked
                $('#mask').click(function () {
                    $(this).hide();
                    $('.window').hide();
                });
            }, 10000);
    });

  (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
  (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
  m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
  })(window,document,'script','//www.google-analytics.com/analytics.js','ga');

  ga('create', 'UA-52084741-1', 'weightlosshappens.com');
  ga('send', 'pageview');

</script>

<script src="<?php echo $config['site_url'];?>js/owl.carousel.js"></script> 

<script src="<?php echo $config['site_url'];?>js/jquery.mCustomScrollbar.concat.min.js"></script>
</body>
</html>
