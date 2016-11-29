<?php if (file_exists($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php')) require($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php'); ?>	<?php include('includes/header.php') ;?>
   

        <!--CONTENT AREA START-->
        <div class="content_area">
            <div class="med_area">
            	<div class="med_arealeft">
                	<div class="meetanthony_area">
                        <div class="registered_area">
                            <div class="inner_hed">
                                Contact Anthony
                            </div>
                        </div>
                    <div class="contact_box">
                      <div class="contact_box_first_line">Anthony Wilson 
                      	<span>RD, MS</span>
                      </div>
                      <div class="contact_box_second_line">West Islip, NY - 11795</div>
                      <div class="contact_phone_box">
            <div class="contact_phone_text">Phone: 631.336.6153</div>
          </div>
          <!--end contact_phone_box-->
          <div class="contact_phone_box">
            <div class="contact_phone_text">Email: <a href="mailto:Anthony@WeightLossHappens.com ">Anthony@WeightLossHappens.com </a></div>
          </div>
          <!--end contact_phone_box-->
          <form method="post" action="" id="frmcontactus" name="frmcontactus" onSubmit="return validate_form(this);">
          
            <div class="mandatory_line"><span class="staric">*</span>Mandatory fields</div>
            <div class="contact_form_box">
              <div class="contact_name_line">
                <div class="contact_name_text"><span class="staric_first">*</span>Name</div>
                <div class="contact_name_field">
                  <input type="text" value="" maxlength="100" id="name" name="name" class="contact_name_field_text" />
                 
                  </div>
              </div>
              <!--end contact_name_line-->
              <div class="contact_name_line">
                <div class="contact_name_text"><span class="staric_first">*</span>Email</div>
                <div class="contact_name_field">
                  <input type="text" value="" maxlength="70" id="email_id" name="email_id" class="contact_name_field_text"/>
                 
                   </div>
              </div>
              <!--end contact_name_line-->
              <div class="contact_name_line">
                <div class="contact_ph_text">Phone</div>
				<div class="contact_name_field">
				<input type="text" value=""  maxlength="13" id="phone" name="phone" class="contactform1" />
                <span style="float:left; margin:5px 2px 0 0;">-</span>
                <input type="text" value=""  maxlength="13" id="phone1" name="phone1" class="contactform1" />
                <span style="float:left; margin:5px 2px 0 0;">-</span>
                <input type="text" value=""  maxlength="13" id="phone2" name="phone2" class="contactform1" />
				</div>
              </div>
              
              <div class="contact_name_line">
                <div class="contact_ph_text">Company</div>
                <div class="contact_name_field">
                  <input type="text" value="" maxlength="70" id="email_id1" name="email_id1" class="contact_name_field_text"/>
                   </div>
              </div>
              
              
              <div class="contact_name_line">
                <div class="contact_name_text"><span class="staric_first">*</span>Comments/Query</div>
                <div class="contact_name_field">
                  <textarea id="comments" name="comments" rows=""  cols=""class="textarea"></textarea>
               
                </div>
              </div>
              <!--end contact_name_line-->
              <div class="clent_tab2">
                <div class="searchcab2">
                 <input id="submit_local" class="searchcab2" type="submit" style="cursor:pointer;" value="" name="submit_local"/>
                </div>
              </div>
            </div>
            <!--end contact_form_box-->
          </form>
        </div>
                 </div>
                </div>
                <div class="rightpanelarea"></div>
                <?php include('includes/rightpanel.php') ;?>
                <div class="question">
                	Questions? Call 631.336.6153 <!-- or email <span><a href="mailto:Anthony@WeightLossHappens.com">Anthony@WeightLossHappens.com</a></span> -->
                </div>
            </div>
        </div>
        <!--CONTENT AREA END-->          <script type="text/javascript">
//alert('hi'); 
$('#contactus').addClass("current");

</script>
      <?php include('includes/footer.php') ;?>  
      
      
      
      
            