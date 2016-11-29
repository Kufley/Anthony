<?php if (file_exists($_SERVER['DOCUMENT_ROOT'] . '/zblock/zbblock.php')) require($_SERVER['DOCUMENT_ROOT'] . '/zblock/zbblock.php'); ?><?php
require_once('include/mainConnect.php');
require_once($config['absolute_path'] . 'classes/main.php');
include('includes/header.php');
?>  


<!--CONTENT AREA START-->
<div class="content_area">
    <div class="med_area">
        <div class="med_arealeft">
            <div class="meetanthony_area">
                <div class="registered_area">
                    <div class="inner_hed">
                        Oops! Page Not Found
                    </div>
                </div>


                <!--start contact_box-->
                <div class="contact_box" style="padding-bottom:18px;">



                    <div class="hi_second">We're sorry, the page you're looking for cannot be found.</div>

                    <div class="hi_second"> It's possible that you typed the address incorrectly, or that the page no longer exists.</div>


                    <div class="backhome"> <a href="index.php">Back to Home Page</a></div>



                </div>
                <!--end contact_box-->

            </div>


        </div>
        <div style="border:solid 0px;  margin-top:14px;"></div>
<?php include('includes/rightpanel.php'); ?>
        <div style="border:solid 0px; float:right; margin-bottom:28px; clear:both;"></div>
    </div>


<script type="text/javascript">
    $('#submenu2').show();

</script>
<?php include('includes/footer.php'); ?>  

<?php //}?>
