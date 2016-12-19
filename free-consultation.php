<?php if (file_exists($_SERVER['DOCUMENT_ROOT'] . '/zblock/zbblock.php')) require($_SERVER['DOCUMENT_ROOT'] . '/zblock/zbblock.php'); ?><?php
require_once($config['absolute_path'] . 'include/mainConnect.php');
require_once($config['absolute_path'] . 'classes/main.php');

if (isset($_POST['submit']) && $_POST['submit'] != '' && $_POST['submit'] == 'submit') {
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
            $elems[] = array('name' => 'phone2', 'label' => 'phone: Please enter your phone number.', 'type' => 'text', 'required' => true, 'len_max' => '3');
        }
        if ($phone3 == '') {
            $elems[] = array('name' => 'phone3', 'label' => 'phone: Please enter your phone number.', 'type' => 'text', 'required' => true, 'len_max' => '3');
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

    } else {

        $error = $mainClass->addConsultation();

    }


}
?>
<?php include('includes/header.php'); ?>
<script type="text/javascript" src="<?php echo $config['site_url']; ?>js/dcommon_functions_usingjq.js"></script>

<script type="text/javascript" src="<?php echo $config['site_url']; ?>js/validation_js.js"></script>
<script language="javascript" type="text/javascript">


    // usage onKeyUp="validation4number(this,'notnumbers')"
    var r2 = {'notnumbers': /[^\d]/g}
    function validation4number(o, w) {
        o.value = o.value.replace(r2[w], '');
    }
    function validation4pnumber(o, w) {
        if (o.value != '') {
            o.value = o.value.replace(r2[w], '');
            if (o.value <= 0 || o.value == '-') {
                //	alert('Please enter valid quantity.');
                o.value = 1;
            }
        }
        if (o.value == '') {
            o.value = 1;
        }
    }

    // Value greater that 0 (not .decimal allowed)
    var r3 = {'notnumbers': /[^\d]/g}
    function validation4numeric(o, w) {
        o.value = o.value.replace(r2[w], '');
    }

</script>
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
<?php //include_once('popup_manager/open_popup_js.php');?>
<link href="<?php echo $config['site_url']; ?>popup_manager/popup.css" rel="stylesheet" type="text/css"/>
<!--CONTENT AREA START-->
<div class="content_area">
    <div class="med_area">
        <div class="med_arealeft width-100">
            <div class="meetanthony_area meetanthony_area_contact">
                <div class="registered_area">
                    <a name="top"></a>
                    <div class="inner_hed"> Free Consultation</div>
                    <div class="consultation_line">Would you like to know how a Registered Dietitian and Behavior
                        Therapist can help you?
                    </div>
                </div>
                <div class="consultation_box">
                    <div class="consultation_box_first_line">What will I achieve with the help of a Registered Dietitian
                        and Behavior Therapist?
                        <p style="margin: 0px 0px 0px 0px; padding:8px 0px 0px 0px;">By working with the guidance of an
                            experienced Registered Dietitian and Behavior Therapist, you are putting yourself in the
                            best position to be successful with your weight management goals! </p>
                        <p>Anthony, a graduate of Cornell University, has been assisting individuals with achieving
                            their desired body weight for close to 20 years. </p>
                        <p>While working with Anthony, someone who takes a 'complete approach' to weight management,
                            together you will create a "recipe for success" which incorporates the different elements
                            that factor into being successful.</p>
                        <p>These would include such things as your current blood work, medical history, dietary intake,
                            types and amounts of physical activity, habits and behaviors, food and nutrition knowledge,
                            stress levels, goals, beliefs, and current obstacles and roadblocks that you need to
                            overcome to be successful. </p>
                        <p>With a dedicated effort and subsequent weight loss, you should expect to decrease your odds
                            of developing heart disease, stroke, diabetes, and numerous types of cancer. </p>
                        <p>Additionally, your risk of common complications and illnesses from being overweight or obese
                            such as bladder and bowel incontinence, insulin resistance, hypertension, sleep apnea,
                            asthma, polycystic ovarian syndrome, impaired fertility, osteoarthritis, high cholesterol,
                            gout, gall bladder disease, and respiratory problems will likely be significantly decreased
                            as well. </p>
                        <p>It is not surprising for clients to also experience a greater self&ndash;esteem and a more
                            focused and productive work day!</p>
                        <p>Whether it be due to feeling more comfortable in your clothing, to decreased stress levels,
                            being able to participate in activities you didn't participate in before like athletic
                            endeavors or social events, or just knowing that your odds of living a longer and more
                            fulfilling life has increased, weight loss clients generally report feeling happier, having
                            a more balanced life, and greater peace of mind. </p>
                        <p style="padding-bottom:20px;">While on your weight loss journey, Anthony will show you
                            unwavering dedication as you both work together to achieve your health and wellness
                            goals!</p>
                    </div>
                    <div class="consultation_box_first_line">Why Should I Choose Weight Loss Happens?
                        <p style="margin: 0px 0px 0px 0px; padding:8px 0px 0px 0px;">Weight Loss Happens is uniquely
                            different for a number of reasons. Anthony Wilson, RD, MS is probably the only Registered
                            Dietitian in the country who is also a Behavior Therapist. </p>
                        <p>What is so beneficial about this is that nutrition and behavior change are highly
                            interconnected areas and critical for weight management success. </p>
                        <p>Anthony has also worked as a sports dietitian helping athletes to eat optimally for their
                            workouts and competition while trying to lose weight at the same time. This same sports
                            nutrition is utilized with clients who are incorporating physical activity as part of their
                            weight management plan.</p>
                        <p>One of the areas that Anthony specializes in, behavior change, is a central principle when it
                            comes to your weight management plan and making important, positive changes such as
                            eliminating behaviors that inhibit your ability to lose weight and reach your desired body
                            weight. </p>
                        <p>Anthony's experience and knowledge with behavior therapy, as well as his ability to connect
                            with people facilitates him in getting clients to take the actions that lead them to
                            achieving success with their weight
                            management plan.</p>
                        <p>One of the behaviors that many clients would like to change is how much they engage in
                            physical activity. Even though weight management clients can lose a significant amount of
                            weight without
                            exercise, engaging in physical activity facilitates clients with reaching their desired
                            weight faster. </p>

                    </div>
                    <div class="consultation_box_first_line" style="border-bottom:none;">How beneficial is phone and
                        computer coaching?
                        <p style="margin: 0px 0px 0px 0px; padding:8px 0px 0px 0px;">Studies have shown that phone and
                            computer coaching is at least as effective as in-person coaching. </p>
                        <p>If you have ever been involved with any type of coaching over the phone you know that phone
                            coaching is very efficient. Simply, there are fewer distractions that take up time so both
                            client and coach
                            generally get right to work at the start of the coaching session. </p>
                        <p>Additionally, phone coaching is very convenient since you don't have to leave your office
                            every time you have a session, which is a real time-saver. </p>
                        <p>Anthony offers clients the choice of coaching over the phone or face-to-face coaching over
                            the computer through the use of Skype. </p>
                        <p>His first experience with phone and computer coaching was with the company Gordian Health
                            Solutions in Franklin, TN. </p>
                        <p>Immediately upon working with clients over the phone he noticed how focused and productive
                            sessions were, and thus, how successful phone and computer coaching could be. </p>
                        <p>His primary area with phone coaching was weight management and he regularly received
                            excellent feedback from clients and supervisors and saw excellent results. </p>
                        <p>Anthony estimates that he helped over 1,000 individuals work towards their weight management
                            goals through this mode of coaching.</p>
                    </div>
                </div>
                <div class="contact_box contact_box_form">
                    <div class="consultation_bottom_line">
                        <p><a name="fr"></a>The bottom line is that Anthony will facilitate you in reaching your weight
                            management goals by targeting the critical areas for success as he has done for so many
                            happy and successful individuals! </p>
                        <p>Please fill out the Free Consultation form and someone will contact you to set up a day and
                            time for your Free consultation!</p>
                        <p style="font-size: 18px; margin: 20px 0 10px;">FREE CONSULTATION</p>
                    </div>


                    <form method="post" action="" id="frmConsultation" name="frmConsultation">
                        <div class="mandatory_line" style=" margin:5px 0px 8px 0px; padding: 0;"><span
                                class="staric">*</span>Mandatory fields
                        </div>
                        <?php if (count($valid_array)) { ?>
                            <div class="clear"></div>
                            <script type="text/javascript" language="javascript"> window.location.href = '#fr';</script>
                            <div class="erorr"
                                 style="font-family:Arial, Helvetica, sans-serif; font-size:12px; font-weight:bold; text-align:center; color:#FF0000; padding-bottom:20px;">
                                <?php

                                echo "" . show_error($valid_array) . ""; ?>
                            </div>
                        <?php } ?>


                        <div class="contact_name_line">
                            <div class="contact_name_text"><span class="staric_first">*</span>Name</div>
                            <div class="contact_name_field">
                                <input type="text" value="<?php echo $name; ?>" maxlength="100" id="name" name="name"
                                       class="contact_name_field_text"/>
                                <div class="clear"></div>
                                <span class="validation_error" id="nameInfo"></span></div>
                        </div>
                        <!--end contact_name_line-->
                        <div class="contact_name_line">
                            <div class="contact_name_text"><span class="staric_first">*</span>Email</div>
                            <div class="contact_name_field">
                                <input type="text" value="<?php echo $email; ?>" maxlength="70" id="email" name="email"
                                       class="contact_name_field_text"/>
                                <div class="clear"></div>
                                <span class="validation_error" id="emailInfo"></span></div>
                        </div>
                        <!--end contact_name_line-->
                        <div class="contact_name_line">
                            <div class="contact_name_text"><span class="staric_first">*</span>Phone</div>
                            <div class="contact_name_field phone_field">
                                <input type="text" value="<?php echo $phone1; ?>" maxlength="3" id="phone1"
                                       name="phone1" class="contactform1"
                                       onkeyup="validation4number(this,'notnumbers')"/>
                                <span style=" margin:5px 2px 0 0;">-</span>
                                <input type="text" value="<?php echo $phone2; ?>" maxlength="3" id="phone2"
                                       name="phone2" class="contactform1"
                                       onkeyup="validation4number(this,'notnumbers')"/>
                                <span style=" margin:5px 2px 0 0;">-</span>
                                <input type="text" value="<?php echo $phone3; ?>" maxlength="4" id="phone3"
                                       name="phone3" class="contactform1"
                                       onkeyup="validation4number(this,'notnumbers')"/>
                                <div class="clear"></div>
                                <span class="validation_error" id="phoneInfo"></span>
                            </div>
                        </div>
                        <div class="contact_name_line">
                            <div class="contact_ph_text">Company</div>
                            <div class="contact_name_field">

                                <input name="company" value="<?php echo $company; ?>" id="company" type="text"
                                       class="contact_name_field_text" maxlength="100"/>
                                <div class="clear"></div>
                                <span class="validation_error" id="companyInfo"></span></div>
                        </div>

                        <div class="contact_name_line">
                            <div class="contact_name_text"><span class="staric_first">*</span>Comments</div>
                            <div class="contact_name_field">
                                <textarea id="comments" name="comments" cols="49" rows="4"
                                          class="textarea"><?php echo $comments; ?></textarea>
                                <div class="clear"></div>
                                <span class="validation_error" id="commentInfo"></span>
                            </div>

                            <!--end contact_name_line-->
                            <div class="free_tab" style="padding-top:33px;">
                                <input name="submit" value="submit" id="submit" type="hidden"/>
                                <input src="images/consultation.png" type="image" style="cursor:pointer;" value=""
                                       name="submit_local">
                                <br> <b> If you receive a 'Thank You' page after submitting your form, it was
                                    successfully sent!
                                    <!--If not successful, please email directly at <a href="mailto:Anthony@WeightLossHappens.com">Anthony@WeightLossHappens.com</a>--></b>
                            </div>
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
<?php include('includes/footer.php'); ?>
 