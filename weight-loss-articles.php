<?php if (file_exists($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php')) require($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php'); ?>
<?php
require_once('include/mainConnect.php');
require_once($config['absolute_path'].'classes/main.php');	
include('includes/header.php') ;?>
<style>
.permanent_weight_main {
	width: 200px;
	border: 0px solid #d6b9f2;
	/*background: #f6f1fe; */
	float: left;
	margin: 0 10px 10px 0;
}
</style>
<div id="boxes">
  <div id="dialog" class="window">
    <div class="header-popup">Life-Saving Christmas Gift!!!</div>
    <div id="popupfoot"><a href="#" class="fa fa-close close"><img src="images/closep.png"></a></div>
    <div class="body-popup">
      <img src="images/tree.png" alt="tree" class="left">
      <div class="text-body">
        <p class="gift">Gift Certificate for a Dream Weight Coaching Program!</p>
        <p class="help">Help someone change their body and their life now!!</p>
        <p class="buy"><a href="http://www.weightlosshappens.com/coaching-programs.php">BUY GIFT CERTIFICATE
            NOW!</a></p>
        <img class="right" src="images/caption.png" alt="merry cristmas">
      </div>
    </div>
  </div>
  <div id="mask"></div>
</div>
<!--CONTENT AREA START-->
<div class="content_area">
<div class="med_area">
  <div class="med_arealeft width-100">
    <div class="meetanthony_area">
      <div class="registered_area">
        <div class="inner_hed"> Weight Loss Articles </div>
      </div>
      <div class="left_panel">
        <div class="articles_text">
          <p>Anthony Wilson is a Registered Dietitian (RD) and Behavior Therapist. Over the past 15 years Anthony has successfully facilitated many diabetic &amp; non-diabetic individuals with overcoming their obstacles and attaining their desired body weight.</p>
          <p style="margin-top:10px;">These articles will help you gain expert nutrition advice and valuable insights into how behavioral principles and techniques help achieve desired body weight and better health.</p>
        </div>
        <div class="weight_articles_area">
          <div class="weight_articles_main">
            <div class="permanent_weight_main">
              <div class="permanent_weight_top"> <a href="#" name="wla1" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect9');"> <img src="images/permanent_weight_loss2.png" alt="permanent_weight_loss" width="190"/></a> </div>
              <div class="permanent_weight_bottom"> <a href="#" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect9');"> 4 Steps to permanent weight loss</a> </div>
            </div>
            <div class="permanent_weight_main">
              <div class="permanent_weight_top"> <a href="#" name="wla2" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect21');"> <img src="images/fat_grams2.jpg" alt="fat_grams" width="190"/></a> </div>
              <div class="permanent_weight_bottom"> <a href="#" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect21');"> Fat grams vs. Calories: who wins?</a> </div>
            </div>
            <div class="permanent_weight_main">
              <div class="permanent_weight_top"> <a href="#" name="wla3" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect11');"> <img src="images/practices2.jpg" alt="practices" width="190"/></a> </div>
              <div class="permanent_weight_bottom"> <a href="#" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect11');"> 3 Practices to drastically reduce your calories</a> </div>
            </div>
            <div class="permanent_weight_main">
              <div class="permanent_weight_top"> <a href="#" name="wla4" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect12');"> <img src="images/prevent_overeating2.png" alt="prevent_overeating" width="190"/></a> </div>
              <div class="permanent_weight_bottom"> <a href="#" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect12');"> 3 Keys to prevent overeating</a> </div>
            </div>
            <div class="permanent_weight_main">
              <div class="permanent_weight_top"> <a href="#" name="wla5" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect13');"> <img src="images/avoid2.jpg" alt="avoid" width="190"/></a> </div>
              <div class="permanent_weight_bottom"> <a href="#" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect13');"> How to avoid binging after work</a> </div>
            </div>
            <div class="permanent_weight_main">
              <div class="permanent_weight_top"> <a href="#" name="wla6" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect14');"> <img src="images/turning2.jpg" alt="turning" width="190"/></a> </div>
              <div class="permanent_weight_bottom"> <a href="#" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect14');"> How to prevent your snack from turning into a meal</a> </div>
            </div>
            <div class="permanent_weight_main">
              <div class="permanent_weight_top"> <a href="#" name="wla7" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect15');"> <img src="images/gaining_weight2.jpg" alt="gaining_weight" width="190"/></a> </div>
              <div class="permanent_weight_bottom"> <a href="#" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect15');"> 3 Ways to stop gaining weight at work</a> </div>
            </div>
            <div class="permanent_weight_main">
              <div class="permanent_weight_top"> <a href="#" name="wla8" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect16');"> <img src="images/overcoming2.png" alt="overcoming" width="190"/></a> </div>
              <div class="permanent_weight_bottom"> <a href="#" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect16');"> 5 Steps to overcoming an obstacle</a> </div>
            </div>
            <div class="permanent_weight_main">
              <div class="permanent_weight_top"> <a href="#" name="wla9" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect17');"> <img src="images/motivation2.png" alt="motivation1" width="190"/></a> </div>
              <div class="permanent_weight_bottom"> <a href="#" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect17');"> Motivation: 5 keys to setting "smart" goals!</a> </div>
            </div>
            <div class="permanent_weight_main">
              <div class="permanent_weight_top"> <a href="#" name="wla10" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect18');"> <img src="images/Increase2.png" alt="Increase" width="190"/></a> </div>
              <div class="permanent_weight_bottom"> <a href="#" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect18');"> Increase your awareness &amp; lose weight fast!</a> </div>
            </div>
            <div class="permanent_weight_main">
              <div class="permanent_weight_top"> <a href="#" name="wla3" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect19');"> <img src="images/older_man_abs.jpg" alt="practices" width="190"/></a> </div>
              <div class="permanent_weight_bottom"> <a href="#" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect19');"> Getting started with training</a> </div>
            </div>
            <div class="permanent_weight_main">
              <div class="permanent_weight_top"> <a href="#" name="wla4" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect20');"> <img src="images/2_ladies_on_mat_abs.jpg" alt="prevent_overeating" width="190"/></a> </div>
              <div class="permanent_weight_bottom"> <a href="#" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect20');"> Working out at home</a> </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>

  <div class="question"><a href="http://www.weightlosshappens.com/">Back to Homepage</a></div>
  <!--<div class="question"> Questions? <span><a href="contactus.php">Contact Anthony</a></span> --><!-- or email <span><a href="mailto:Anthony@WeightLossHappens.com">Anthony@WeightLossHappens.com</a></span> -->
  <!-- </div>--> 
</div>
</div>
<!--CONTENT AREA END--><script type="text/javascript">
//alert('hi'); 
$('#weight_loss_articles').addClass("current");

</script>
<?php include('includes/footer.php') ;?>
