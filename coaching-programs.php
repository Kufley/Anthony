<?php if (file_exists($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php')) require($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php'); ?>
<?php
require_once('include/mainConnect.php');
require_once($config['absolute_path'].'classes/main.php');	
include('includes/header.php') ;
// require_once('include_scrollbar.php');
  ?>

<!--CONTENT AREA START-->
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
<div class="content_area">
<div class="med_area">
  <div class="med_arealeft coaching-full-div">
    <div class="meetanthony_area text-center">
      <div class="registered_area">
        <div class="inner_hed"> Coaching Programs </div>
      </div>

      </div>
      <div class="meetanthony_right">
        <div class="executiveweight_text text-center">
          <p><b>The program is designed for the client who seeks the professional guidance they really need and desire!</b></p>
          <p><b>You want a personalized weight management blueprint that is tailored to your needs and goals, which produces hard core results and eliminates guesswork!</b> </p>
          <p><b>Whether you have 10# or 210# to lose, I will personally see to it that you get the guidance, motivation and accountability that will enable you to reach your desired body weight and accomplish all of your health and wellness goals!</b> </p>
        </div>
      </div>
    </div>
    
    <!-- Get Google CDN's jQuery and jQuery UI with fallback to local --> 
    
    <!--<div class="stages_area">
                    	<div class="stages_main">
                        	<div class="stages_rowarea1 starter_programs">
                            	<div class="stages_col1">
                                	<div class="stages_col1_align">Individual Nutrition Sessions</div>
									</div>
                            
                              
                                <div class="stages_colleft">
                               <div class="stages_colleft_align" style="float: none;">
                                   <p style="text-align: center; text-decoration: underline; margin: 0px 0px 15px 0px; font-size: 32px;">
                                    SPECIAL!
                                   </p>
                                   <p style="margin: 15px 0px; padding: 0px;">
                                       1st (3) sessions &frac12; price!
                                   </p>
                                   <p style="margin: 15px 0px; padding: 0px 0px 10px 0px;">
                                    30, 60 minute sessions available
                                   </p>
							   </div>
                                </div>
                            </div>
                        </div>
                    </div>
                   Stage Area 1 end
      
      <div class="stages_area">
        <div class="stages_main">
          <div class="stages_rowarea1 starter_programs">
            <div class="stages_col1">
              <div class="stages_col1_align">Personal Training Sessions</div>
            </div>
            <div class="stages_colleft">
              <div class="stages_colleft_align" style="float: none;">
                <p style="text-align: center; margin: 0px 0px 15px 0px; font-size: 32px;"> FULL </p>
                <p style="margin: 15px 0px; padding: 0px;">&nbsp; </p>
                <p style="margin: 15px 0px; padding: 0px 0px 10px 0px;">&nbsp; </p>
              </div>
            </div>
          </div>
        </div>
      </div>--> 
    
    <!--Stage Area Start--> 
    
    <!--Stage Area end--> 
  </div>
   <div class="prize-table">
     <div>
       <div class="programs_below">Please choose one of the programs below that best fits you, and let&rsquo;s get
         started!</div>
         <div class="programs_below font-26 underline">CREATE YOUR OWN PROGRAM!!</div>
         <div class="programs_below font-21">Use <span class="underline">YOUR</span> hours on the topics <span class="underline">YOU</span> want to use them on!</div>

     </div>
    <div class="stages_area new_page">
      <div class="stages_main">
        <div class="stages_rowarea1">
          <div class="stages_col1">
            <div class="stages_col1_align">Personalized Weight Loss Programs</div>
          </div>
          <div class="stages_col2">
            <div class="stages_col2_align"><img src="images/star1.png" alt="star1" /></div>
          </div>
          <div class="stages_col2">
            <div class="stages_col2_align"><img src="images/star2.png" alt="star2" /></div>
          </div>
          <div class="stages_col4">
            <div class="stages_col2_align"><img src="images/star3.png" alt="star3" /></div>
          </div>
        </div>
        <div class="stages_rowarea1">
          <div class="bronze_col1"></div>
          <div class="bronze_col2">
            <div class="bronze_col1_align">Bronze Program - 10 Hours</div>
          </div>
          <div class="bronze_col2">
            <div class="bronze_col1_align">Silver Program - 20 Hours</div>
          </div>
          <div class="bronze_col4">
            <div class="bronze_col1_align">Gold Program - 30 Hours</div>
          </div>
        </div>
        <!--
                            <div class="stages_rowarea1">
                            	<div class="total_hours_col1">
                                	<div class="total_hours_col1_align">Stages</div>
                                </div>
                                <div class="total_hours_col2">
                                	<div class="total_hours_col2_align"></div>
                                </div>
								<div class="total_hours_col2">
                                	<div class="total_hours_col2_align">8-10 Hours</div>
                                </div>
                                <div class="total_hours_col2">
                                	<div class="total_hours_col2_align">10-12 Hours</div>
                                </div>
                                <div class="total_hours_col4">
                                	<div class="total_hours_col2_align">16-18 Hours</div>
                                </div>
                            </div>
                            -->
        <div class="stages_rowarea1">
          <div class="big_picture_col1">
            <div class="big_picture_col1_align"> <a href="#" name="bp" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect1');">Big Picture (click here)</a>
              <p> Medical History, Blood Work, Needs Assessment, 
                Roadblock Analysis, Goal Orientation </p>
            </div>
          </div>
          <div class="big_picture_col2">
            <div class="big_picture_col2_align"><img src="images/right.png" alt="right" /></div>
          </div>
          <div class="big_picture_col2">
            <div class="big_picture_col2_align"><img src="images/right.png" alt="right" /></div>
          </div>
          <div class="big_picture_col4">
            <div class="big_picture_col2_align"><img src="images/right.png" alt="right" /></div>
          </div>
        </div>
        <div class="stages_rowarea1">
          <div class="awareness_col1">
            <div class="big_picture_col1_align"> <a href="#" name="aw" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect2');">Awareness (click here)</a>
              <p> Food Assessment, Food Beliefs, Food Recognition </p>
            </div>
          </div>
          <div class="awareness_col2">
            <div class="big_picture_col2_align"><img src="images/right.png" alt="right" /></div>
          </div>
          <div class="awareness_col2">
            <div class="big_picture_col2_align"><img src="images/right.png" alt="right" /></div>
          </div>
          <div class="awareness_col4">
            <div class="big_picture_col2_align"><img src="images/right.png" alt="right" /></div>
          </div>
        </div>
        <div class="stages_rowarea1">
          <div class="big_picture_col1">
            <div class="big_picture_col1_align"> <a href="#" name="bm" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect3');">Behavior Modification (click here)</a>
              <p> Behavior Identification, Habits, Motivation, Power Thinking </p>
            </div>
          </div>
          <div class="big_picture_col2">
            <div class="big_picture_col2_align"><img src="images/right.png" alt="right" /></div>
          </div>
          <div class="big_picture_col2">
            <div class="big_picture_col2_align"><img src="images/right.png" alt="right" /></div>
          </div>
          <div class="big_picture_col4">
            <div class="big_picture_col2_align"><img src="images/right.png" alt="right" /></div>
          </div>
        </div>
        <div class="stages_rowarea1">
          <div class="awareness_col1">
            <div class="big_picture_col1_align"> <a href="#" name="st" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect4');">Stress (click here)</a>
              <p> Stressors, Actions, Goals </p>
            </div>
          </div>
          <div class="awareness_col2">
            <div class="big_picture_col2_align"><img src="images/right.png" alt="right" /></div>
          </div>
          <div class="awareness_col2">
            <div class="big_picture_col2_align"><img src="images/right.png" alt="right" /></div>
          </div>
          <div class="awareness_col4">
            <div class="big_picture_col2_align"><img src="images/right.png" alt="right" /></div>
          </div>
        </div>
        <div class="stages_rowarea1">
          <div class="big_picture_col1">
            <div class="big_picture_col1_align"> <a href="#" name="ep" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect5');">Exercise Nutrition Plan (click here)</a>
              <p> Macro-Nutrient Modeling, Nutrient Timing </p>
            </div>
          </div>
          <div class="big_picture_col2">
            <div class="big_picture_col2_align"><img src="images/right.png" alt="right" /></div>
          </div>
          <div class="big_picture_col2">
            <div class="big_picture_col2_align"><img src="images/right.png" alt="right" /></div>
          </div>
          <div class="big_picture_col4">
            <div class="big_picture_col2_align"><img src="images/right.png" alt="right" /></div>
          </div>
        </div>
        <div class="stages_rowarea1">
          <div class="awareness_col1">
            <div class="big_picture_col1_align"> <a href="#" name="sp" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect6');">Success Plan (click here)</a>
              <p> Goals &amp; Timelines, Recipe For Success, Meal Plans </p>
            </div>
          </div>
          <div class="awareness_col2">
            <div class="big_picture_col2_align"><img src="images/right.png" alt="right" /></div>
          </div>
          <div class="awareness_col2">
            <div class="big_picture_col2_align"><img src="images/right.png" alt="right" /></div>
          </div>
          <div class="awareness_col4">
            <div class="big_picture_col2_align"><img src="images/right.png" alt="right" /></div>
          </div>
        </div>
        <div class="stages_rowarea1">
          <div class="big_picture_col1">
            <div class="big_picture_col1_align"> <a href="#" name="fa" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect7');">Follow-Up &amp; Accountability (click here)</a>
              <p> Obstacles, Motivation, Coach </p>
            </div>
          </div>
          <div class="big_picture_col2">
            <div class="big_picture_col2_align"></div>
          </div>
          <div class="big_picture_col2">
            <div class="big_picture_col2_align"><img src="images/right.png" alt="right" /></div>
          </div>
          <div class="big_picture_col4">
            <div class="big_picture_col2_align"><img src="images/right.png" alt="right" /></div>
          </div>
        </div>
        <div class="stages_rowarea1">
          <div class="awareness_col1">
            <div class="big_picture_col1_align" id="popup"> <a href="#" name="sus" onClick="openPopup('fadefriend',1,'fade_popup','datafriend',2,'data_on_fade','contect8');">Additional Hours (click Here)</a>
              <p> Maintenance, Guidance, Strategies </p>
            </div>
          </div>
          <div class="awareness_col2">
            <div class="big_picture_col2_align">&nbsp;</div>
          </div>
          <div class="awareness_col2">
            <div class="big_picture_col2_align"><img src="images/right.png" alt="right" /></div>
          </div>
          <div class="awareness_col4">
            <div class="big_picture_col2_align"><img src="images/right.png" alt="right" /></div>
          </div>
        </div>
        <div class="stages_rowarea1">
          <div class="big_picture_col1">
            <div class="big_picture_col1_align"  id="popup2"> Bonus
              <p> 24/7 email access thru entire program! </p>
            </div>
          </div>
          <div class="big_picture_col2">
            <div class="big_picture_col2_align"><img src="images/right.png" alt="right" /></div>
          </div>
          <div class="big_picture_col2">
            <div class="big_picture_col2_align"><img src="images/right.png" alt="right" /></div>
          </div>
          <div class="big_picture_col4">
            <div class="big_picture_col2_align"><img src="images/right.png" alt="right" /></div>
          </div>
        </div>
        
        <!--<div class="stages_rowarea1">
                            	<div class="bonus_col1">
                                	<div class="bonus_col1_align">
                                    Bonus
                                        <p>
                                           24/7 email access thru entire program!
                                        </p>
                                    </div>
                                </div>
                                <div class="bonus_col2">
                                	<div class="bonus_col2_align"><img src="images/right.png" alt="right" /></div>
                                </div>
                                <div class="bonus_col2">
                                	<div class="bonus_col2_align"><img src="images/right.png" alt="right" /></div>
                                </div>
                                <div class="success_col444">
                                	<div class="bonus_col2_align"><img src="images/right.png" alt="right" /></div>
                                </div>
                            </div>-->
        
        <div class="stages_rowarea1">
          <div class="bronzeprogram_col1"> </div>
          <div class="bronzeprogram_col2">
            <div class="bronzeprogram_col2_align"> <a class="bronze" href="<?php echo $config['site_url'];?>bronze-landing.php"><br />
              HELP ME LOSE WEIGHT NOW!</a> </div>
          </div>
          <div class="bronzeprogram_col2">
            <div class="bronzeprogram_col2_align"> <a class="silver" href="<?php echo $config['site_url'];?>silver-landing.php"><br />
              HELP ME LOSE WEIGHT NOW!</a> </div>
          </div>
          <div class="bronzeprogram_col4">
            <div class="bronzeprogram_col2_align"> <a class="gold" href="<?php echo $config['site_url'];?>gold-landing.php"><br />
              HELP ME LOSE WEIGHT NOW!</a> </div>
          </div>
        </div>
      </div>
    </div>
  </div>
   <div class="contact_box" style="margin-left: 20px;">
    <div class="contact_box_first_line" style="  margin:5px 0px 0px 5px;" > QUESTIONS? </div>
    <!--end contact_phone_box-->
    <div class="contact_phone_box" style="  margin:0px 0px 0px 5px;">
      <div class="contact_phone_text">Contact Us. We would love to speak with you!</div>
      <div class="mandatory_line" style=" margin:17px 5px 8px 0px; width:605px;"><span class="staric">*</span>Mandatory fields</div>
    </div>
    <!--end contact_phone_box-->
    <form method="post" action="contactus.php" id="frmcontactus" name="frmcontactus" >

      <?php	if(count($valid_array))	{?>
      <div class="clear"></div>
      <div class="erorr error_fc" >
        <?php

                                echo "".show_error($valid_array)."";	?>
      </div>
      <?php } ?>
      <div class="contact_form_box" style=" margin-left:20px;">
        <div class="contact_name_line">
          <div class="contact_name_text"><span class="staric_first">*</span>Name</div>
          <div class="contact_name_field">
            <input type="text" value="<?php echo $name; ?>" maxlength="100" id="name" name="name" class="contact_name_field_text"  />
            <div class="clear"></div>
            <span class="validation_error" id="nameInfo"></span> </div>
        </div>
        <!--end contact_name_line-->
        <div class="contact_name_line">
          <div class="contact_name_text"><span class="staric_first">*</span>Email</div>
          <div class="contact_name_field">
            <input type="text" value="<?php echo $email; ?>" maxlength="70" id="email" name="email" class="contact_name_field_text" />
            <div class="clear"></div>
            <span class="validation_error" id="emailInfo"></span> </div>
        </div>
        <!--end contact_name_line-->
        <div class="contact_name_line">
          <div class="contact_name_text"><span class="staric_first">*</span>Phone</div>
          <div class="contact_name_field" style="margin-left:1px;">
            <input type="text" value="<?php echo $phone1;?>"  maxlength="3" id="phone1" name="phone1" class="contactform1" onkeyup="validation4number(this,'notnumbers')" style="width:60px;" />
            <span class="dotsym"  margin:5px 2px 0 0;">-</span>
            <input type="text" value="<?php echo $phone2;?>"  maxlength="3" id="phone2" name="phone2" class="contactform1" onkeyup="validation4number(this,'notnumbers')"  />
            <span class="dotsym"  margin:5px 2px 0 0;">-</span>
            <input type="text" value="<?php echo $phone3;?>"  maxlength="4" id="phone3" name="phone3" class="contactform1" onkeyup="validation4number(this,'notnumbers')"  />
            <div class="clear"></div>
            <span class="validation_error" id="phoneInfo"></span> </div>
        </div>
        <div class="contact_name_line">
          <div class="contact_ph_text">Company</div>
          <div class="contact_name_field">
            <input name="company" value="<?php echo $company; ?>"  id="company" type="text" class="contact_name_field_text"  maxlength="100" />
            <div class="clear"></div>
            <span class="validation_error" id="companyInfo"></span> </div>
        </div>
        <div class="contact_name_line">
          <div class="contact_name_text"><span class="staric_first">*</span>Comments</div>
          <div class="contact_name_field">
            <textarea id="comments" name="comments" cols="49" rows="4" class="textarea"><?php echo $comments; ?></textarea>
            <div class="clear"></div>
            <span class="validation_error" id="commentInfo"></span> </div>
        </div>
        
        <!--end contact_name_line-->
        <div class="clent_tab2" style="margin:15px 0px 40px 160px;
    padding: 0;">
          <div class="searchcab2">
            <input name="submit" value="submit"  id="submit" type="hidden" />
            <input id="submit_local" class="searchbutton" type="submit" style="cursor:pointer;" value="" name="submit_local"/>
          </div>
          <br>
          <b> If you receive a 'Thank You' page after submitting your form, it was successfully sent! 
          <!--If not successful, please email directly at <a href="mailto:Anthony@WeightLossHappens.com">Anthony@WeightLossHappens.com</a>--></b> </div>
      </div>
      <!--end contact_form_box-->
    </form>
  </div>
  <div class="question"><a href="http://www.weightlosshappens.com/">Back to Homepage</a></div>
</div>
<!--<div class="question"> Questions? <span><a href="contactus.php">Contact Anthony</a></span><!-- or email <span><a href="mailto:Anthony@WeightLossHappens.com">Anthony@WeightLossHappens.com</a></span> --><!--</div>-->
<script type="text/javascript" src="js/validation1_js.js"></script>
<script language="javascript" type="text/javascript">
  /* this is just a simple reload; you can safely remove it; remember to remove it from the image too */
  function reloadCaptcha()
  {//alert('hii');
    document.getElementById('captcha').src = document.getElementById('captcha').src+ '?' +new Date();
  }


  var r2={ 'notnumbers':/[^\d]/g}
  function validation4number(o,w)
  {
    o.value = o.value.replace(r2[w],'');
  }
  function validation4pnumber(o,w)
  {
    if(o.value!='')
    {
      o.value = o.value.replace(r2[w],'');
      if(o.value <=0 || o.value=='-')
      {
        //	alert('Please enter valid quantity.');
        o.value=1;
      }
    }
    if(o.value=='')
    {
      o.value=1;
    }
  }

  // Value greater that 0 (not .decimal allowed)
  var r3={ 'notnumbers':/[^\d]/g}
  function validation4numeric(o,w)
  {
    o.value = o.value.replace(r2[w],'');
  }
</script>
<script  type="text/javascript">
//alert('hi'); 
$('#executive_weight_loss').addClass("current");

</script> 
<!--CONTENT AREA END-->
<?php include('includes/footer.php') ;?>
