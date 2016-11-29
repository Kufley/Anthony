<?php if (file_exists($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php')) require($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php'); ?><?php
error_reporting(E_ALL);
require_once('include/mainConnect.php');
require_once($config['absolute_path'].'classes/main.php');
include('includes/header.php') ;
?>
<!--CONTENT AREA START-->

<div class="content_area">
  <div class="registered_area2">
    <div class="registered_text"> How much weight will you lose with the help of a<br />
      Registered Dietitian and Behavior Therapist? </div>
  </div>
  <div class="med_area">
    <div class="med_arealeft">
      <div class="meetanthony_area">
        <div class="meetanthony_left">
          <div class="meetanthony_top"> <a href="about-anthony.php"><img src="images/meetanthony.png" alt="meetanthony" width="208" height="251" /></a> </div>
          <div class="meetanthony_bottom"> <a href="about-anthony.php">Anthony Wilson</a>, <span>RD, MS</span>  <div class="dietitian">Dietitian and Behavior Therapist </div></div>
        </div>
        <div class="meetanthony_right">
          <div class="meetanthony_right_redtext2">
            <p>Anthony Wilson, Registered Dietitian and Behavior Therapist helps you approach weight management from a 3-pronged perspective:</p>
            <ul class="meetanthony_list">
              <li>Nutrition</li>
              <li>Exercise</li>
              <li>Behavior Change</li>
            </ul>
          </div>
          <div class="consultation_button"> <a href="http://www.weightlosshappens.com/coaching-programs.php">Coaching Programs<span><img src="images/caret.png"></span></a></div>
        </div>
      </div>
	  
	  <div class="meetanthony_area">
		<div class="meetanthony_video">
			<div class="inner_hed_video">Meet Anthony</div>
			<div class="play_video">
				<video width="400" controls="controls" autoplay="autoplay">
				  <source src="meetAnthony.mp4" type="video/mp4">
				  <source src="meetAnthony.ogv" type="video/ogg">
				</video>
			</div>
        </div>
      </div>
    </div>
    <?php include('includes/rightpanel.php') ;?>
      <div class="weightloss_area">
          <div class="weightloss_top">
              <div class="weightloss_tophed">Weight Loss Articles</div>
              <div class="weightloss_topmore"> <a href="weight-loss-articles.php">More articles</a> </div>
          </div>
          <div class="weightloss_bottom" style="height:225px;">
              <div class="articles_main">
                  <div class="articles_tophed"> <a href="#" name="wla1" onclick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect9');" >4 steps to permanent<br>weight loss</a> </div>

                  <div class="articles_bottom"> <a href="#" onclick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect9');"><img src="images/permanent_weight_second.jpg" alt="permanent_weight_second" title="4 steps to permanent weight loss" class="articles_border" width="185" /></a> </div>
              </div>
              <div class="line"></div>
              <div class="articles_main">
                  <div class="articles_tophed"> <a href="#" name="wla2" onclick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect10');">LACK OF PROFESSIONAL GUIDANCE: 10 CONSEQUENCES</a> </div>
                  <div class="articles_bottom"> <a href="#" onclick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect10');"><img src="images/doctor.png" alt="fat_grams_second" title="Fat grams vs. Calories: who wins?" class="articles_border" width="185" /></a> </div>
              </div>
              <div class="line"></div>
              <div class="articles_main">
                  <div class="articles_tophed"> <a href="#" name="wla3" onclick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect11');">3 practices to drastically reduce<br>your calories</a> </div>
                  <div class="articles_bottom"> <a href="#" onclick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect11');"><img src="images/drastically_first.jpg" alt="drastically_first" title="3 practices to drastically reduce your calories" class="articles_border" width="185" /></a> </div>
              </div>
          </div>
      </div>
      <div class="question"> Questions? <span><a href="contactus.php">Contact Anthony</a></span></div>
  </div>
</div>
<!--googleoff: all-->
<div class="pop-up">
	<style scoped>
    @import "css/bootstrap.css";
	@import "css/style.css";
    </style>
  <div id="introdu" class="modal fade bs-example-modal-lg" tabindex="-1" role="dialog" aria-labelledby="myLargeModalLabel" aria-hidden="true">
    
    <div class="modal-dialog modal-lg">
      <div class="modal-content">
        <div class="modal-header">
          <button type="button" class="close" data-dismiss="modal"><span aria-hidden="true">&nbsp;</span><span class="sr-only">Close</span></button>
          <h2>SIGN UP TODAY FOR YOUR FREE 2 HOUR CONSULTATION!</h2>
        </div>
        <div class="modal-body">
          <div class="Pop-content">
            <div class="col-md-8">
            	<h3>TITLE WILL COME HERE !!!</h3>
                <p class="center"><u>Free consultation!!<br>Plus 24/7 email support!!</U><br></p><p><br /></p>
                <p>12:01 am Friday, January 9th 
					<span>-till-</span>
				11:59 pm Sunday, January 11th</p>
                
                <p>** LIMITED TO A MAXIMUM OF 10 PEOPLE !!! **</p>
                
            </div>
            <div class="col-md-4">
            	<img src="images/pop-img.jpg" alt="Pop-image">
            </div>
            
          </div>
        </div>
        <div class="modal-footer">
        <span>Click for more details and to contact us</span>
        <a type="button" class="btn btn-primary" href="<?php echo $config['site_url'];?>/free-consultation.php">Click Here</a>
      </div>
      </div>
    </div>
  </div>
</div>
<!--googleon: all-->
<script>
$(window).load(function() {
$('#introdu').delay(10000).modal('show');
$(".close").click(function(){
$("#intro").hide();	
});
$("#introdu").click(function(){
$("#intro").hide();	
});
});
</script>
<!--CONTENT AREA END-->
<script type="text/javascript" >
//alert('hi'); 
$('#home').addClass("current");

</script>
<?php include('includes/footer.php') ;?>
