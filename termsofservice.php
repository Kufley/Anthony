<?php if (file_exists($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php')) require($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php'); ?><?php
require_once('include/mainConnect.php');
require_once($config['absolute_path'].'classes/main.php');	
?>
<?php include('includes/header.php') ;?>  

        <!--CONTENT AREA START-->
        <div class="content_area">
            <div class="med_area">
 <div class="popup_weightarticle_area">
        
    	<div id="content_1" class="content">	 
        <div class="popup_weightarticle_bottom">
            <div class="popup_weightarticle_main">
                <div class="popup_weightarticle_hed"></div>
                
                <div class="popup_weightarticle_contents">
                <h3> <center>TERMS OF SERVICE AGREEMENT</center></h3>
<ol>
 <h2><u><li>ASSESSMENT FORM:</li></u></h2> 
<p>Before any (paid) consulting begins, you MUST fill out the entire assessment form and return it to me,  signed. If you do not get the form to me at least 1 day before the time of our first paid consulting appointment, your first appointment is automatically rescheduled for the following week - no exceptions. If you do not want to answer all of the questions on the form, you must put your initials in the blank space provided for each numbered question signifying that you read the question and decided not to answer it. The information I receive on the assessment form is absolutely essential for me being able to see the big picture with your weight loss issues. The assessment form is there for YOUR benefit.</p> 

<h2><u><li>REFUNDS:</li></u></h2> 
<p>Full refunds are available for 72 hours starting from the following midnight of the day you purchase the program. There are no partial refunds given at any time unless I make an exception to the refund policy. </p>

<h2><u><li>(24/7) EMAIL SUPPORT:</li></u></h2> 
<p>Email support is limited to short-answer questions only. For questions that require a more detailed response, these questions need to be asked and discussed during our regular weekly session. 24/7 email support limits weekly email questions to 7 short-answer questions per week. You have the opportunity to ask one or more questions per day, or, all of them on the same day of the week. This is done to prevent clients from taking advantage of this policy. If for some reason you should need to ask more questions, just request it and if you have not been trying to take advantage of the policy it will almost definitely be answered. Anthony Wilson/ Anthony Wilson Consulting reserves the right to have the final say as to what constitutes a “short-answer” question.</p> 

<h2><u><li>PROGRAM CANCELLATION OF A CLIENT'S PROGRAM BY ANTHONY WILSON/ ANTHONY WILSON CONSULTING AFTER COACHING HAS BEGUN:</li></u></h2>
<p>Program cancellation of a clients program by Anthony Wilson/ Anthony Wilson Consulting is unlikely to happen. However, Anthony Wilson/ Anthony Wilson Consulting reserves the right to cancel any of his weight loss coaching programs for any of his clients for any reason. In the unlikely event of this occurring, a partial, pro-rated refund will be given solely for the remaining hours of your weight loss program that were not used through coaching or missed appointments. For instance, if you signed up for the Silver Coaching Program which consists of 20 hours of coaching, and you used 10 hours, did not show up for your appointment for 2 of them (without having given 24 hours advance notice for cancellation), you will be eligible for a pro-rated refund for the 8 hours you still had available in your program. If you paid $2,000 for your weight loss coaching program, which would equate to a $100. per session/ hour in this example, you would be eligible to receive a pro-rated refund in the amount of $800, for example. </p>

<h2><u><li>COACHING SESSIONS: STARTING AND ENDING TIMES </li></u></h2>
<p>All “hourly” coaching session consist of 55 minutes. Half hour (30 minute) coaching sessions consist of 25 minutes. Coaching sessions will start promptly at the time that has been agreed upon by both client and Anthony Wilson/ Anthony Wilson Consulting. If a client should be unable to begin their session at the time specified and agreed upon, their session will still end at the originally designated time without any refund or additional time added to their program. Thus, if a client has an 8:00 pm – 9:00 pm hourly coaching session appointment for their weight loss coaching program, and they show up at 8:30 pm for their 8:00 pm appointment, they will have used up 1 full hourly coaching session at the end of their session at 9:00 pm. Another example would be if a client has an hourly coaching session that is to begin at 10:00 am, and they do not show up for their coaching session until 9:45am. Their 'hourly' session will end promptly at 9:55 am, thus having used up one of their hourly coaching sessions from their program. </p>

<h3><u><li> WHAT TOPICS FROM THE WEIGHTLOSSHAPPENS.COM WEBSITE'S “COACHING PROGRAMS PAGE” ARE GUARANTEED TO BE COVERED DURING THE COACHING PROGRAM?</li></u></h3>
<p>Simply, we cover as many of the topics that are outlined on the website's 'Coaching Programs' page as we can. We may cover every topic there or just a few of them. It really just depends on where we collaboratively decide we want to spend the time (hours). Clients usually need to spend more time on certain topics and sometimes do not have a need for other topics. Therefore, there is no guarantee that all of the topics listed on the 'Coaching Programs' page will be covered during your coaching program, though our goal will certainly be to cover all of them unless you decide otherwise. </p>

<h3><u><li>ALL COACHING PROGRAMS EXPIRATION TIMELINE:</li></u></h3>
<p>All programs, and their respective coaching sessions, will expire 1 year from the date of purchase regardless of whether or not any or all of the weight loss coaching sessions and services have been used. </p>

<h3><u><li> DENIAL OF SIGN-UP FOR ANY COACHING PROGRAM:</li></u></h3>
<p>Anthony Wilson/ Anthony Wilson Consulting reserves the right to deny any individual the opportunity to sign-up for and pay for any of his weight loss coaching programs for any reason or no reason at all. If for some reason any individual whom he chooses not to coach for any of his programs does sign up and pay for, in full or part, one of his coaching programs, regardless of whether that individual has been notified in advance or not as to being denied the opportunity to sign up for any of the coaching progams, the individual will be given a full refund (minus any transactions fees) and no coaching services will commence at any time. </p>
</ol>
<form onsubmit="return checkForm(this);" action="https://www.paypal.com/cgi-bin/webscr">
<input type="checkbox" name="terms" /> By checking this box you agree to the terms and conditions of the TERMS OF SERVICE AGREEMENT  <br />
<p><input type="submit" name="Submit" value="Submit"></p> </form>
</div></div></div></div></div>

</div>
</div>
<?php include('includes/footer.php') ;?>  
<script type="text/javascript">

  function checkForm(form)
  {
    if(!form.terms.checked) {
      alert("Please indicate that you accept the Terms and Conditions");
      form.terms.focus();
      return false;
    }
    return true;
  }

</script>