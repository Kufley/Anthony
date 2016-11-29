<?php if (file_exists($_SERVER['DOCUMENT_ROOT'] . '/zblock/zbblock.php')) require($_SERVER['DOCUMENT_ROOT'] . '/zblock/zbblock.php'); ?>
<?php
error_reporting(E_ALL);
session_start();
require_once('include/mainConnect.php');
require_once($config['absolute_path'] . 'classes/main.php');

if (isset($_POST['submit']) && $_POST['submit'] != '' && $_POST['submit'] == 'submit') {

    $_SESSION['name'] = $_POST['fname'];
// print_r($_POST); die;
    $fname = $mainClass->outputData($_POST['fname']);
    $lname = $mainClass->outputData($_POST['lname']);
    $email = $mainClass->outputData($_POST['email']);
    $phone = $mainClass->outputData($_POST['phone']);
    $comments = $mainClass->outputData($_POST['comments']);


    // Server Side vaidation starts
    $elems[] = array('name' => 'fname', 'label' => 'Name: Please Enter Your First Name', 'type' => 'text', 'required' => true, 'cont' => 'nameVal', 'len_max' => '40');
    $elems[] = array('name' => 'lname', 'label' => 'Company: Please Enter Your Last Name', 'type' => 'text', 'len_max' => '40');
    if ($email == '') {
        $elems[] = array('name' => 'email', 'label' => 'Email: Please Enter Your Email Address', 'type' => 'text', 'required' => true, 'cont' => 'email');
    } else {
        $elems[] = array('name' => 'email', 'label' => 'Email: Please Enter Your Valid Email Address', 'type' => 'text', 'required' => true, 'cont' => 'email');
    }
    if ($phone == '') {
        $elems[] = array('name' => 'phone', 'label' => 'Phone: Please Enter Your Valid Phone Number', 'type' => 'text', 'required' => true, 'len_max' => '10');

    }
    $elems[] = array('name' => 'comments', 'label' => 'Message: Please Enter Your Message', 'type' => 'text', 'required' => true);


    $f = new FormValidator($elems);
    $err = $f->validate($_POST);

    if ($err === true) {
        $ret = $f->getValidElems();
        if (is_array($ret))
            $valid_array = $ret;
        //print_r($valid_array);

    } else {

        $error = $mainClass->addContact();
//var_dump($mainClass);
//var_dump($error); die();

    }


}
include('includes/header.php');
?>
<link href='https://fonts.googleapis.com/css?family=Abel' rel='stylesheet' type='text/css'>
<link href="<?php echo $config['site_url']; ?>font/stylesheet.css" rel="stylesheet" type="text/css">
<link href="http://fonts.googleapis.com/css?family=Oswald:400,300,700" rel="stylesheet" type="text/css"/>
<link href="https://fonts.googleapis.com/css?family=Lato:400,400i" rel="stylesheet">
<link href="<?php echo $config['site_url']; ?>css/owl.carousel.css" rel="stylesheet">
<link href="<?php echo $config['site_url']; ?>css/owl.theme.css" rel="stylesheet">

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
<div class="content-purple-area-main">
    <div class="container">
        <div class="how-much-weight-main">
            <h1>How Much Weight Do You Want To Lose
                In The Next 3-6 Months?</h1>
            <p>With the coaching program that pays for itself!</p>
            <div class="free-consult-purple">
                <h2>*FREE 2 – HR CONSULTATION!</h2>
                <a href="#contactform-box">Sign up Now!</a></div>
        </div>
        <div class="anthony-section-left small-size">
            <div class="anthony-details-top ">
                <div class="meetanthony_right">
                    <h2>WANT TO LOSE WEIGHT, BUT DON'T KNOW WHERE TO BEGIN?</h2>
                    <h3>Your "Dream Weight" Coaching Program helps you reach your desired bodyweight now! </h3>
                </div>
            </div>
        </div>

        <div class="anthony-section">

            <div class="meetanthony_left"><a href="about-anthony.php"><img width="208" height="251"
                                                                           src="images/anthony.jpg"
                                                                           alt="meetanthony"></a>
                <div class="name-profile"><span class="name-div"><a href="about-anthony.php">Anthony Wilson</a>, <b>RD,
                            MS</b></span>
                    <p>Registered Dietitian &<br/>
                        Behavior Therapist </p>
                </div>
            </div>
            <div class="anthony-section-left">
                <div class="anthony-details-top">
                    <div class="meetanthony_right">
                        <h2>WANT TO LOSE WEIGHT, BUT DON'T KNOW WHERE TO BEGIN?</h2>
                        <h3>Your "Dream Weight" Coaching Program helps you reach your desired bodyweight now! </h3>
                        <h4>Say goodbye to frustration,<br>
                            and hello to success!!</h4>
                    </div>
                </div>
            </div>
            <div class="coaching-program-right">
                <div class="coaching-top">
                    <h5>Dream Weight <br/>
                        Coaching Programs</h5>
                    <ul>
                        <li><a href="http://www.weightlosshappens.com/gold-landing.php">GOLD</a></li>
                        <li><a href="http://www.weightlosshappens.com/silver-landing.php">SILVER</a></li>
                        <li><a href="http://www.weightlosshappens.com/bronze-landing.php">BRONZE</a></li>
                    </ul>
                </div>
                <div class="coaching-middle">
                    <h3>choose a program - <br/>
                        "click one"</h3>
                </div>
                <div class="coaching-top">
                    <h5>Mission Statement</h5>
                    <p>Facilitate clients who truly desire to take control of their health by attaining a healthy body
                        weight now! </p>
                    <span><a href="mission-statement.php">read more</a> +</span></div>
            </div>

        </div>

        <div class="anthony-section-left small-size">
            <div class="anthony-details-top ">
                <div class="meetanthony_right">
                    <h4>Say goodbye to frustration,<br>
                        and hello to success!!</h4>
                </div>
            </div>
        </div>
        <div class="errow-icon"><a href="#bottom"><img src="images/errow-icon.png" alt=""></a></div>
    </div>
    <div class="program-main" id="bottom">
        <div class="container">
            <div class="prog-main">
                <h3>With the Dream Weight Coaching Program <br/>
                    you'll learn to:</h3>
                <ul>
                    <li>Eat all types of food and still lose weight!</li>
                    <li>Increase your metabolism without dangerous drugs!</li>
                    <li>Eat in a way whereby you never feel deprived again!</li>
                    <li>Substitute higher calorie ingredients and foods for great
                        tasting lower calorie ones!
                    </li>
                    <li>Lose weight by eating in a way that you'll eat for the rest of
                        your life!
                    </li>
                    <li>Avoid hitting plateaus that cause you to have to consume less
                        calories to continue losing weight!
                    </li>
                    <li>Avoid feeling hungry in between meals!</li>
                    <li>And much, much more!</li>
                </ul>
            </div>
            <div class="pro-icon"><a href="#feature-bottom"><img src="images/errow-icon.png" alt=""></a></div>
        </div>
    </div>
    <div class="feature-main" id="feature-bottom">
        <div class="container">
            <div class="feat-main">
                <h3>A few of the features that you get with the Dream Weight Coaching
                    Program are: </h3>
                <ul>
                    <li>Support System!
                        <h4>24/7 email support!</h4>
                    </li>
                    <li>Experienced Professional!
                        <h4>Work with an experienced weight loss expert who has helped
                            over 1,000 clients!</h4>
                    </li>
                    <li>Personalized Plan!
                        <h4>A personalized step-by-step dietary and behavioral plan!</h4>
                    </li>
                    <li>Strategic Roadblock & Obstacle Analysis!
                        <h4>A strategy to determine & overcome the main road blocks &
                            obstacles that are holding you back from reaching your desired
                            body weight! </h4>
                    </li>
                    <li>Convenience!
                        <h4>With phone and online consulting you don't have to leave
                            your home or office to get the help you need!</h4>
                    </li>
                </ul>
            </div>
        </div>
    </div>
    <div class="wilson-main">
        <div class="container">
            <div class="resg-main">
                <h3>Anthony Wilson, Registered Dietitian Nutritionist & Behavior Therapist, helps you approach weight
                    management from a 3-pronged perspective:</h3>
                <div class="weight-main">
                    <div class="nutri-main">
                        <div class="nutri-icon"><img src="images/nutrition-icon.png" alt=""></div>
                        <h3>Nutrition</h3>
                    </div>
                    <div class="nutri-main">
                        <div class="nutri-icon"><img src="images/exer-icon.png" alt=""></div>
                        <h3>Exercise</h3>
                    </div>
                    <div class="nutri-main">
                        <div class="nutri-icon"><img src="images/up-down-errow.png" alt=""></div>
                        <h3>Behavior change</h3>
                    </div>
                </div>
                <div class="start-button"><a href="http://www.weightlosshappens.com/coaching-programs.php">START LOSING
                        NOW!</a></div>
            </div>
        </div>
    </div>
    <div class="testimonal-main">
        <div class="container">
            <div class="testi-text">
                <h3>Testimonials</h3>
                <p class="justify">"I lost 80# working with Anthony and I have a new life now thanks to him! Anthony was
                    very professional. He made me feel comfortable by taking things slowly and working at a pace that
                    I was comfortable with. I could see that he really cared about my condition and that he didn't want
                    to see me have long-term problems. After only working with Anthony for a short while, I trusted that
                    he had my best interests at heart. This really helped me to trust him which made it
                    easier to take his professional advice and make lasting changes with my lifestyle. You'll love
                    working with Anthony - he's very professional and humorous too!"</p>
                <h4><span>Jeannine N.&nbsp</span>-&nbspCornell University</h4>
            </div>
        </div>
    </div>
</div>
<div class="get-main">
    <div class="container">
        <div class="meet-anthony">
            <h2>Meet Anthony</h2>
            <div class="play_video">
                <iframe width="560" height="315"
                        src="https://www.youtube.com/embed/_byJ0IzCAAw?rel=0&amp;controls=0&amp;showinfo=0"
                        frameborder="0" allowfullscreen></iframe>
            </div>
        </div>
    </div>
</div>
<div class="button-section-main">
    <div class="container">
        <div class="free-cnsutant-green">
            <h1>*FREE 2 – HR CONSULTATION!</h1>
            <a href="#contactform-box">Sign up Now!</a></div>
        <h2>WHAT CAN I HELP YOU WITH?</h2>
        <ul>
            <li><a href="javascript:void(0)">PORTION CONTROL</a></li>
            <li><a href="javascript:void(0)">ACCOUNTABILITY</a></li>
            <li><a href="javascript:void(0)">SUPPORT SYSTEM</a></li>
            <li><a href="javascript:void(0)">EMOTIONAL EATING</a></li>
            <li><a href="javascript:void(0)">DEPRESSION</a></li>
            <li><a href="javascript:void(0)">MEAL PLANNING</a></li>
            <li><a href="javascript:void(0)">NUTRITION EDUCATION</a></li>
            <li><a href="javascript:void(0)">SNACKING</a></li>
            <li><a href="javascript:void(0)">CONFIDENCE</a></li>
            <li><a href="javascript:void(0)">DIABETES CONTROL</a></li>
            <li><a href="javascript:void(0)">LIMITING BELIEFS</a></li>
            <li><a href="javascript:void(0)">CONTROLLING STRESS</a></li>
            <li><a href="javascript:void(0)">TIME MANAGEMENT</a></li>
            <li><a href="javascript:void(0)">HEALTHY HABITS</a></li>
            <li><a href="javascript:void(0)">EATING DISORDER</a></li>
        </ul>
        <h1>GET HELP NOW!</h1>
        <div class="program"><a href="http://www.weightlosshappens.com/bronze-landing.php"><img src="images/bronze.png"
                                                                                                alt="bronge"/></a><a
                href="http://www.weightlosshappens.com/silver-landing.php"><img src="images/silver.png"
                                                                                alt="silver"/></a> <a
                href="http://www.weightlosshappens.com/gold-landing.php"><img src="images/gold.png" alt="gold"/></a>
        </div>
    </div>
</div>
<div class="testimonals-main">
    <div class="container">
        <div class="test-text">
            <h3>testimonials</h3>
        </div>
        <div class="slider">
            <div id="demo">
                <div class="container">
                    <div class="row">
                        <div class="span12">
                            <div id="owl-demo" class="owl-carousel">
                                <div class="item">
                                    <div class="slide-show">
                                        <div class="abo-new-main">
                                            <p>I'm a diabetic who has been overweight most of my life and has suffered
                                                with bowel incontinence since becoming obese. From the first time I
                                                worked with Anthony he started educating me about nutrition & diabetes
                                                and I was amazed to learn that I held so many myths about nutrition in
                                                general. If I had not been educated by Anthony, I would still be going
                                                down the wrong path wondering why my conditions and weight weren't
                                                getting any better. Anthony really opened my eyes about the connections
                                                between nutrition, beating diabetes and living a healthier, more
                                                enjoyable life.</p>
                                        </div>
                                        <div class="client-bottom">
                                            <div class="client-image"><img src="images/client-image.png" alt=""></div>
                                            <div class="client-text">
                                                <p><span>Betty E.</span>Ithaca, NY</p>
                                            </div>
                                        </div>
                                    </div>
                                    <div class="slide-show">
                                        <div class="abo-new-main">
                                            <p>Working with Anthony was a pleasure. I could tell he had been doing this
                                                for a long time. He looked at my situation and started making
                                                suggestions right away. Simply, I started doing what he said and it
                                                worked! I developed a new way of eating whereby I was not hungry, did
                                                not feel deprived, and started losing weight. As I've continued to do
                                                what he said, I continue to keep the weight off and feel very content
                                                with my new eating pattern. For the first time in years I feel like my
                                                chances of getting cancer are down and that my knees & back are finally
                                                on the mend. Thanks Anthony!</p>
                                        </div>
                                        <div class="client-bottom">
                                            <div class="client-image"><img src="images/client-image.png" alt=""></div>
                                            <div class="client-text">
                                                <p><span>LEAH. D</span>Ithaca, NY</p>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                                <div class="item">
                                    <div class="slide-show">
                                        <div class="abo-new-main">
                                            <p>Anthony was very professional. I was hesitant to get help with my
                                                condition because I didn’t want someone criticizing my behaviors and
                                                telling me I should do this and that when I really didn’t want to.
                                                Anthony focused our time and efforts on creating a mutually agreeable
                                                strategy whereby we put together nutrition and behavioral plans that
                                                kept me focused from the beginning of our time together. In the past I
                                                jumped from trying one idea to trying another without ever stayed
                                                focused. Anthony kept me very focused – that was the ultimate key to my
                                                success! </p>
                                        </div>
                                        <div class="client-bottom">
                                            <div class="client-image"><img src="images/client-image.png" alt=""></div>
                                            <div class="client-text">
                                                <p><span>Sam C.</span>West Islip, NY</p>
                                            </div>
                                        </div>
                                    </div>
                                    <div class="slide-show">
                                        <div class="abo-new-main">
                                            <p>Anthony really cares about you. I have worked with other clinicians in
                                                the past that seemed to just be going through the motions. Anthony was
                                                different. He was very knowledgeable like many other clinicians, but he
                                                also really cared about me personally which inspired me to become the
                                                healthiest person I could be. When you feel that someone else really
                                                cares about you first and foremost, it’s motivating. I wish I had met
                                                Anthony sooner.</p>
                                        </div>
                                        <div class="client-bottom">
                                            <div class="client-image"><img src="images/client-image.png" alt=""></div>
                                            <div class="client-text">
                                                <p><span>Carl S.</span>Nashville, TN</p>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>
<div class="permanent-main">
    <div class="container">
        <div class="step-top">
            <h3>Weight Loss Articles</h3>
            <a href="weight-loss-articles.php">More articles</a></div>
        <div class="front-main">
            <div class="steps-main">
                <h3>LACK OF PROFESSIONAL GUIDANCE: 10 CONSEQUENCES</h3>
                <div class="Realize-main lack">
                    <div class="main-relize">
                        <div class="realize-left"><img src="images/doc-image.png" alt=""></div>
                        <div class="realize-right">
                            <h3>LOSS OF MOTIVATION MUCH MORE LIKELY:</h3>
                            <p>One of the top motivators that keeps individuals continuing their weight loss journey is
                                SUCCESS! Simply, working with a professional greatly increases your chances of success
                                with your weight loss and that initial success will be critical for maintaining
                                motivation as you move forward down your weight loss path.</p>
                            <p>This happens for numerous reasons such as when you are working with someone you are aware
                                that the individual you are working with is counting on you to be successful.</p>
                        </div>
                    </div>
                    <div class="way-main">
                        <p>Often in a working relationship your desire is to be successful first and foremost for
                            yourself, but also, you don't want to let the person assisting you down and that can be very
                            motivating for you especially at times when you might otherwise falter. Similarly, having
                            this other person hold you accountable keeps you on your toes and you are more inclined to
                            do what's in you best interests, and with this, you attain more success which fuels your
                            motivation very positively!</p>
                    </div>
                    <div class="way-main">
                        <h3>BURNING LESS CALORIES DUE TO DEFICIENT BLOOD WORK:</h3>
                        <p>Not being aware of what your blood work is showing and not knowing exactly what you need to
                            do for it can cost you in terms of weight loss. For instance, when your red blood cell
                            count, hemoglobin, and iron levels are low, that can have a large negative impact on your
                            ability to burn calories. </p>
                        <p>Even though you may have had these tests run previously, they may not have been tested in
                            some time. Also, your doctor rarely has the time to go over your blood work in depth with
                            you such as discussing how and why your blood work got low, and exactly what you need to do
                            to get those levels back to normal and higher.</p>
                        <p>One of the 1st things I do with clients is discuss recent or brand new blood work. We
                            determine what must be done to get your deficiencies corrected and then we apply it to your
                            weight loss plan. </p>
                    </div>
                    <div class="way-main">
                        <h3>SLOWER GAINS DUE TO INACCURATE NUTRITION & WEIGHT LOSS INFORMATION:</h3>
                        <p>When you don't have accurate nutrition and weight loss information by which to plan your
                            weight loss journey, you end up making slower gains even though you think you are doing
                            everything right. Sooner or later you start to struggle to lose any weight. Slower gains are
                            common when you have inaccurate information and flawed strategies </p>
                        <p>Consequently, many individuals find themselves starting over numerous times since they don't
                            have much success due to basing their weight management plan on misinformation and often
                            times poor planning as well.</p>
                    </div>
                    <div class="way-main">
                        <h3>QUITTING DUE TO A LACK OF FOLLOW-THRU:</h3>
                        <p>Many individuals have been learning about weight loss for a long time, but ultimately don't
                            come close to reaching their dream weight due to a lack of follow-through, plain and simple.
                            This could be due to many reasons such as a lack of knowledge, fear, lack of initial
                            success, or other reasons. Whatever the reason, follow-through is absolutely necessary for
                            success! Working with a professional will almost always help you to follow-through. </p>
                    </div>
                    <div class="way-main">
                        <h3>WEIGHT GAIN, NOT WEIGHT LOSS:</h3>
                        <p>Weight gain, not weight loss, due to unintentional yo-yo 'dieting' often occurs. Many
                            individuals start their weight loss plan, but then for one reason or another, stop shortly
                            thereafter. Unfortunately, the end result is a higher body fat percentage and a slower
                            metabolism. This is the result of losing muscle and gaining fat mass which happens when you
                            decrease your caloric intake for a while and then abruptly go back to eating the same number
                            of calories that you were eating before you started your weight loss plan. </p>
                        <p>When you make that abrupt change, your metabolism is lower and not expecting to get as many
                            calories as you used to feed it just a short while ago. So you end up over-consuming
                            calories during that time. It doesn't seem like you are over-consuming calories because that
                            is the same number of calories you used to consume.</p>
                    </div>
                    <div class="way-main">
                        <h3>SLOWER GAINS DUE TO POOR GOAL-SETTING:</h3>
                        <p>Another top key when it comes to motivation is goal-setting. It is very useful to make daily,
                            short & long-term goals and to make them in a way that will benefit you the most. Many times
                            individuals' goal-setting was not created ideally and It doesn't motivate them the way that
                            it should, if at all. Goal-setting that really motivates helps to keep you focused and
                            driven especially during difficult times! Effective goal-setting is critical!</p>
                    </div>
                    <div class="way-main">
                        <h3>TREMENDOUS FRUSTRATION: </h3>
                        <p>Not having someone you trust to turn to for advice when you hit obstacles or are unsure about
                            which is the best way to proceed with something leads to, among other things, tremendous
                            frustration. And then you guess as to what to do and likely end up being even more
                            frustrated. This is one of the benefits of working with a trusted professional – you always
                            have someone to turn to for expert advice! </p>
                    </div>
                    <div class="way-main">
                        <h3>SLOWER GAINS DUE TO THE BELIEF THAT YOU WILL NOT BE SUCCESSFUL: </h3>
                        <p>Many individuals trying to lose weight and maintain that weight loss have tried to do so in
                            the past and have failed. Because of that many have adopted the belief that, as much as they
                            truly want to lose weight, they won't be successful with losing weight. Ultimately, your
                            limiting beliefs will affect your actions which will almost definitely have a negative
                            impact on your food choices and how you forward with your weight loss plan. </p>
                    </div>
                    <div class="way-main">
                        <h3>SLOWER PROGRESS DUE TO DEFICIENT WEIGHT LOSS PRESCRIPTION: </h3>
                        <p>It's difficult for you to put together your best dietary "prescription" for your weight loss
                            journey without taking into account your past and current medical conditions, among other
                            things, and exactly how they factor in. For instance, if you have had your gallbladder
                            removed you would need to know that you need to consume low fat meals for the rest of your
                            life or else you will have chronic diarrhea, everyday. </p>
                        <p>If you have diabetes you would need to know the most successful ways to plan your meals and
                            snacks which would involve knowing the best ways to control and overcome your diabetes.
                            Without nutrition and medical training you might be unaware of how to do this which would
                            slow your progress down.</p>
                    </div>
                    <div class="way-main">
                        <h3>LESS CALORIES BURNED FROM A WORKOUT:</h3>
                        <p>Knowing what to eat before and after your workouts is critical so that you can get the most
                            out of those workouts. Depending on what your goals are for your workouts, your nutrition
                            prescription will vary. Many individuals base their pre- and post-workouts meals and snacks
                            on false information and do not consume what will benefit them the most. The poorer your
                            workout nutrition plan, the less energy you'll have for burning calories during your
                            workouts.</p>
                    </div>
                </div>
            </div>
            <!--<div class="steps-main">
                  <h3>3 practices to drastically reduce your calories</h3>
                  <div class="Realize-main mCustomScrollbar">
                    <div class="main-relize">
                      <div class="realize-left"> <img src="images/calo-image.jpg" alt=""> </div>
                      <div class="realize-right">
                        <h3>3 Practices to drastically reduce
                          your calories</h3>
                        <p>Do you realize that you've been brainwashed and you don't even know it? Many people grew up being told that "there are many starving children in the world" and "you can't leave the table until you clean your plate."</p>
                        <p>You may have also been told that "wasting food means wasting money." For whatever reason, you have been conditioned to clean everything from your plate. But don't feel bad, you are not alone!</p>
                      </div>
                    </div>
                    <div class="way-main">
                      <h3>Extra food</h3>
                      <p>I estimate that many people consume about 25% - 50% more food at mealtimes (especially dinner) than their bodies want or need. Why does</p>
                      <p>this happen? The main answer is that they are cleaning their plates after they have gotten signals from their brain that they are starting to get full, which is the point at which they should stop eating. However, many of us keep eating, even though it would be better to have stopped.</p>
                      <p>So how did that extra food get there in the first place? For starters, people have been conditioned, out of habit, to cover their entire plate with food. This process has been helped along by the fact that most of us make too much food to begin with. As a result, there is more food available to us, and when there is more food available to us, the bottom line is that we eat more of it.</p>
                    </div>
                    <div class="way-main">
                      <h3>Easiest way to cut your amount</h3>
                      <p>The easiest way to cut down on the amount of food you take is to use a smaller plate. This way even if you fill your plate to capacity, you have less than you normally would because the size of your plate is smaller.</p>
                      <p>So for your next dinner meal, instead of using your typical dinner plates, use smaller plates, like lunch plates. You may need to go out and buy different sized plates, but it should be well worth the money!</p>
                    </div>
                  </div>
                </div>-->
        </div>
    </div>
</div>
<!-- <div class="white-space"> </div>-->
<div class="Transform-main">
    <div class="container">
        <div class="tras-main">
            <div class="Transform-list">
                <ul>
                    <li><a href="#">Get the free consultation!</a></li>
                    <li><a href="#">Get your questions answered!</a></li>
                    <li><a href="#">Get motivated!</a></li>
                    <li><a href="#">Get started!</a></li>
                </ul>
            </div>
            <div class="life-text">
                <hr>
                <hr>
                <hr>
                <h3>Transform your <span>body</span> and your <span>life</span> <strong>now!</strong></h3>
                <hr>
                <hr>
                <hr>
            </div>
        </div>
    </div>
</div>
<div class="contact-main" id="contactform-box">
    <div class="container">
        <div class="get-start-button">
            <h2>GET STARTED NOW!</h2>
            <a href="#contactform-box">SIGN-UP BELOW!</a></div>
        <div class="free-text" id="freetext">
            <h3>*FREE 2-HR CONSULTATION FORM</h3>
        </div>
        <form method="post" action="#freetext" id="frmcontactus" name="frmcontactus">
            <div class="form-main">
                <?php if (count($valid_array)) { ?>
                    <div class="clear"></div>
                    <div class="erorr error_fc">
                        <?php

                        echo "" . show_error($valid_array) . ""; ?>
                    </div>
                <?php } ?>
                <input type="text" value="<?php echo $fname; ?>" maxlength="100" id="fname" name="fname"
                       placeholder="First Name*"/>
                <input type="text" value="<?php echo $lname; ?>" maxlength="100" id="lname" name="lname"
                       placeholder="Last Name*"/>
                <input type="text" value="<?php echo $email; ?>" maxlength="70" id="email" name="email"
                       placeholder="Email*"/>
                <input type="text" value="<?php echo $phone; ?>" maxlength="11" id="phone" name="phone"
                       placeholder="Phone No.*"/>
                <textarea id="comments" name="comments" placeholder="Message*"><?php echo $comments; ?></textarea>
                <input name="submit" value="submit" id="submit" type="hidden"/>
                <span>
        <input id="submit_local" class="searchbutton" type="submit" style="cursor:pointer;" value="Submit"
               name="submit_local"/>
        </span></div>
            <!--end contact_form_box-->
        </form>
        <div class="note">If you receive a 'Thank You' page after submitting <br/>
            your form, it was successfully sent!
        </div>
    </div>
</div>
<!--googleoff: all-->
<!--div class="pop-up">
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
        <a type="button" class="btn btn-primary" href="<?php //echo $config['site_url'];?>/free-consultation.php">Click Here</a>
      </div>
      </div>
    </div>
  </div>
</div>
<!--googleon: all-->
<script>
    /*
     $(window).load(function() {
     $('#introdu').delay(10000).modal('show');
     $(".close").click(function(){
     $("#intro").hide();
     });
     $("#introdu").click(function(){
     $("#intro").hide();
     });
     });*/
</script>
<!--CONTENT AREA END-->
<script type="text/javascript">
    //alert('hi');
    $('#home').addClass("current");

</script>
<?php include('includes/footer.php'); ?>
