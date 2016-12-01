<?php if (file_exists($_SERVER['DOCUMENT_ROOT'] . '/zblock/zbblock.php')) require($_SERVER['DOCUMENT_ROOT'] . '/zblock/zbblock.php'); ?>
<?php
session_start();
require_once('include/mainConnect.php');
require_once($config['absolute_path'] . 'classes/main.php');
if (isset($_POST['submit']) && $_POST['submit'] != '' && $_POST['submit'] == 'submit') {
    //print_r($_SESSION); die;
    $name = $mainClass->outputData($_POST['name']);
    $email = $mainClass->outputData($_POST['email']);
    $phone1 = $mainClass->outputData($_POST['phone1']);
    $phone2 = $mainClass->outputData($_POST['phone2']);
    $phone3 = $mainClass->outputData($_POST['phone3']);
    $comments = $mainClass->outputData($_POST['comments']);
    $company = $mainClass->outputData($_POST['company']);


    // Server Side vaidation starts
    $elems[] = array('name' => 'name', 'label' => 'Name: Please enter your name.', 'type' => 'text', 'required' => true, 'cont' => 'nameVal', 'len_max' => '40');
    if ($email == '') {
        $elems[] = array('name' => 'email', 'label' => 'Email: Please enter your email address.', 'type' => 'text', 'required' => true, 'cont' => 'email');
    } else {
        $elems[] = array('name' => 'email', 'label' => 'Email: Please enter your valid email address.', 'type' => 'text', 'required' => true, 'cont' => 'email');
    }
    if ($phone1 != '' || $phone2 != '' || $phone3 != '') {
        if ($phone1 == '') {
            $elems[] = array('name' => 'phone1', 'label' => 'phone: Please enter your valid phone number.', 'type' => 'text', 'required' => true, 'len_max' => '3');
        }
        if ($phone2 == '') {
            $elems[] = array('name' => 'phone2', 'label' => 'phone: Please enter your valid phone number.', 'type' => 'text', 'required' => true, 'len_max' => '3');
        }
        if ($phone3 == '') {
            $elems[] = array('name' => 'phone3', 'label' => 'phone: Please enter your valid phone number.', 'type' => 'text', 'required' => true, 'len_max' => '3');
        }
    }

    $elems[] = array('name' => 'company', 'label' => 'Company: Please enter your company name.', 'type' => 'text', 'len_max' => '255');

    $elems[] = array('name' => 'comments', 'label' => 'Comment: Please enter your comment.', 'type' => 'text', 'required' => true);



    $f = new FormValidator($elems);
    $err = $f->validate($_POST);

    if ($err === true) {
        $ret = $f->getValidElems();
        if (is_array($ret))
            $valid_array = $ret;
        //print_r($valid_array);
    }
    else {

        $error = $mainClass->addContact();
//var_dump($mainClass);
//var_dump($error); die();
    }
}
?>
<?php include('includes/header.php'); ?>
<script type="text/javascript" src="js/validation1_js.js"></script>
<script language="javascript" type="text/javascript">
    /* this is just a simple reload; you can safely remove it; remember to remove it from the image too */
    function reloadCaptcha()
    {//alert('hii');
        document.getElementById('captcha').src = document.getElementById('captcha').src + '?' + new Date();
    }


    var r2 = {'notnumbers': /[^\d]/g}
    function validation4number(o, w)
    {
        o.value = o.value.replace(r2[w], '');
    }
    function validation4pnumber(o, w)
    {
        if (o.value != '')
        {
            o.value = o.value.replace(r2[w], '');
            if (o.value <= 0 || o.value == '-')
            {
                //	alert('Please enter valid quantity.');
                o.value = 1;
            }
        }
        if (o.value == '')
        {
            o.value = 1;
        }
    }

// Value greater that 0 (not .decimal allowed)
    var r3 = {'notnumbers': /[^\d]/g}
    function validation4numeric(o, w)
    {
        o.value = o.value.replace(r2[w], '');
    }
</script>

<!--CONTENT AREA START-->

<div class="content_area contact-page-main">
<div class="med_area">
  <div class="med_arealeft page-contact">
    <div class="meetanthony_area">
      <div class="registered_area">
        <div class="inner_hed" style="padding:5px 0px 5px 0px;"> Contact Anthony </div>
      </div>
      <div class="contact_box">
        <div class="contact_box_first_line" style="  margin:5px 0px 0px 5px;" >Anthony Wilson <span >RD, MS</span> </div>
        <div class="contact_phone_box" style="  margin:0px 0px 2px 5px;">
          <!-- <div class="contact_phone_text" >Phone: 631.336.6153</div>--> 
        </div>
        <!--end contact_phone_box-->
        <div class="contact_phone_box" style="  margin:0px 0px 0px 5px;"> 
          <!--<div class="contact_phone_text">Email: <a href="mailto:Anthony@WeightLossHappens.com ">Anthony@WeightLossHappens.com </a></div>--> 
        </div>
        <!--end contact_phone_box-->
        <form method="post" action="" id="frmcontactus" name="frmcontactus" >
          <div class="mandatory_line" style=" margin:17px 5px 8px 0px; width:605px;"><span class="staric">*</span>Mandatory fields</div>
          <?php if (count($valid_array)) { ?>
          <div class="clear"></div>
          <div class="erorr error_fc" > <?php echo "" . show_error($valid_array) . ""; ?> </div>
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
                <input type="text" value="<?php echo $phone1; ?>"  maxlength="3" id="phone1" name="phone1" class="contactform1" onkeyup="validation4number(this, 'notnumbers')" style="width:60px;" />
                <span class="dotsym" margin:5px 2px 0 0;">-</span>
                <input type="text" value="<?php echo $phone2; ?>"  maxlength="3" id="phone2" name="phone2" class="contactform1" onkeyup="validation4number(this, 'notnumbers')"  />
                <span class="dotsym" margin:5px 2px 0 0;">-</span>
                <input type="text" value="<?php echo $phone3; ?>"  maxlength="4" id="phone3" name="phone3" class="contactform1" onkeyup="validation4number(this, 'notnumbers')"  />
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
    </div>
  </div>
 <div class="question"><a href="http://www.weightlosshappens.com/">Back to Homepage</a></div>
</div>
</div>
<!--CONTENT AREA END--> 
<script type="text/javascript">
//alert('hi'); 
        $('#contactus').addClass("current");

    </script>
<?php include('includes/footer.php'); ?>
