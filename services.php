<?php if (file_exists($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php')) require($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php'); ?>
<?php
require_once('include/mainConnect.php');
require_once($config['absolute_path'].'classes/main.php');	
include('includes/header.php') ;?>
<!--CONTENT AREA START-->

<div class="content_area">
<div class="med_area">
  <div class="med_arealeft width-100">
    <div class="meetanthony_area">
      <div class="registered_area">
        <div class="inner_hed"> Services </div>
      </div>
      <div class="service_box"> 
        <!--start service_box_group-->
        <div class="service_box_group"> 
          <!--start service_left_box-->
          <div class="service_left_box">
            <div class="service_left_box_first">Coaching Programs</div>
            <!--start service_left_box_second-->
            <div class="service_left_box_second"><img src="images/executive_coaching.jpg" align="left" alt="executive_coaching" title="Executive Coaching Programs" /> We offer a number of options with our weight management programs. Please click on the <a href="coaching-programs.php">weight loss coaching programs</a> link to view more detailed information on each one. <span>Please contact us with any questions or to set up a <a href="free-consultation.php">free consultation</a>.</span> </div>
            <!--end service_left_box_second--> 
          </div>
          <!--end service_left_box--> 
          <!--start service_left_box-->
          <div class="service_again_left_box">
            <div class="service_again_left_box_first">Boot Camp</div>
            <!--start service_left_box_second-->
            <div class="service_left_box_second_column" ><img src="images/executive_boot.jpg" align="left" alt="executive_boot" title="Executive Boot Camp" />Weight management boot camp for the busy executive! This 1-day experience will include creating your own &ldquo;recipe-for-success&rdquo; which incorporates food and 
              nutrition education, current blood work analysis, behavior modification, meal plans and recipes, a 
              supermarket tour and more. <span>Boot camp can be done one day during the week or one day on the weekend.</span> </div>
            <!--end service_left_box_second--> 
          </div>
          <!--end service_left_box--> 
        </div>
        <!--service_box_group--> 
        <!--start service_box_group-->
        <div class="service_box_group"> 
          <!--start service_left_box-->
          <div class="service_left_box" >
            <div class="service_left_box_first" >Personal Training Services <span class="short_text">(local clients)</span></div>
            <!--start service_left_box_second-->
            <div class="service_left_box_second"><img src="images/personal_training.jpg" align="left" alt="personal_training" title="Personal Training Services" />Personal training complements your dietary weight management plan by helping you to burn extra calories and raising your level of motivation. <span>Personal training services are available for local clients in which I will find you a personal trainer in your area that would best fit your needs and personality.</span> </div>
            <!--end service_left_box_second--> 
          </div>
          <!--end service_left_box--> 
          <!--start service_left_box-->
          <div class="service_again_left_box"  >
            <div class="service_again_left_box_first">Supermarket Tours</div>
            <!--start service_left_box_second-->
            <div class="service_left_box_second_column" ><img src="images/supermarket_tours.jpg" align="left" alt="supermarket_tours" title="Supermarket Tours" />With all the different choices of foods in the supermarkets, it is all too easy for people with the best of intentions to make less than ideal choices when shopping. Supermarket tours teach people how to shop wisely from a health and weight management perspective. </div>
            <!--end service_left_box_second--> 
          </div>
          <!--end service_left_box--> 
        </div>
        <!--service_box_group--> 
        <!--start service_box_group-->
        <div class="service_box_group"> 
          <!--start service_left_box-->
          <div class="service_left_box" >
            <div class="service_left_box_first">Bariatric Services</div>
            <!--start service_left_box_second-->
            <div class="service_left_box_second" ><img src="images/group_seminars.jpg" align="left" alt="group_seminars" title="Group Seminars And Corporate Workshops" />Considering bariatric surgery? Need to lose weight before your bariatric surgery? Already had bariatric surgery and need nutritional assistance to get back on track with your weight? Let's talk!</div>
            <!--end service_left_box_second--> 
          </div>
          <!--end service_left_box--> 
          <!--start service_left_box-->
          <div class="service_again_left_box"  >
            <div class="service_again_left_box_first">Gift Certificates</div>
            <!--start service_left_box_second-->
            <div class="service_left_box_second_column" ><img src="images/gift.jpg" align="left" alt="gift" title="Gift Certificates" />If you know someone who could use some assistance with improving their health and weight, gift certificates for any of the above 
              services can be a fantastic, life-saving gift! </div>
            <!--end service_left_box_second--> 
          </div>
          <!--end service_left_box--> 
        </div>
        <!--service_box_group--> 
      </div>
      <!--end service_box--> 
    </div>
  </div>

  <div class="question"><a href="http://www.weightlosshappens.com/">Back to Homepage</a></div>
  <!--<div class="question"> Questions? <span><a href="contactus.php">Contact Anthony</a></span>--> <!-- or email <span><a href="mailto:Anthony@WeightLossHappens.com">Anthony@WeightLossHappens.com</a></span> --><!--</div>--> 
</div>
</div>
<!--CONTENT AREA END--> 
<script type="text/javascript">
//alert('hi'); 
$('#services').addClass("current");

</script>
<?php include('includes/footer.php') ;?>
