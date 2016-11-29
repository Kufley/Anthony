<?php if (file_exists($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php')) require($_SERVER['DOCUMENT_ROOT'].'/zblock/zbblock.php'); ?>
              <div class="med_arearight display_none">
                	<!--<div class="youtube"><img src="images/youtube.png" alt="youtube" class="youtube_border" /></div>-->
                    <div class="mission_statement_area">
					<?php if(!strstr($_SERVER['PHP_SELF'],'mission-statement.php'))  {?>
					
                    	<div class="mission_statement_main">
                        	<div class="mission_hed">Mission Statement</div>
                            <div class="mission_text">
                            Facilitate clients who truly desire to take control of their health by attaining a healthy body weight now!
                            </div>
                            <div class="readmore">
                        		<a href="mission-statement.php">Read more &gt;</a>
                        	</div>
                        </div>
                        <?php }?>
						<?php if(!strstr($_SERVER['PHP_SELF'],'executive-weight-loss.php'))  {?>
                        <div class="mission_statement_main">
                        	<div class="mission_hed2">Coaching Programs</div>
                            <div class="executive_text">
                            	<a href="coaching-programs.php"><img src="images/e.xecutive.jpg" alt="" class="executive" /></a>
                            	A personalized weight management blueprint tailored to your needs and goals which produces results and eliminates guesswork!
                            </div>
                        </div>
                        <div class="learnhelp">
                        	<a href="coaching-programs.php">Learn how I can help &gt;</a>
                        </div>
                        <?php }?>
                    </div>
                    </div>
                </div>