<?php if (file_exists($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php')) require($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php'); ?><?php
require_once('include/mainConnect.php');
require_once($config['absolute_path'].'classes/main.php');	

/*if($_SESSION['name']=='')
{
	header('location:index.php'); die;
}
else {	*/
?>
<?php include('includes/header.php') ;?>  


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
                <!--start application_box-->
                <div class="contact_box" style="margin-bottom:30px;">
                
                            
                                <div  style="margin-top:0px;  border:0px solid #000000; padding:0px;">
                                   <div class="hi">Hi <?php echo ucwords($_SESSION['name']);?>,</div>
                                    <div class="hi" style="margin-top:10px;">Thank you for your request for a FREE Consultation.</div>
                                   
                                   <div class="hi">I will get back to you shortly.</div>
                                   
                             
                                     
                                  <div class="contact_box_first_line" style="margin-top:22px;">Anthony Wilson, RD, MS</div>
                                   <!--<div class="contact_box_second_line" style="margin-bottom:2px;">West Islip, NY - 11795</div> 
                   
                 <div class="contact_phone_box">
                      <div class="contact_phone_text"><strong>Phone:</strong> 631.336.6153 </div>
                   </div>
                    
                    
                    <div class="contact_phone_box" style=" margin-bottom:17px;">
                        <div class="contact_phone_text"><strong>Email:</strong> <a href="mailto:Anthony@WeightLossHappens.com">Anthony@WeightLossHappens.com</a></div>
                    </div>-->
                                   
                                   
                                   </div>
                        
                   

                </div>
                <!--end application_box-->
                
            </div>
            <!--end application_left_area-->
     
        </div>
      </div>
        <div class="question"><a href="http://www.weightlosshappens.com/">Back to Homepage</a></div>
    </div>
    


 <?php include('includes/footer.php') ;?>  
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
<?php //}?>
