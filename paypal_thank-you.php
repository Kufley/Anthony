<?php if (file_exists($_SERVER['DOCUMENT_ROOT'] . '/zblock/zbblock.php')) require($_SERVER['DOCUMENT_ROOT'] . '/zblock/zbblock.php'); ?><?php
require_once('include/mainConnect.php');
require_once($config['absolute_path'] . 'classes/main.php');
?>
<?php include('includes/header.php'); ?>  


<!--CONTENT AREA START-->
<div class="content_area">
    <div class="med_area">
        <div class="med_arealeft width-100">
            <div class="meetanthony_area">
                <div class="registered_area">
                    <div class="inner_hed">
                        Thank You
                    </div>
                </div>
                <!--start contact_box-->
                <div class="contact_box">



                    <div class="hi">Hi <?php echo stripslashes(stripslashes(ucwords($_SESSION['name']))); ?>,</div>
                    <div class="hi" style="margin-top:10px;">Thank you! You have successfully placed your order for Dream Weight Gold Coaching Program.
                    </div>

                    <!--<div class="hi">I will get back to you shortly.</div>-->



                    <div class="contact_box_first_line" style="margin-top:22px;">Anthony Wilson, RD, MS</div>
                    <div class="contact_box_second_line" style="margin-bottom:2px;">West Islip, NY - 11795</div> 

                    <!-- <div class="contact_phone_box">
                            <div class="contact_phone_text"><strong>Phone:</strong> 631.336.6153 </div>
                        </div>-->


                    <div class="contact_phone_box" style=" margin-bottom:18px;">
                        <!--<div class="contact_phone_text"><strong>Email:</strong> <a href="mailto:Anthony@WeightLossHappens.com">Anthony@WeightLossHappens.com</a></div>-->
                    </div>





                </div>
                <!--end contact_box-->

            </div>


        </div>
       </div>
    <div class="question"><a href="http://www.weightlosshappens.com/">Back to Homepage</a></div>
    </div>



    <?php include('includes/footer.php'); ?>  
    <script language="javascript">
        $('#submenu2').show();
        /*function showSubMenu(){
         i=2;
         for(var i=1;i<10;i++){
         if(minuId==i){
         
         $('#submenu'+i).show();
         return false;
         }
         else{
         alert(i);
         $('#submenu'+i).hide();
         
         }
         }
         }*/
    </script>
    <script type="text/javascript">
//alert('hi'); 
        $('#executive_weight_loss').addClass("current");

    </script>
    <?php //}?>
