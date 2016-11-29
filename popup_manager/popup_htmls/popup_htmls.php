<?php if (file_exists($_SERVER['DOCUMENT_ROOT'] . '/zblock/zbblock.php')) require($_SERVER['DOCUMENT_ROOT'] . '/zblock/zbblock.php'); ?><?php
//die("END");
//include("../../include/mainConnect.php");

//require_once($config['absolute_path'].'include/connect.inc.php');
//require_once($config['absolute_path'].'classes/main.php');	// calling meta title and keyword

$exploadParam = explode('|', $_GET['open_poup_for']);
$popupFor = trim($exploadParam[0]); // o'th element always will stand for popupFor
$pid = $exploadParam[1];

//echo $popupFor;
//die();
if ($popupFor == 'contect1') {
    ?>
    <div class="awarenesspopup_area">
        <div class="awarenesspopup_top">
            <div class="awarenesspopup_left">Big Picture</div>
            <div class="awarenesspopup_right"><a href="javascript:void(0);"
                                                 onclick="closeOpenedPopup('fadefriend,datafriend,bp')"
                                                 title="Close">X</a></div>
        </div>
        <!-- for the jquery scroll bar    -->
        <div id="content_1" class="content">
            <div class="awarenesspopup_bottom">
                <div class="foodassessment_main">
                    <div class="foodassessment_hed">Medical History</div>
                    <div class="foodassessment_content">
                        <img src="images/medical_history.jpg" class="assessment">
                        <div class="topic_content"><p>The information you report back to me enables me to be aware of
                                what medical issues may be impacting your weight and weight loss efforts. For instance,
                                if you are female and have had one or both of your ovaries removed, that would allow me
                                to see why your metabolism is lower than what I would expect it to be. Or, if you were
                                overweight as a child I would need to know that because it would make me aware of your
                                individualized physiology and what struggles I could expect you to see in the future.
                            </p>
                            <p>Additionally, since we will be putting together your eating plan it is imperative that I
                                know your entire medical history. If you had your gallbladder removed and need to
                                consume low fat meals (even if the fats are 'healthy' fats) to prevent complications, I
                                need to know that.
                            </p>
                            <p>Another example would be if you have a history of hypertension and / or
                                hypercholesterolemia, that's something I need to be aware because it will have an impact
                                on your dietary recommendations. Besides focusing on losing weight and permanently
                                maintaining that weight loss, which should automatically make you healthier overall, we
                                will work together to prevent sickness, disease and death. </p></div>
                    </div>
                </div>

                <div class="foodassessment_main2">
                    <div class="foodassessment_hed">Current Blood Work</div>
                    <div class="foodassessment_content">
                        <img src="images/curren_blood.jpg" class="assessment">
                        <div class="topic_content"><p>Recent blood work is analyzed to detect nutritional deficiencies,
                                possible disease states, areas that need extra focus and attention, and to facilitate
                                creating the best dietary prescription for you. For example, when it comes to your
                                overall health, and in particular, your capacity to be physically active, your red blood
                                cell, hemoglobin and iron levels are critical. </p>
                            <p>Being deficient in any of these categories (among other categories) will make it much
                                more difficult for you to burn a maximum number of calories when exercising, as well as
                                burning calories when you are not exercising. Additionally, when you have blood work
                                deficiencies, you generally are not feeling as strong as you could be which can make it
                                easier for you to get tired throughout the day which lends itself to making poorer food
                                choices. </p>
                            <p>Upon noticing any deficiencies, your diet will be devised to target these deficiencies
                                and get them to normal or higher levels. When your medical doctor orders blood tests for
                                you, if they see a deficiency they will likely tell you about the deficiency and make a
                                suggestion in which that suggestion may leave a lot to be interpreted. Generally, that
                                is all you'll get from them if for no other reason than they don't have the time to go
                                into depth with you about it. </p>
                            <p>I DO go into depth with you about it! For instance, we discuss how it may have happened,
                                what you need to do to prevent it from getting worse, how to make it better including
                                exactly which food sources we need to include in your diet, how much, how often, with or
                                without what other food sources, and what your optimal blood levels should be.</p>
                            <p>Additionally, many doctors do NOT do complete blood tests. Often they leave out key blood
                                tests which upon noticing I may recommend that they order those blood tests so that we
                                can see the entire picture with your current health and blood status. Getting your blood
                                work to healthy levels can have a big impact on your ability to reach your dream
                                weight!</p></div>
                    </div>
                </div>

                <div class="foodassessment_main2">
                    <div class="foodassessment_hed">Roadblock Analysis & Needs Assessment</div>
                    <div class="foodassessment_content">
                        <img src="images/needs_assessment.jpg" class="assessment">
                        <div class="topic_content"><p>Part of seeing the 'Big Picture' with your weight management
                                involves determining what your current roadblocks and obstacles are that are preventing
                                you from attaining a healthy weight. You can have roadblocks that are getting in your
                                way of exercising as well as roadblocks that are inhibiting your ability to consume a
                                healthier diet.</p>
                            <p>It's very important to know what the problem is, but it is critical to know why the
                                problem is there. This assessment also helps to facilitate determining what's at the
                                core of your challenges. Determining what these roadblocks and obstacles are, and what's
                                at the core of them is absolutely imperative, just as devising a plan to overcome them
                                is. </p>
                            <p>You have your own personal needs – things that are essential for you to be successful
                                with your weight loss goal. Your needs are in part based upon your personal
                                circumstances, the challenging areas you are dealing with, your medical and food history
                                and more.</p>
                            <p>Without knowing what your true needs are, it is very difficult to create a solution to
                                the problem that will be effective long–term. Together, we'll determine what you'll need
                                to overcome your roadblocks and obstacles so that you can start making significant
                                progress with your weight loss goal and soon reach your dream weight!</p></div>
                    </div>
                </div>

                <div class="foodassessment_main2">
                    <div class="foodassessment_hed">Goal Orientation</div>
                    <div class="foodassessment_content">
                        <img src="images/goal_orientation.jpg" class="assessment">
                        <div class="topic_content"><p>Goal orientation focuses on the initiation of determining what
                                your long-term goals are as well as what short-term goals you will need in order to be
                                successful with accomplishing your long–term goals. It is imperative to set goals at the
                                very start of your program, however, goals can be modified at any time. </p>
                            <p>For example, if you need more time to achieve a short-term goal, you can modify the
                                timeline for the accomplishment of that goal. Without making modifications at times,
                                many people will fall short of accomplishing their goals and therefore abandon their
                                goals altogether and find themselves starting all over again later on.</p>
                            <p>However, goals are created to give you drive and focus! Having a timeline for a goal and
                                doing everything you can to achieve that goal within that timeline is really critical.
                                Without having a deadline to meet, goals do not have the impact that they are meant to
                                have. </p>
                            <p>When you are doing your best to meet a goal, but unforeseen circumstances arise or you
                                realize you made your goal too profound for that short period of time, it may be best to
                                modify your goal. In addition to being time sensitive, goals should be specific,
                                measurable, attainable, and realistic.</p></div>
                    </div>
                </div>

                <!--<div class="question2">
                    Questions? <span><a href="contactus.php">Contact Anthony</a></span> or email
                    <span>
                    <a href="mailto:Anthony@WeightLossHappens.com">Anthony@WeightLossHappens.com</a></span>
                </div>-->

            </div>


        </div>
        <!-- end for the jquery scroll bar    -->
    </div>
    <!--poppup 1 end-->
    <!-- for the jquery scroll bar    -->

    <!-- for the jquery scroll bar    -->
    <?php
} ?>


<!--poppup 2 start-->
<?php if ($popupFor == 'contect2') { ?>

    <div class="awarenesspopup_area">
        <div class="awarenesspopup_top">
            <div class="awarenesspopup_left">Awareness</div>
            <div class="awarenesspopup_right"><a href="javascript:void(0);"
                                                 onclick="closeOpenedPopup('fadefriend,datafriend,aw')"
                                                 title="Close">X</a></div>
        </div>
        <div id="content_1" class="content">
            <div class="awarenesspopup_bottom">
                <div class="foodassessment_main">
                    <div class="foodassessment_hed">Food Assessment</div>
                    <div class="foodassessment_content">
                        <img src="images/assessment.jpg" class="assessment">
                        <div class="topic_content"><p>The food assessment helps us to see what the big picture is with
                                your eating patterns and habits. It focuses on what you have been eating, what you are
                                currently eating, and to some extent, what the underlying causes of your eating patterns
                                and habits are. </p>
                            <p>It also allows us to see if you have any major nutritional deficiencies. The food
                                assessment generally yields a tremendous amount of important information and is a major
                                key at the beginning of your program.</p></div>
                    </div>
                </div>

                <div class="foodassessment_main2">
                    <div class="foodassessment_hed">Food Beliefs</div>
                    <div class="foodassessment_content">
                        <img src="images/food_recognition.jpg" class="assessment">
                        <div class="topic_content"><p>This involves looking at how you view certain foods and key
                                nutrients, and then educating you as to whether or not you hold accurate beliefs
                                regarding them, and why. This is important because inaccurate food and nutrient beliefs
                                are likely affecting your food choices which may be hindering your ability to be
                                successful with your daily, short and long–term goals. </p>

                            <p>Being unsuccessful with your daily & short-term goals with have a tremendous negative
                                impact on your ultimate long-term weight loss goal. Your beliefs will have a direct
                                impact on your actions regarding food intake.</p></div>
                    </div>
                </div>

                <div class="foodassessment_main2">
                    <div class="foodassessment_hed">Food Recognition</div>
                    <div class="foodassessment_content">
                        <img src="images/food_cognition_second.jpg" class="assessment">
                        <div class="topic_content"><p>Food recognition ultimately involves recognizing the overall
                                reasons why you are eating the way you are and why your habits and patterns exist. This
                                then leads to determining what needs to be changed to eradicate these behaviors.</p>

                            <p>For instance, if you were going long periods of time without food, that would help me to
                                recognize why you are binging on sugary and fatty snacks, and at least partially, what
                                we need to do about it. Food recognition is the ultimate key when it comes to being more
                                aware as to why we are eating they way we are.</p></div>
                    </div>
                </div>
                <!--<div class="foodassessment_main2">
                    <div class="foodassessment_hed">Food Cognition</div>
                    <div class="foodassessment_content">
                        <img src="images/food_cognition_second.jpg" class="assessment">
                        <div class="topic_content"><p>Looking at the way you look at foods and certain key nutrients and
    educating you as to whether or not you hold accurate beliefs regarding them.</p>
    <p>This is important because your false food and nutrient beliefs are likely affecting your food choices, which may be hindering your ability to be successful with your daily, short and long&ndash;term goals.</p></div>
                    </div>
                </div>-->

                <!-- <div class="question2">
                     Questions? <span><a href="contactus.php">Contact Anthony</a></span> or email
                     <span>
                     <a href="mailto:Anthony@WeightLossHappens.com">Anthony@WeightLossHappens.com</a></span>
                 </div>-->

            </div>


        </div>
    </div>


    <?php
} ?>
<!--poppup 2 end-->


<!--poppup 3 start-->
<?php if ($popupFor == 'contect3') { ?>
    <div class="awarenesspopup_area">
        <div class="awarenesspopup_top">
            <div class="awarenesspopup_left">Behavior Modification</div>
            <div class="awarenesspopup_right"><a href="javascript:void(0);"
                                                 onclick="closeOpenedPopup('fadefriend,datafriend,bm')"
                                                 title="Close">X</a></div>
        </div>


        <div id="content_1" class="content">
            <div class="awarenesspopup_bottom">
                <div class="foodassessment_main">
                    <div class="foodassessment_hed">Behavior Identification &amp; Habits</div>
                    <div class="foodassessment_content">
                        <img src="images/behavior_identification.jpg" class="assessment">
                        <div class="topic_content"><p>Now that we have the vital information from the food awareness
                                section and know what your negative eating patterns and habits are, and why they exist,
                                we'll also identify if you actually want to change those behaviors and habits, and why
                                or why not. Additionally, we'll identify how far out of your comfort zone you are
                                willing to go and then create a plan to modify your current eating patterns and habits
                                so that you can create new, empowering eating patterns and habits. </p>

                            <p>Together, we'll determine how to deal with them most effectively, and ultimately, how to
                                go about making the needed changes. Simply, we are going to utilize behavioral
                                psychology techniques to facilitate the transitioning of negative behaviors to positive
                                ones.</p></div>
                    </div>
                </div>

                <div class="foodassessment_main2">
                    <div class="foodassessment_hed">Motivation</div>
                    <div class="foodassessment_content">
                        <img src="images/motivation_second.jpg" class="assessment">
                        <div class="topic_content"><p>To begin any journey you must be motivated to get started. To
                                finish any journey, you must stay motivated along the way. And when you hit unforeseen
                                roadblocks and obstacles, your motivation needs to be there in full force to support you
                                or else you may give up and lose all the gains that you have made thus far. </p>

                            <p>What drives one person doesn't necessarily drive another one, which is why, together,
                                we'll create your 'personalized' motivational blueprint that will act as your driving
                                force to keep you on cue with all of your goals. Motivation is power! Let it drive you
                                to your dream weight!
                            </p></div>
                    </div>
                </div>

                <div class="foodassessment_main2">
                    <div class="foodassessment_hed">Powerful Thinking</div>
                    <div class="foodassessment_content">
                        <img src="images/cognitive_restructuring.jpg" class="assessment">
                        <div class="topic_content"><p>Did you know that your thoughts have a tremendous impact on your
                                feelings and that your feelings affect your actions? Since your thoughts have such a
                                strong impact on your behaviors, we'll identify how you speak to yourself and whether or
                                not that is positively or negatively impacting your weight loss efforts. </p>

                            <p>Learning to look at things from a positive perspective as well as looking at change as an
                                opportunity will be two of our goals that will facilitate you in achieving powerful
                                thinking which will greatly facilitate you on your weight loss journey. </p></div>
                    </div>
                </div>
                <!--<div class="foodassessment_main2">
                    <div class="foodassessment_hed">Cognitive Restructuring</div>
                    <div class="foodassessment_content">
                        <img src="images/cognitive_restructuring.jpg" class="assessment">
                        <p>Since your thoughts have a tremendous impact on your behaviors, we will identify how you speak to yourself and whether or not that is positively or negatively impacting your weight loss efforts.</p>
                        <p>Learning to look at things from a different perspective, and looking at change as an opportunity will be two of our goals.</p>
                        <p>Additionally, we are going to eliminate false beliefs about foods and key nutrients, as well as utilize
    behavioral psychology techniques to facilitate the transitioning of a negative behavior and habit to a positive one. </p>
                    </div>
                </div>-->

                <!--<div class="question2">
                    Questions? <span><a href="contactus.php">Contact Anthony</a></span> or email
                    <span>
                    <a href="mailto:Anthony@WeightLossHappens.com">Anthony@WeightLossHappens.com</a></span>
                </div>-->

            </div>
        </div>


    </div>
    <?php
} ?>
<!--poppup 3 end-->


<!--poppup 4 start-->
<?php if ($popupFor == 'contect4') { ?>
    <div class="awarenesspopup_area">
        <div class="awarenesspopup_top">
            <div class="awarenesspopup_left">Stress</div>
            <div class="awarenesspopup_right"><a href="javascript:void(0);"
                                                 onclick="closeOpenedPopup('fadefriend,datafriend,st')"
                                                 title="Close">X</a></div>
        </div>

        <div id="content_1" class="content">
            <div class="awarenesspopup_bottom">
                <div class="foodassessment_main">
                    <div class="foodassessment_hed">Stressors</div>
                    <div class="foodassessment_content">
                        <img src="images/stressors_seccond.jpg" class="assessment">
                        <div class="topic_content"><p>Stress is often a prime culprit with weight gain and the struggle
                                to reach a healthy body weight. This is because of its impact on emotional eating,
                                appetite, the amount you eat, when you eat, and its connection to emotional eating. </p>
                            <p>The exhaustion that stress can impart can lead to decreased quality sleep, less energy,
                                less calories burned during a workout, skipped meals, excessive snacking, and poor food
                                choices like foods high in simple sugars and fat.</p>
                            <p>If stress is having an impact on your level of happiness and contentment, it is most
                                likely having an impact on your dietary habits. Stress is physiologically dangerous.
                                Among other effects, it weakens your immune system, can lead to permanent short–term
                                memory loss, and promotes that dreaded belly fat!
                            </p></div>
                    </div>

                </div>
            </div>

            <div class="foodassessment_main2">
                <div class="foodassessment_hed">Actions</div>
                <div class="foodassessment_content">
                    <img src="images/actions_second.jpg" class="assessment">
                    <div class="topic_content"><p>Together, we will determine what the true causes of your stress are
                            and what we must do, from a food, activity and behavioral standpoint, to eliminate and/ or
                            cope with these stressors so that your long-term weight loss goal can still be achieved.
                            There are many different things that you can do in regards to your stress including
                            utilizing many cognitive and behavioral techniques to prevent it from occurring, or manage
                            it should your stress start to rise. </p>

                        <p>Obviously, exercise is a great way to keep a lid on stress in many instances, but it does not
                            target its root cause. So we will counter stress from 3 perspectives: preventing it,
                            controlling it and eliminating it when possible. </p></div>
                </div>
            </div>

            <div class="foodassessment_main2">
                <div class="foodassessment_hed">Goals</div>
                <div class="foodassessment_content">
                    <img src="images/goals_second.jpg" class="assessment">
                    <div class="topic_content"><p>If stress is having a large impact on your weight then one of our
                            first priorities is to make preventing, managing and overcoming your stress immediate goals.
                            Too much stress can be a tremendous roadblock to your weight loss success. </p>

                        <p>Creating daily and short-term goals that target stress will be a great start to removing this
                            roadblock! Part of your long-term plan and 'recipe for success' will involve these
                            short-term goals that target your stress so that you have the best chance for success with
                            achieving your long-term goal! </p></div>
                </div>
            </div>

            <!--<div class="question2">
                Questions? <span><a href="contactus.php">Contact Anthony</a></span> or email
                <span>
                <a href="mailto:Anthony@WeightLossHappens.com">Anthony@WeightLossHappens.com</a></span>
            </div>-->


        </div>

    </div>

    <?php
} ?>
<!--poppup 4 end-->


<!--poppup 5 start-->
<?php if ($popupFor == 'contect5') { ?>
    <div class="awarenesspopup_area">
        <div class="awarenesspopup_top">
            <div class="awarenesspopup_left">Exercise Nutrition Plan:</div>
            <div class="awarenesspopup_right"><a href="javascript:void(0);"
                                                 onclick="closeOpenedPopup('fadefriend,datafriend,ep')"
                                                 title="Close">X</a></div>
        </div>
        <div id="content_1" class="content">
        <div class="awarenesspopup_bottom">
            <div class="foodassessment_main" style="padding-top:15px;">
                <div class="foodassessment_hed">Macro-Nutrient &amp; Nutrient Timing</div>
                <div class="foodassessment_content">
                    <img src="images/macro-nutrient.jpg" class="assessment">
                    <div class="topic_content"><p>To get the most out of your exercise plan, you need to utilize the
                            correct nutrients, in the correct amounts, and at the correct time! This involves
                            determining how much carbohydrate, protein, and fat to have before and after your workouts,
                            as well as for your entire day. </p>

                        <p>Utilizing proper sports nutrition will facilitate you in having more intense workouts,
                            recovering from your workouts more quickly, decreasing your chances of injury, and feeling
                            better after your workout. And that's in addition to burning a maximum number of calories
                            during and after your workout.
                        </p></div>
                </div>
            </div>

            <!--<div class="foodassessment_main2">
                <div class="foodassessment_hed">Exercise RX</div>
                <div class="foodassessment_content">
                    <img src="images/exercise.png" class="assessment">
                    <p>You want to know what exercises will be best for you given where you are starting from, what your goals are, the number of days per week you can workout, and the amount of time per workout you have available to spend.</p>

                    <p>You want an exercise plan that puts cardio, weights, and stretching all together in a way that leads to the maximum number of calories burned. And you want to know how to stay motivated with your workouts and what you can do to make them as enjoyable as possible.</p>
                </div>
            </div>-->

            <!--<div class="question2">
                Questions? <span><a href="contactus.php">Contact Anthony</a></span> or email
                <span>
                <a href="mailto:Anthony@WeightLossHappens.com">Anthony@WeightLossHappens.com</a></span>
            </div>-->

        </div>
        </div>
    </div>
    <?php
} ?>
<!--poppup 5 end-->


<!--poppup 6 start-->
<?php if ($popupFor == 'contect6') { ?>
    <div class="awarenesspopup_area">
        <div class="awarenesspopup_top">
            <div class="awarenesspopup_left">Success Plan</div>
            <div class="awarenesspopup_right"><a href="javascript:void(0);"
                                                 onclick="closeOpenedPopup('fadefriend,datafriend,sp')"
                                                 title="Close">X</a></div>
        </div>
        <div id="content_1" class="content">
        <div class="awarenesspopup_bottom">
            <div class="foodassessment_main" style="padding-top:15px;">
                <div class="foodassessment_hed">Goals &amp; Timelines</div>
                <div class="foodassessment_content">
                    <img src="images/goals_timelines.jpg" class="assessment">
                    <div class="topic_content"><p>Without having goals and a success plan, many people aimlessly wander
                            about wanting to reach their dream weight, but year after year they never get there. To
                            start off your success plan, we identify what we've decided is your long–term goal and the
                            date by which you want to accomplish it by. </p>

                        <p>Next, we decide what the short–term goals are that you'll need in order to be successful with
                            achieving your long-term goal. We'll also create daily-goals that help you to stay focused
                            each and every day! </p></div>
                </div>
            </div>

            <div class="foodassessment_main2">
                <div class="foodassessment_hed"> Recipe-For-Success</div>
                <div class="foodassessment_content">
                    <img src="images/recipes_second.jpg" class="assessment">
                    <div class="topic_content"><p>Based on all of the information we've gathered thus far, we will put
                            together a 'Recipe For Success' so that you can make your dream weight a reality! This will
                            take into account what your circumstances and needs are, your likes, dislikes, what
                            motivates you, and the specific actions you'll need to take to accomplish your goals!</p>

                        <p>Your 'recipe-for-success' can be modified at any time. When you have a significant amount of
                            weight to lose, your weight loss journey is definitely a process. It does not happen
                            overnight and your recipe-for-success will likely change over time depending upon how
                            successful you have been and what your current circumstances are. Either way, there are many
                            important ingredients in your own personalized recipe!
                        </p></div>
                </div>
            </div>


            <div class="foodassessment_main2">
                <div class="foodassessment_hed">Meal Plans</div>
                <div class="foodassessment_content">
                    <img src="images/meal_plans.jpg" class="assessment">
                    <div class="topic_content"><p>Additionally, we will create sample food lists, sample meals, and
                            sample meal plans based on your food preferences. Your sample meal plans will have menus
                            that keep you full throughout the day and still losing weight. They will only include foods
                            that you enjoy and will be based upon your daily needs, goals and medical conditions. </p>
                    </div>
                </div>
            </div>

            <!-- <div class="question2">
                 Questions? <span><a href="contactus.php">Contact Anthony</a></span> or email
                 <span>
                 <a href="mailto:Anthony@WeightLossHappens.com">Anthony@WeightLossHappens.com</a></span>
             </div>-->

        </div>
            </div>
    </div>
    <?php
} ?>
<!--poppup 6 end-->


<!--poppup 7 start-->
<?php if ($popupFor == 'contect7') { ?>
    <div class="awarenesspopup_area">
        <div class="awarenesspopup_top">
            <div class="awarenesspopup_left">Follow&ndash;Up & Accountability</div>
            <div class="awarenesspopup_right"><a href="javascript:void(0);"
                                                 onclick="closeOpenedPopup('fadefriend,datafriend,fa')"
                                                 title="Close">X</a></div>
        </div>
        <div id="content_1" class="content">
            <div class="awarenesspopup_bottom">
                <div class="foodassessment_main">
                    <div class="foodassessment_hed">Obstacles</div>
                    <div class="foodassessment_content">
                        <img src="images/obstacles.jpg" class="assessment">
                        <div class="topic_content"><p>Now you've started to put your 'Success Plan' into motion!
                                Obstacles and unforeseen circumstances are inevitable and we will tackle them together
                                as they arise. One of the main reasons why individuals don't reach their weight loss
                                goal when working without the help of a professional is that they let their new
                                obstacles and circumstances bring them to a screeching halt. </p>

                            <p>Maintaining motivation throughout your weight loss journey is imperative. Working with a
                                professional whereby obstacles are overcome and don't act as roadblocks, at least not
                                for very long, allow you to continue to be successful which is key for maintaining
                                motivation.</p>
                            <p>Additionally, maintaining success is further enhanced by having someone hold you
                                accountable. I will hold you accountable! Just knowing that someone is holding you
                                accountable goes a long way – further than you might have imagined. So accountability is
                                powerful! </p></div>
                    </div>
                </div>

                <div class="foodassessment_main2">
                    <div class="foodassessment_hed"> Motivation</div>
                    <div class="foodassessment_content">
                        <img src="images/motivation_third.jpg" class="assessment">
                        <div class="topic_content"><p>Working together for 6 full months will act as a driving force to
                                keep you motivated for many reasons. Everyone is motivated by similar things as well as
                                by things solely unique to them. We will determine what motivates YOU and use that to
                                keep you going strong! </p>

                            <p>We will be utilizing goal-setting to further enhance and maintain your motivation.
                                Together we'll create daily, short & long-term goals and design them so that you'll
                                achieve each one, and each one will enable you to accomplish the next one, and
                                ultimately, your dream weight long-term goal! Having expert support and someone holding
                                you accountable will further enhance motivation tremendously. </p>

                            <p>Simply, being held accountable puts pressure on you to follow through, which often times
                                makes you think twice about acting upon the negative or detrimental behavior.</p>
                            <p>Additionally, knowing you have someone to answer to motivates and encourages you to do
                                what's in your best interests.</p></div>
                    </div>
                </div>


                <div class="foodassessment_main2">
                    <div class="foodassessment_hed">Coach 24/7</div>
                    <div class="foodassessment_content">
                        <img src="images/coach.jpg" class="assessment">
                        <div class="topic_content"><p>By having a coach available to you 24/7, you'll always have a
                                resource available that you'll need to be successful. When trying to decide on what to
                                eat, or how much, or how to go about doing something we discussed in one of your
                                sessions, you may find it quite useful to contact me via email for a much needed
                                question at just about any time. </p>

                            <p>Again, this helps to keep you successful and motivated, knowing all the while that you
                                are not alone - you have a partner that is here to assist you! And that's motivating!
                                Short answer questions are perfect email questions while larger topics will be discussed
                                during your sessions. Everyone loves having a coach they can reach out to 24/7!</p>
                        </div>
                    </div>
                </div>

                <!--<div class="question2">
                    Questions? <span><a href="contactus.php">Contact Anthony</a></span> or email
                    <span>
                    <a href="mailto:Anthony@WeightLossHappens.com">Anthony@WeightLossHappens.com</a></span>
                </div>-->

            </div>
        </div>
    </div>
    <?php
} ?>
<!--poppup 7 end-->


<!--poppup 8 start-->
<?php if ($popupFor == 'contect8') { ?>
    <div class="awarenesspopup_area">
        <div class="awarenesspopup_top">

            <div class="awarenesspopup_left">3 Additional Months</div>
            <div class="awarenesspopup_right"><a href="javascript:void(0);"
                                                 onclick="closeOpenedPopup('fadefriend,datafriend,sus')"
                                                 title="Close">X</a></div>
        </div>
        <div id="content_1" class="content">
            <div class="awarenesspopup_bottom">
                <div class="foodassessment_main">
                    <div class="minute_session">30 minute session per week</div>
                    <div class="foodassessment_hed">Maintenance</div>
                    <div class="foodassessment_content">
                        <img src="images/maintenance_four.jpg" class="assessment">
                        <div class="topic_content"><p>By the end of the 1st 3-months you will be well on your way
                                towards your weight loss goal!</p>
                            <p>However, many people lose weight, but then their motivation decreases and they start to
                                regress with their new habits and behaviors, and eventually, their weight loss. You must
                                remember that the journey is not nearly over at the 3-month mark! You must keep going in
                                order to be successful. </p>
                            <p>And we will keep it going with weekly 30 minute sessions whereby you'll continue to
                                receive support, accountability, motivation, meals, goal-setting, and more! There's no
                                point in making progress initially just to let it all slip away. At this point you have
                                to maintain your past success as well as continue to have new successes.</p>

                            <p>One of the biggest mistakes I see people make is that they get started on the right path,
                                start making progress, and then think that the rest will come without continuously
                                taking an intense approach. Just as you utilized expert support and targeted many
                                different areas in your 1st 3-months, you must continue to do the same if you truly want
                                to reach your dream weight goal! </p></div>
                    </div>
                </div>

                <div class="foodassessment_main2">
                    <div class="foodassessment_hed"> Guidance &amp; Support</div>
                    <div class="foodassessment_content">
                        <img src="images/guidance_support.jpg" class="assessment">
                        <div class="topic_content"><p>Without maintaining progress and newly created powerful habits,
                                successful follow-through doesn't occur. Continued guidance and support play a huge role
                                with sustainability, as does enjoyment with your food and activity plan. Having someone
                                who really supports your efforts and is there for you 24/7, is motivating and
                                empowering! People tend to put forth their best effort when they know someone else is
                                counting on them to be successful. Continued guidance & support will be key!</p></div>
                    </div>
                </div>


                <div class="foodassessment_main2">
                    <div class="foodassessment_hed">Strategies</div>
                    <div class="foodassessment_content">
                        <img src="images/strategies.jpg" class="assessment">
                        <div class="topic_content"><p>Each week we'll discuss successes and obstacles from the previous
                                week and create strategies that will empower and facilitate your success for the
                                upcoming week. With your help and focused effort, I'll see to it that we'll create a
                                strategy to overcome any obstacle or roadblock that appears so that you can finish what
                                you started and continue down your path towards you dream weight goal! </p>

                            <p>We'll look back and see what has worked for you in the past for similar obstacles and let
                                that guide us. I'll also make sure you are aware of resources available to you so that
                                you can stay feeling empowered. Just remember........Weight Loss Happens, with the right
                                strategy! </p></div>
                    </div>
                </div>

                <!--<div class="question2">
                    Questions? <span><a href="contactus.php">Contact Anthony</a></span> or email
                    <span>
                    <a href="mailto:Anthony@WeightLossHappens.com">Anthony@WeightLossHappens.com</a></span>
                </div>-->

            </div>
        </div>


    </div>
    <?php
} ?>
<!--poppup 8 end-->


<!-------------------------Weight Loss Articles  page html start----------------------------------------->
<!--poppup 9 start-->
<?php if ($popupFor == 'contect9') { ?>
    <div class="popup_weightarticle_area">
        <div class="popup_weightarticle_top">
            <div class="popup_weightarticle_left">Weight Loss Articles</div>
            <div class="popup_weightarticle_right">
                <a href="javascript:void(0);" onclick="closeOpenedPopup('fadefriend,datafriend,wla1')"
                   title="Close">X</a>
            </div>
        </div>
        <div id="content_1" class="content">
            <div class="popup_weightarticle_bottom">
                <div class="popup_weightarticle_main">
                    <div class="popup_weightarticle_hed">4 Steps to permanent weight loss</div>

                    <div class="popup_weightarticle_contents">
                        <img src="images/permanent_weight_loss2.png" class="popup_weightarticle1" alt="">
                        <h1>Step #1: Realize you are different!</h1>
                        <p>When it comes to being successful with your weight management goals, the first thing that you
                            will need to do is realize that what YOU need to do to be successful is going to be somewhat
                            different than what the person next to you needs to do.</p>
                        <p>Yes, there are identical things that both of you will need to do such as consume less
                            calories than what your body is using or burn more
                            calories through physical activity. However, because you are different people, you're
                            individualized plans will be quite different as well!</p>
                        <h1>Step #2: Determine what's in your way?</h1>


                        <p>Now that you know that you need to focus on creating a plan that is unique and specific to
                            your individual needs and circumstances, the second thing you need to do is to start
                            learning a lot about yourself. For instance, your second task will be to determine what your
                            obstacles or roadblocks are with achieving or maintaining your desired weight.</p>
                        <p>You need to determine what it is that is preventing you from being either successful, or,
                            more successful than you
                            currently are. In other words, what is it that is getting in your way of success?</p>
                        <p>Most people are aware of what some of their obstacles and roadblocks are, but not all of
                            them, especially their most
                            detrimental ones. This is why you have to look more closely to develop a greater awareness
                            about yourself.</p>
                        <h2>Step #3 &amp; #4: Determine why and how</h2>
                        <p>Your third task is really critical and most people overlook it. The third thing you need to
                            do is determine why your obstacles are there. In order to successfully accomplish the fourth
                            thing you need to do, which is to determine how to overcome your obstacles, you really need
                            to look closely at why your obstacles exist in the first place.</p>
                        <p>If you create a 'solution' that seems to overcome an obstacle, but it doesn't really address
                            the real reason why that obstacle is there, you may find that you have only created a &quot;temporary&quot;
                            solution. In time, the obstacle will likely
                            reappear and you'll find yourself trying to create new ways to overcome that same
                            obstacle.</p>
                        <h2>"Why" Your obstacles are There</h2>
                        <p>Once you determine why your obstacles are truly there, you are then in a much better position
                            to come up with permanent solutions for them. However, determining why they are really there
                            can be difficult for people. If we could all individually determine why we do the things we
                            do, none of us would have the need for a therapist!</p>
                        <p>So whether you personally determine why your obstacles are there or you utilize the help of a
                            professional, what matters is that you figure this out so that you can start making real
                            progress toward your weight loss goals. As much as this step is not easy to do, it is very
                            important to do it!</p>
                        <h2>Example of the importance of &quot;why&quot;</h2>
                        <p>As an example of the importance of determining why, I had a client whom would eat 2-3x's more
                            food for dinner than what his body really wanted or needed. He really didn't know why he ate
                            so much at dinner time, or at least, he never admitted to himself the real reasons for his
                            dinner habits.</p>
                        <p>When I first started working with him, I asked him why he thought he did this. He mentioned
                            to me that he didn't like to throw away food from his or his kid's plates, as well as a few
                            other reasons. And so at first we talked about what he needed to do so that he wouldn't
                            consume his kid's leftovers.</p>
                        <p>We came up with a few ideas and he tried them, but we did not see much improvement with him
                            decreasing his food consumption at dinner time. The reason for this was that his real
                            problem with consuming too much food at dinner was not because he did not want to see food
                            thrown out (primarily), but because he was depending on dinner to give him the pleasure that
                            he was not obtaining from the rest of his day.</p>
                        <p>In other words, dinner was where his happiness for the day existed and he really depended on
                            it on a regular basis. His lack of stimulation and pleasure throughout the day was his real
                            obstacle. And once we addressed his real obstacle, we started to make progress with his
                            weight loss goals right away!</p>
                        <h2>Bottom line</h2>
                        <p>The bottom line is to realize that what you need to do to be successful is going to be
                            somewhat different than what others need to do to be successful. And also that you'll need
                            to determine what your obstacles are, why they are there, and how to overcome them. Then and
                            only then will you see things for what they truly are and be on your way to reaching your
                            weight loss goals!</p>
                    </div>
                </div>
            </div>
        </div>

    </div>
    <?php
} ?>
<!--poppup 9 end-->


<!--poppup 10 start-->
<?php if ($popupFor == 'contect10') { ?>
    <div class="popup_weightarticle_area">
        <div class="popup_weightarticle_top">
            <div class="popup_weightarticle_left">Weight Loss Articles</div>
            <div class="popup_weightarticle_right">
                <a href="javascript:void(0);" onclick="closeOpenedPopup('fadefriend,datafriend,wla2')"
                   title="Close">X</a>
            </div>
        </div>
        <div id="content_1" class="content">
            <div class="popup_weightarticle_bottom">
                <div class="popup_weightarticle_main">
                    <div class="popup_weightarticle_hed">LACK OF PROFESSIONAL GUIDANCE: 10 CONSEQUENCES</div>
                    <div class="popup_weightarticle_content">

                        <div class="popup_weightarticle_contents">
                            <img src="images/doctor.png" class="popup_weightarticle1" alt="fat_grams2">
                            <h2>LOSS OF MOTIVATION MUCH MORE LIKELY:</h2>
                            <p>One of the top motivators that keeps individuals continuing their weight loss journey is
                                SUCCESS! Simply, working with a professional greatly increases your chances of success
                                with your weight loss and that initial success will be critical for maintaining
                                motivation as you move forward down your weight loss path. </p>
                            <p>This happens for numerous reasons such as when you are working with someone you are aware
                                that the individual you are working with is counting on you to be successful. Often in a
                                working relationship your desire is to be successful first and foremost for yourself,
                                but also, you don't want to let the person assisting you down and that can be very
                                motivating for you especially at times when you might otherwise falter.</p>

                            <p>Similarly, having this other person hold you accountable keeps you on your toes and you
                                are more inclined to do what's in you best interests, and with this, you attain more
                                success which fuels your motivation very positively!</p>

                            <h2>BURNING LESS CALORIES DUE TO DEFICIENT BLOOD WORK: </h2>
                            <p>Not being aware of what your blood work is showing and not knowing exactly what you need
                                to do for it can cost you in terms of weight loss. For instance, when your red blood
                                cell count, hemoglobin, and iron levels are low, that can have a large negative impact
                                on your ability to burn calories.</p>
                            <p>Even though you may have had these tests run previously, they may not have been tested in
                                some time. Also, your doctor rarely has the time to go over your blood work in depth
                                with you such as discussing how and why your blood work got low, and exactly what you
                                need to do to get those levels back to normal and higher. </p>
                            <p>One of the 1<sup>st</sup> things I do with clients is discuss recent or brand new blood
                                work. We determine what must be done to get your deficiencies corrected and then we
                                apply it to your weight loss plan. </p>

                            <h2>SLOWER GAINS DUE TO INACCURATE NUTRITION & WEIGHT LOSS INFORMATION: </h2>
                            <p>When you don't have accurate nutrition and weight loss information by which to plan your
                                weight loss journey, you end up making slower gains even though you think you are doing
                                everything right. Sooner or later you start to struggle to lose any weight. Slower gains
                                are common when you have inaccurate information and flawed strategies. </p>
                            <p>Consequently, many individuals find themselves starting over numerous times since they
                                don't have much success due to basing their weight management plan on misinformation and
                                often times poor planning as well.</p>

                            <h2>QUITTING DUE TO A LACK OF FOLLOW-THRU:</h2>
                            <p>Many individuals have been learning about weight loss for a long time, but ultimately
                                don't come close to reaching their dream weight due to a lack of follow-through, plain
                                and simple. This could be due to many reasons such as a lack of knowledge, fear, lack of
                                initial success, or other reasons. Whatever the reason, follow-through is absolutely
                                necessary for success! Working with a professional will almost always help you to
                                follow-through.
                            </p>
                            <h2>WEIGHT GAIN, NOT WEIGHT LOSS: </h2>
                            <p>Weight gain, not weight loss, due to unintentional yo-yo 'dieting' often occurs. Many
                                individuals start their weight loss plan, but then for one reason or another, stop
                                shortly thereafter. Unfortunately, the end result is a higher body fat percentage and a
                                slower metabolism. This is the result of losing muscle and gaining fat mass which
                                happens when you decrease your caloric intake for a while and then abruptly go back to
                                eating the same number of calories that you were eating before you started your weight
                                loss plan. </p>

                            <p>When you make that abrupt change, your metabolism is lower and not expecting to get as
                                many calories as you used to feed it just a short while ago. So you end up
                                over-consuming calories during that time. It doesn't seem like you are over-consuming
                                calories because that is the same number of calories you used to consume.</p>

                            <h2> SLOWER GAINS DUE TO POOR GOAL-SETTING:</h2>
                            <p>Another top key when it comes to motivation is goal-setting. It is very useful to make
                                daily, short & long-term goals and to make them in a way that will benefit you the most.
                                Many times individuals' goal-setting was not created ideally and it doesn't motivate
                                them the way that it should, if at all. Goal-setting that really motivates helps to keep
                                you focused and driven especially during difficult times! Effective goal-setting is
                                critical!</p>

                            <h2>TREMENDOUS FRUSTRATION: </h2>
                            <p>Not having someone you trust to turn to for advice when you hit obstacles or are unsure
                                about which is the best way to proceed with something leads to, among other things,
                                tremendous frustration. And then you guess as to what to do and likely end up being even
                                more frustrated. This is one of the benefits of working with a trusted professional –
                                you always have someone to turn to for expert advice! </p>

                            <h2>SLOWER GAINS DUE TO THE BELIEF THAT YOU WILL NOT BE SUCCESSFUL: </h2>
                            <p>Many individuals trying to lose weight and maintain that weight loss have tried to do so
                                in the past and have failed. Because of that many have adopted the belief that, as much
                                as they truly want to lose weight, they won't be successful with losing weight.
                                Ultimately, your limiting beliefs will affect your actions which will almost definitely
                                have a negative impact on your food choices and how you forward with your weight loss
                                plan. </p>

                            <h2>SLOWER PROGRESS DUE TO DEFICIENT WEIGHT LOSS PRESCRIPTION:</h2>
                            <p>It's difficult for you to put together your best dietary “prescription” for your weight
                                loss journey without taking into account your past and current medical conditions, among
                                other things, and exactly how they factor in. For instance, if you have had your
                                gallbladder removed you would need to know that you need to consume low fat meals for
                                the rest of your life or else you will have chronic diarrhea, everyday. </p>

                            <p>If you have diabetes you would need to know the most successful ways to plan your meals
                                and snacks which would involve knowing the best ways to control and overcome your
                                diabetes. Without nutrition and medical training you might be unaware of how to do this
                                which would slow your progress down.</p>

                            <h2>LESS CALORIES BURNED FROM A WORKOUT:</h2>
                            <p>Knowing what to eat before and after your workouts is critical so that you can get the
                                most out of those workouts. Depending on what your goals are for your workouts, your
                                nutrition prescription will vary. Many individuals base their pre- and post-workouts
                                meals and snacks on false information and do not consume what will benefit them the
                                most. The poorer your workout nutrition plan, the less energy you'll have for burning
                                calories during your workouts.</p>
                        </div>
                    </div>
                </div>
            </div>
        </div>

    </div>
    <?php
} ?>
<!--poppup 10 end-->

<!--poppup 21 start-->
<?php if ($popupFor == 'contect21') { ?>
    <div class="popup_weightarticle_area">
        <div class="popup_weightarticle_top">
            <div class="popup_weightarticle_left">Weight Loss Articles</div>
            <div class="popup_weightarticle_right">
                <a href="javascript:void(0);" onclick="closeOpenedPopup('fadefriend,datafriend,wla02')"
                   title="Close">X</a>
            </div>
        </div>
        <div id="content_1" class="content">
            <div class="popup_weightarticle_bottom">
                <div class="popup_weightarticle_main">
                    <div class="popup_weightarticle_hed">Fat grams vs. calories: who wins?</div>

                    <div class="popup_weightarticle_contents">
                        <img src="images/fat_grams2.jpg" class="popup_weightarticle1" alt="fat_grams2">
                        <p>The other day I was at the supermarket and I saw a friend of mine with a puzzled look on her
                            face as she was reading the nutrition label of a food product. Generally, whenever I see
                            someone trying to dissect the nutrition label, I'm always curious as to what they are having
                            trouble understanding. So I walked over to her to find out.</p>
                        <p>As I approached her, she looked at me with a funny look on her face and said, &quot;What
                            should I be focusing on so that I don't gain weight, fat grams or calories?&quot; I told her
                            that was an interesting question and that there was a simple and a more complex answer.</p>


                        <h1>The answer</h1>
                        <p>The simple answer, ultimately, is calories. On the other hand, the more complex answer is
                            both calories and fat grams. What determines whether or not you gain any weight at the end
                            of the week is whether or not you ingest more calories (from food) compared to the number of
                            calories your body burns. For the number of calories your body burns, this includes calories
                            derived from your metabolism plus calories burned from physical activity.</p>
                        <p>However, if you do not watch the number of fat grams that you consume, your chances of
                            over-consuming calories increases substantially. This means that for most people, if they do
                            not focus at least somewhat on the number of grams of fat that they consume on a daily
                            basis, they will most likely run into a problem.</p>

                        <h2>The problem</h2>
                        <p>Generally, people who consume too much fat each day, consume too many calories each day as
                            well. There are 9 calories per gram of fat, compared with 4 calories per gram of protein and
                            carbohydrate. So the fat calories can add up fast! Plus, the body uses less energy
                            (calories) to digest fat compared with protein and carbohydrates. So you get some extra fat
                            calories from there as well.</p>
                        <p>From a digestive perspective, the extra calories from fat probably wouldn't make much of a
                            difference with your weight all by themselves. But when you consume too many grams of fat,
                            and likely too many calories, plus you add in extra calories for the digestive effect, you
                            are creating a recipe for weight gain!</p>

                        <h2>Future struggles</h2>
                        <p>To add insult to injury, plenty of high fat foods have a sufficient amount of sugar in them,
                            like cheesecake, for instance. Sugar is addictive to our brains which means the more we
                            consume it, the more we crave it. Thus, you are training your brain, and possibly your taste
                            buds, to be conditioned to desire high fat foods in the future, and to be less conditioned
                            to desire raw, healthy, low fat, low calorie foods like fruits and vegetables.</p>
                        <p>Plus, that delectable, creamy, smooth mouth feel of fat certainly doesn't help deter your
                            desire for high fat foods either. The consequence is that you set yourself up for future
                            struggles with trying to consume fewer fat grams and fewer calories!</p>

                        <h2> Bottom line</h2>
                        <p>If you consume more calories than your body needs, you will likely gain weight. If you
                            consume the number of calories your body needs to maintain its weight, you shouldn't gain
                            any weight. And by limiting the number of grams of fat you consume each day, you will find
                            that it is easier to consume less calories and either achieve or maintain your desired body
                            weight!</p>
                    </div>
                </div>
            </div>
        </div>

    </div>
    <?php
} ?>
<!--poppup 21 end-->


<!--poppup 11 start-->
<?php if ($popupFor == 'contect11') { ?>
    <div class="popup_weightarticle_area">
        <div class="popup_weightarticle_top">
            <div class="popup_weightarticle_left">Weight Loss Articles</div>
            <div class="popup_weightarticle_right">
                <a href="javascript:void(0);" onclick="closeOpenedPopup('fadefriend,datafriend,wla3')"
                   title="Close">X</a>
            </div>
        </div>
        <div id="content_1" class="content">
            <div class="popup_weightarticle_bottom">
                <div class="popup_weightarticle_main">
                    <div class="popup_weightarticle_hed">3 Practices to drastically reduce your calories</div>

                    <div class="popup_weightarticle_contents">
                        <img src="images/practices2.jpg" class="popup_weightarticle1" alt="practices2">
                        <p>Do you realize that you've been brainwashed and you don't even know it? Many people grew up
                            being told that &quot;there are many starving children in the world&quot; and &quot;you
                            can't leave the table until you clean your plate.&quot;</p>
                        <p>You may have also been told that &quot;wasting food means wasting money.&quot; For whatever
                            reason, you have been conditioned to clean everything from your plate. But don't feel bad,
                            you are not alone!</p>
                        <h2>Extra food</h2>
                        <p>I estimate that many people consume about 25% - 50% more food at mealtimes (especially
                            dinner) than their bodies want or need. Why does </p>

                        <p>this happen? The main answer is that they are cleaning their plates after they have gotten
                            signals from their brain that they are starting to get full, which is the point at which
                            they should stop eating. However, many of us keep eating, even though it would be better to
                            have stopped.</p>
                        <p>So how did that extra food get there in the first place? For starters, people have been
                            conditioned, out of habit, to cover their entire plate with food. This process has been
                            helped along by the fact that most of us make too much food to begin with. As a result,
                            there is more food available to us, and when there is more food available to us, the bottom
                            line is that we eat more of it.</p>

                        <h2>Easiest way to cut your amount</h2>
                        <p>The easiest way to cut down on the amount of food you take is to use a smaller plate. This
                            way even if you fill your plate to capacity, you have less than you normally would because
                            the size of your plate is smaller.</p>
                        <p>So for your next dinner meal, instead of using your typical dinner plates, use smaller
                            plates, like lunch plates. You may need to go out and buy different sized plates, but it
                            should be well worth the money!</p>

                        <h2>Don't make so much food</h2>
                        <p>So how do we prevent ourselves from having too much food available to us to take from, before
                            we even fill our plates? First off, ask yourself if you measure out the amount of food you
                            will need food before cooking it. For instance, do you measure out the pasta or just
                            haphazardly dump it into the water in which case you end up making 1.5 - 2.0 times more than
                            you really need?</p>
                        <p>The consequence of this is that when you start feeling full, but still have a lot of pasta
                            left in your bowl, you keep eating until your bowl is empty. The end result is that you just
                            consumed unwanted and unneeded calories, and have made attaining or maintaining your desired
                            body weight that much more difficult.</p>
                        <p>As much as it is important to measure out your food before you make it, you need to know how
                            much to make so that you can measure out the correct amount. If you have gotten used to
                            making more food than you really need, you probably don't even know how much food you need
                            to make.</p>

                        <h2>How much do I need to make</h2>
                        <p>What you can do in this case is just start by making half or two - thirds as much as you
                            normally do. If you find that you are still hungry after eating that amount, you'll know
                            that you need to make a little more next time.</p>
                        <p>Or, better yet, if you are still hungry you could opt for a low calorie salad, some
                            vegetables or fruit to fill up on. This is more highly recommended than eating more of your
                            main dish. This way, you are likely to save calories, and get a greater variety of nutrients
                            into your diet.</p>
                        <h2>Out of sight</h2>
                        <p>If for some reason you do have food left over after you create a plate for yourself, keep it
                            out of sight. If you leave the extra food right in front of you on the table, it is just too
                            easy to reach for more or for someone to encourage you to take more. Having it out of sight
                            can help keep you from leaving the table stuffed!</p>
                        <h2>Bottom line</h2>
                        <p>Over-consuming food and calories at meal times can be avoided. And the result can be a
                            decrease in weight. It is in your best interests to only clean your plate if you are
                            starting with a small plate and an amount of food that your body needs and wants. And
                            remember, the less food you start with, the less you'll consume!</p>
                    </div>
                </div>
            </div>
        </div>

    </div>
    <?php
} ?>
<!--poppup 11 end-->


<!--poppup 12 start-->
<?php if ($popupFor == 'contect12') { ?>

    <div class="popup_weightarticle_area">
        <div class="popup_weightarticle_top">
            <div class="popup_weightarticle_left">Weight Loss Articles</div>
            <div class="popup_weightarticle_right">
                <a href="javascript:void(0);" onclick="closeOpenedPopup('fadefriend,datafriend,wla4')"
                   title="Close">X</a>
            </div>
        </div>
        <div id="content_1" class="content">
            <div class="popup_weightarticle_bottom">
                <div class="popup_weightarticle_main">
                    <div class="popup_weightarticle_hed">3 Keys to prevent overeating</div>


                    <div class="popup_weightarticle_contents">
                        <img src="images/prevent_overeating2.png" class="popup_weightarticle1"
                             alt="prevent_overeating2">
                        <p>Everyone seems to know that consuming too much food leads to weight gain, particularly fat
                            mass around the belly and hips. We also know that being overweight or obese can have far
                            greater consequences, such as greatly increasing our risk of developing cancer, Type-2
                            diabetes, heart disease, stroke, high blood pressure and many other debilitating
                            illnesses.</p>
                        <p>Many people that have already achieved a healthy weight have seen that one of the main
                            obstacles that they needed to overcome was overeating. I've listed 3 mistakes people whom
                            overeat tend to make and then the 3 keys to prevent overeating.</p>
                        <h1>Mistake #1: Not knowing the cause of your overeating</h1>
                        <p>If your goal is to overcome your overeating, don't you first need to know the causes of
                            it?</p>
                        <p>As I have helped individuals determine their causes of overeating over the years I have seen
                            that one or more of the following reasons tend to be at the core of their struggle:</p>
                        <ul>
                            <li>Addicted to food.</li>
                            <li>Love the taste of food.</li>
                            <li>Hungry all the time.</li>
                            <li>Emotional eater (eat whenever depressed, stressed, bored, or lonely or whenever another
                                emotion is present).
                            </li>
                            <li>Habit.</li>
                            <li>Binge Eating Disorder.</li>
                            <li>Blood sugar fluctuates throughout the day.</li>
                            <li>Addicted to sugar.</li>
                            <li>Addicted to fast food.</li>
                            <li>Only thing find enjoyable in the day.</li>
                        </ul>
                        <p>One of the difficulties with determining the causes of overeating is that many people are
                            either unaware of what it is because they have never really thought about it or that they
                            are in total denial that they even have an issue with it in the first place.</p>
                        <p>Assuming that you are aware that you do have a problem with overeating, in order to overcome
                            it you first need to be aware of what the root causes are.</p>
                        <h2>Key #1 to prevent overeating</h2>
                        <p>Determine the causes of your overeating. Think of this as your starting point, not your end
                            point. To begin with you need to develop greater awareness about yourself to figure out what
                            your true causes of overeating are.</p>
                        <p>The next step after determining your causes is to determine how you are going to overcome
                            them. In attempting to overcome them it is highly recommended that you create a plan that
                            incorporates goal&ndash;setting where your goals are overcoming your obstacles.</p>
                        <h2>Mistake #2: Skipping Snacks In Between Meals</h2>
                        <p>Some people have heard that you shouldn't snack in between meals because snacks mean extra
                            calories. On one hand snacks do contain calories because they are food and all foods have
                            calories, obviously. On the other hand without consuming snacks in between your meals you
                            are likely to become overly hungry which can lead to a few problems.</p>
                        <p>Problem #1: When we become overly hungry we tend to make poor food choices, such as choosing
                            foods high in sugar, fat and of course, calories.</p>
                        <p>Problem #2: For our next meal We prepare more food than what our bodies really want or need
                            simply because we are so hungry.</p>
                        <p>Problem #3: Now that we have a lot of food in front of us, we overeat simply because it is
                            there and available to us. This leads to taking in a lot more calories than if we had
                            snacked in between meals and had a smaller, portion-controlled meal afterwards.</p>

                        <h2>Key #2 to prevent overeating</h2>
                        <p>Have a high fiber or high protein snack in between your meals to keep from becoming too
                            hungry in between meals and at mealtimes which can help to prevent the problems above. You
                            can also try drinking a lot of calorie-free liquids between meals.</p>
                        <p>Research shows that consuming liquids works well for some people while consuming a high
                            protein or high fiber snack works best for others. How many calories your snack should be
                            can be dependent upon a few factors, but in general it is a good idea to keep your snack to
                            about 150 calories per snack.</p>

                        <h2>Mistake #3: Skipping meals</h2>
                        <p>In addition to having heard that you should skip snacks to cut calories, many people have
                            heard that they should also skip meals. Simply, you encounter the same problems when
                            skipping meals that you do when you skip snacks, though the problems may be more pronounced
                            with skipping meals .</p>

                        <h2>Key #3 to prevent overeating</h2>
                        <p>You want to be eating sensibly throughout the day. This should look like one of the
                            following. Either 3 healthy, portion&ndash;controlled meals plus 2&ndash;3 healthy, calorie&ndash;controlled
                            snacks, or, 5&ndash;6 mini&ndash;meals per day.</p>
                        <p>A non&ndash;mini meal would have most of your calories coming from breakfast, lunch and
                            dinner, with your snacks having significantly fewer calories. On the other hand, 6 mini&ndash;meals
                            would have all 5&ndash;6 mini&ndash;meals containing about the same number of calories. At
                            the end of the day, regardless of which method you chose you should have consumed the same
                            number of calories for the day.</p>
                        <h2>Summary</h2>
                        <p>Overeating revolves around the consumption of too much food which then leads to excess weight
                            gain. Keys to preventing it include not skipping snacks or meals, eating throughout the day
                            without extensive periods of time in between meals, and being aware of portion sizes.
                            However, the most crucial factor with preventing overeating is determining the root causes
                            of it and then overcoming those obstacles.</p>
                        <p>You may find that it has everything to do with what your mother said to you when you were
                            younger to how unhappy you are at your job. Whatever the reason is, it is the most important
                            thing you need to do to prevent excessive food consumption and weight gain!</p>

                    </div>

                </div>
            </div>
        </div>

    </div>
    <?php
} ?>
<!--poppup 12 end-->


<!--poppup 13 start-->
<?php if ($popupFor == 'contect13') { ?>
    <div class="popup_weightarticle_area">
        <div class="popup_weightarticle_top">
            <div class="popup_weightarticle_left">Weight Loss Articles</div>
            <div class="popup_weightarticle_right">
                <a href="javascript:void(0);" onclick="closeOpenedPopup('fadefriend,datafriend,wla5')"
                   title="Close">X</a>
            </div>
        </div>
        <div id="content_1" class="content">
            <div class="popup_weightarticle_bottom">
                <div class="popup_weightarticle_main">
                    <div class="popup_weightarticle_hed">How to avoid binging after work</div>
                    <div class="popup_weightarticle_content">

                        <div class="popup_weightarticle_contents">
                            <img src="images/avoid2.jpg" class="popup_weightarticle1" alt="avoid2">
                            <p>When it comes to making changes with your weight, you have to make changes with your
                                behavior, and this often involves breaking bad habits. This is one of the most important
                                things that you must absolutely do to be successful with your weight goals!</p>
                            <p>A habit is something you repeatedly do, whether it be on an hourly, daily or weekly
                                basis.</p>
                            <p>I've had clients tell me that one of their worst habits is to go right into the kitchen
                                after they walk in the door after work and start snacking, sometimes to the point of
                                binging. They say that either they feel stressed, </p>
                            <p>depressed, are hungry because they haven't eaten in so long, are addicted to binging
                                after work, or some other reason.</p>
                            <p>Obviously this habit is detrimental to their weight loss efforts. Most clients who engage
                                in this behavior are aware that it definitely interferes with their efforts to either
                                lose weight or maintain their current weight.</p>
                            <h2>Psychological factors</h2>
                            <p>What's behind your bad habit? For different people it is something different. It could be
                                one of the things mentioned above like stress or hunger, or another reason.</p>
                            <p>So how do you change your 'bad' habit? The first thing you need to do is really look at
                                your circumstances and your state of mind and ask yourself, &quot;What are the driving
                                psychological factors here that are leading me to engage in this maladaptive behavior?&quot;</p>
                            <h2>Emotions</h2>
                            <p>In doing this, it would be a good idea to first look at what emotions are involved here,
                                the emotions you are experiencing before you engage in this eating behavior. What are
                                the emotions that are triggering this behavior?</p>
                            <p>And realize that your thoughts have a tremendous impact on your emotions and feelings. It
                                would be nice to say, &quot;Just stay positive and your feelings and behaviors will be
                                fine&quot;. Realistically, this is a good place to start because the more positive your
                                thoughts, the more positive your feelings will be, in general.</p>
                            <p>However, you can't stop there. You really have to look deeper within yourself to get at
                                the root of the problem so that you can make lasting changes. You need to determine what
                                your major challenges are.</p>

                            <h2>The real issue</h2>
                            <p>I once had a client who previously found her job very satisfying. However, when I started
                                seeing her, she no longer felt that way. As a consequence of this, she compensated for
                                her lack of job satisfaction by eating more, especially once she walked in the door
                                after work. Before discussing this with her, she really had no idea why she was binging
                                after work; it just wasn't obvious to her.</p>

                            <h2>Bottom line</h2>
                            <p>The bottom line is that you can't separate food consumption and your thoughts and
                                feelings &ndash; they are tremendously intertwined. You really have to look at what is
                                driving your negative behaviors, that is, what the root causes are. Then you can begin
                                to create a plan to overcome these obstacles so that you can achieve your weight loss
                                goals!</p>
                        </div>
                    </div>
                </div>
            </div>
        </div>

    </div>
    <?php
} ?>
<!--poppup 13 end-->


<!--poppup 14 start-->
<?php if ($popupFor == 'contect14') { ?>
    <div class="popup_weightarticle_area">
        <div class="popup_weightarticle_top">
            <div class="popup_weightarticle_left">Weight Loss Articles</div>
            <div class="popup_weightarticle_right">
                <a href="javascript:void(0);" onclick="closeOpenedPopup('fadefriend,datafriend,wla6')"
                   title="Close">X</a>
            </div>
        </div>
        <div id="content_1" class="content">
            <div class="popup_weightarticle_bottom">
                <div class="popup_weightarticle_main">
                    <div class="popup_weightarticle_hed">How to prevent to your snack from turning into a meal</div>

                    <div class="popup_weightarticle_contents">
                        <img src="images/turning2.jpg" class="popup_weightarticle1" alt="turning2">
                        <p>If you ask people who are overweight what they think their extra weight is due to, many of
                            them will tell you that snacking has had something to do with it. No surprise here.</p>
                        <p>Most people know that excessive snacking can lead to a whole lot of extra calories that our
                            bodies don't need or want. And that the result is weight gain!</p>
                        <p>When it comes to smart snacking, there are a few things to keep in mind.</p>
                        <h1>Meals, not snacks!</h1>
                        <p>One, if you find yourself binging on snacks, then you probably have more</p>

                        <p> of an issue with your meals than you do with your snacks. For instance, are you going too
                            long in between meals in which you become ravenously hungry and snack excessively as a
                            result? If so, your main obstacle here is with your meals, such as the timing and
                            content.</p>

                        <p>If you go too long without eating, you will likely start having serious cravings for sweets.
                            Ever been there? I have. And the next thing you know, bam, you are binging on sweets and
                            consuming a large amount of calories in the process.</p>
                        <p>Isn't it funny that when we get that hungry because there is no food around or we don't have
                            the time to stop and eat sensibly, that we can always find sweets to snack on? Though that
                            'snack' soon turns into a high calorie meal!</p>
                        <p>Not only is this bad because of the high amount of calories you just consumed, but it is
                            detrimental because it makes eating intelligently for the rest of the day that much more
                            difficult. And it could be the start of a bad habit as well!</p>
                        <p>Obviously, the key here is to make sure that you don't go too long without eating so that
                            your snack doesn't turn into a high calorie meal, as well as look at what you are actually
                            consuming at meal time.</p>

                        <h2>A healthy snack</h2>
                        <p>You may ask, &quot;What constitutes a healthy snack?&quot; To start with, one that has about
                            150 - 200 calories. Keeping your snacks to this amount seems to be beneficial for most
                            people.</p>
                        <p>Secondly, consuming a snack that is high in fiber or protein is a good idea as well. You
                            don't want to eat a snack that is going to get digested too quickly because you will get
                            hungry sooner, rather than later.</p>
                        <p>An example of a high fiber or high protein snack would be a small homemade chicken salad with
                            calorie-free dressing. If you consumed 2&ndash;3 oz of lean skinless chicken breast, with
                            calorie-free dressing, and some mixed greens and other vegetables, you would be below 200
                            kcals for this snack that should keep you full until your next meal.</p>

                        <h2>Simple snack</h2>
                        <p>For a simpler snack, you could consume a small piece of fruit or half an apple with 1
                            tablespoon of peanut butter, a homemade bran muffin, or a low-carb protein bar, for
                            example.</p>

                        <h2>Bottom line</h2>
                        <p>Enjoy your snack, but let the main purpose of it be to give you nutrition for energy, as well
                            as carry you from one meal to the next without the consumption of too many calories in
                            between!</p>
                    </div>
                </div>
            </div>
        </div>

    </div>
    <?php
} ?>
<!--poppup 14 end-->


<!--poppup 15 start-->
<?php if ($popupFor == 'contect15') { ?>
    <div class="popup_weightarticle_area">
        <div class="popup_weightarticle_top">
            <div class="popup_weightarticle_left">Weight Loss Articles</div>
            <div class="popup_weightarticle_right">
                <a href="javascript:void(0);" onclick="closeOpenedPopup('fadefriend,datafriend,wla7')"
                   title="Close">X</a>
            </div>
        </div>
        <div id="content_1" class="content">
            <div class="popup_weightarticle_bottom">
                <div class="popup_weightarticle_main">
                    <div class="popup_weightarticle_hed">3 Ways to stop gaining weight at work</div>

                    <div class="popup_weightarticle_contents">
                        <img src="images/gaining_weight2.jpg" class="popup_weightarticle1" alt="gaining_weight2">
                        <p>Have you ever considered that by having a job it can be hazardous to your weight? This can
                            actually be true, to an extent. But before you decide to quit your job, continue
                            reading...</p>

                        <h1>Colleague's snacks</h1>
                        <p>You may ask, &quot;How is this possible?&quot; Think of it this way. You start a new job and
                            what do you know, your new colleagues have brought in some of your favorite, high calorie
                            snacks.</p>
                        <p>Then you find yourself saying, &quot;Why did they have to bring that in today &ndash; I love
                            those things!&quot; So what do you do, just resist temptation? You can try, but there is a
                            better solution.</p>

                        <h1>(1) Answer</h1>
                        <p>The best solution is to plan ahead and bring in your own favorite, low fat, low calorie
                            snacks. This way, if your coworkers bring in snacks, it will be much easier to resist them
                            knowing that you are not going to go hungry or feel deprived by avoiding them because you
                            know you have your own delicious snacks that you would much rather have anyway!</p>
                        <p>Additionally, by the time you see the snacks that others have brought in you may have just
                            finished your own lower calorie, tasty snacks, enjoyed them even more, and now have no
                            desire for theirs. This can make avoiding coworker's cellulite gaining snacks that much
                            easier!</p>
                        <h2>Fast food lunch</h2>
                        <p>Then there are the coworkers who insist that you go out for lunch. You tell them that you
                            brought your lunch, but they moan and groan and insist, and eventually you give in and
                            go.</p>
                        <p>Some coworkers at lunch time will want to go the cheapest route which will likely means your
                            typical fast food establishment which has served zillions of customers over the years. In
                            this situation, your options are limited and you are definitely in a more difficult
                            situation.</p>
                        <h2>(2) What you should do</h2>
                        <p>There are a couple of things you can do. Before you order anything, get your hands on their
                            nutrition facts sheet or pamphlet.Look and see what foods are available and are lowest in
                            calories (and grams of saturated and trans fat for heart healthy reasons).</p>
                        <p>For instance, do they have a salad with some (non&ndash;fried) chicken and some low or zero
                            calorie dressing (versus the traditional blue cheese or ranch dressing)? Do they have a
                            small baked potato with salsa available? You get the idea.</p>
                        <p>And for fluids, obviously going with 32 oz of soda is not going to be your friend here. How
                            about water - tap or bottled? What else do they have on the menu &ndash; take a look!</p>
                        <p>As far as diet soda goes, many studies show that people who consume diet soda don't lose any
                            more weight than people who consume regular soda. Try to make it a point not to consume any
                            calories from liquids. That alone may save you from a disaster lunch.</p>
                        <p>Remember that when you go to eat at places that favor weight gain, you don't have to have as
                            much food as you normally would. You just need to survive the experience!</p>


                        <h2>(3) Know in advance</h2>
                        <p>Even better than going in and trying to figure out what options you have available to you,
                            know ahead of time. For many places you can find out online what their choices are as well
                            as what the nutrition facts are for each food.</p>
                        <p>Making a quick decision while you are standing on line and in a rush to get your food so that
                            you can get back to work on time doesn't always lead to a good decision. So know before you
                            get there!</p>
                        <p>Additionally, you don't have to think of this as &quot;lunch.&quot; Rather, you can think of
                            it as a snack, and that you will have the lunch you brought in when it is time to have your
                            afternoon snack.</p>
                        <p>Granted, this may not go over too well with your coworkers at the lunch table, but you need
                            to stay committed to your goals. And from a general perspective, you certainly want to stay
                            away from anything deep fried, such as french fries.</p>
                        <p>Also, your burgers here are loaded with grams of fat which means lots of calories. And even
                            if you order a salad and use their typical dressings, like ranch or blue cheese, you are in
                            for plenty of calories also (especially if you drench your salad as many people do)!</p>

                        <h2>Bottom line </h2>
                        <p>Bringing your own healthy, delicious snacks with you to work will deter you from consuming
                            your coworker's high calorie, fatty foods. For fast food meals, like lunch, determine what
                            they have that is healthy and low calorie and stick with that, even if it means eating less.
                            Eating out for lunch at less than desirable fast food places doesn't have to lead to weight
                            gain city!</p>
                    </div>
                </div>
            </div>
        </div>

    </div>
    <?php
} ?>
<!--poppup 15 end-->


<!--poppup 16 start-->
<?php if ($popupFor == 'contect16') { ?>
    <div class="popup_weightarticle_area">
        <div class="popup_weightarticle_top">
            <div class="popup_weightarticle_left">Weight Loss Articles</div>
            <div class="popup_weightarticle_right">
                <a href="javascript:void(0);" onclick="closeOpenedPopup('fadefriend,datafriend,wla8')"
                   title="Close">X</a>
            </div>
        </div>
        <div id="content_1" class="content">
            <div class="popup_weightarticle_bottom">
                <div class="popup_weightarticle_main">
                    <div class="popup_weightarticle_hed">5 Steps to overcoming an obstacle</div>

                    <div class="popup_weightarticle_contents">
                        <img src="images/overcoming2.png" class="popup_weightarticle1" alt="overcoming2">
                        <h1>Step 1: Get Motivated to overcome it!</h1>
                        <p>If you are going to overcome an obstacle you'll need to look at the obstacle as a challenge
                            and get motivated to overcome it! Consider what you will gain if you are successful with
                            overcoming your obstacle as well as consider what you will lose out on if you are not
                            successful.</p>
                        <h1>Step 2: Determine why the obstacle is there!</h1>
                        <p>Now that you know what your obstacle is and you are motivated to accomplish it, you need to
                            ask yourself why is it there. Determining why the obstacle is there will give you tremendous
                            insight as to how you are going to overcome it.</p>

                        <p>You need to spend some time on this. Why you think the obstacle is there may not be the real
                            reason why it actually is there. Take your time and consider all possibilities.</p>
                        <h2>Step 3: Repeat step 2!</h2>
                        <p>Oddly enough, once you determine why your obstacle exists, then ask yourself why that reason
                            (that you just came up with in step 2) exists. For instance, one of my former patients
                            consistently overate at dinner time, which was his number one obstacle.</p>
                        <p>He did this because he wasn't enjoying the rest of his day and looked to dinner for his day's
                            pleasure. From there we had to determine why that reason existed, specifically, why he
                            wasn't getting much pleasure from the rest of his day. If we hadn't looked more deeply at
                            his issue, we wouldn't have determined what he really needed to do to be successful.</p>

                        <h2>Step 4: Ask Questions to Create a Recipe!</h2>
                        <p>Subsequently, with this client the focus then became creating a recipe for success for him.
                            What kind of a plan did we need to create in order for him to be successful? To determine
                            this we started asking some questions which would help us decide how to go about it.</p>
                        <p>For example:</p>
                        <p>&quot;What's the first thing that needs to be done, what will we need to do this, and how
                            will we do it?&quot;</p>
                        <p>&quot;How have you overcome a similar obstacle in the past?&quot;</p>
                        <p>&quot;What are all of the resources at your disposal?&quot;</p>
                        <p>&quot;How would someone else that you know attack the same problem?&quot;</p>

                        <h2>Step 5: Time&ndash;Line &amp; Accountability!</h2>
                        <p>Now that you have a plan for overcoming your obstacle, you need to develop a time&ndash;line
                            for when you are going to accomplish the different aspects within it. Set a deadline for
                            when items in your plan need to be accomplished by.</p>
                        <p>And finally, have someone hold you accountable with the mini&ndash;goals that you have
                            created in order to overcome your obstacles and accomplish your main goal. Accountability
                            can be your best friend when it comes to staying on track and accomplishing everything that
                            you need to!</p>

                    </div>
                </div>
            </div>
        </div>

    </div>
    <?php
} ?>
<!--poppup 16 end-->


<!--poppup 17 start-->
<?php if ($popupFor == 'contect17') { ?>
    <div class="popup_weightarticle_area">
        <div class="popup_weightarticle_top">
            <div class="popup_weightarticle_left">Weight Loss Articles</div>
            <div class="popup_weightarticle_right">
                <a href="javascript:void(0);" onclick="closeOpenedPopup('fadefriend,datafriend,wla9')"
                   title="Close">X</a>
            </div>
        </div>
        <div id="content_1" class="content">
            <div class="popup_weightarticle_bottom">
                <div class="popup_weightarticle_main">
                    <div class="popup_weightarticle_hed">Motivation: 5 keys to setting "smart" goals!</div>

                    <div class="popup_weightarticle_contents">
                        <img src="images/motivation2.png" class="popup_weightarticle1" alt="motivation2">
                        <p>It's extremely important to set goals &ndash; goals are what's at the heart of motivation!
                            When we stop aiming for a goal, we forget why we are putting forth such an effort every
                            day.</p>
                        <p>Consequently, without a goal, we stop trying so hard. When setting goals it is very important
                            to set goals that are &quot;SMART,&quot; which includes the following:</p>
                        <h1>(1) Specific</h1>
                        <p>Make sure your goals are specific. For instance, just stating that you want to "lose weight"
                            is not specific. If you want to lose weight, you need to state exactly how much weight you
                            want to lose, though keep in mind, you can always change this amount later. </p>
                        <p>But you need to have a specific amount in mind that you are aiming for right from the
                            beginning of your weight loss efforts!</p>
                        <h1>(2) Measurable</h1>

                        <p>Your goals must be measurable. If your goals are measurable, you can then tell if you are
                            making progress with your goals as well as if you have reached them.</p>
                        <p>For instance, if your goal is to lose 10 pounds in 10 weeks, you can measure whether or not
                            you are achieving that goal as you work towards it each week. And at the end of the 10 weeks
                            you can tell if you have reached your goal!</p>
                        <h2>(3) Adjustable</h2>
                        <p>It's important to be flexible with your goals. For instance, if you see that you need more
                            (or less) time to achieve a goal, be willing to adjust your time line or even the goal
                            itself.</p>
                        <p>Ultimately, you want to be successful with your goals and being successful usually includes
                            being flexible!</p>
                        <h2>(4) Realistic</h2>
                        <p>Your goals should be realistic. If your goals are not realistic, you may soon lose your
                            motivation due to making such a strong effort and not feeling like you are much closer to
                            attaining your goals.</p>
                        <p>It's great to expect the best from yourself and set "challenging" goals, but being realistic
                            at the same time will facilitate you in maintaining your motivation throughout the process
                            as well as in accomplishing them!</p>

                        <h2>(5) Timely</h2>
                        <p>Your goals should have a time line. If your goal is to lose 10 pounds, you should specify
                            when you want to lose that weight by, such as a certain number of weeks or a specific
                            date.</p>
                        <p>Having a timely deadline will help keep you motivated because you know you do not have an
                            endless amount of time by which to accomplish your goal! You are well aware that the clock
                            is ticking!!!</p>

                        <h2>Bottom line</h2>
                        <p>Goals motivate! It's important to use good strategy when setting goals. Above are 5 key
                            principles to include in your goal&ndash;setting plan.</p>
                        <p>And make sure to write your goals down and keep them somewhere where you'll see them
                            everyday. Also, have someone hold you accountable with your goals and subsequent actions.
                            Just knowing someone is going to be checking in with you to make sure you are doing what you
                            are suppose to be doing as well as what you said you would do, can be a much needed
                            motivator!</p>
                    </div>
                </div>
            </div>
        </div>

    </div>
    <?php
} ?>
<!--poppup 17 end-->


<!--poppup 18 start-->
<?php if ($popupFor == 'contect18') { ?>
    <div class="popup_weightarticle_area">
        <div class="popup_weightarticle_top">
            <div class="popup_weightarticle_left">Weight Loss Articles</div>
            <div class="popup_weightarticle_right">
                <a href="javascript:void(0);" onclick="closeOpenedPopup('fadefriend,datafriend,wla10')"
                   title="Close">X</a>
            </div>
        </div>
        <div id="content_1" class="content">
            <div class="popup_weightarticle_bottom">
                <div class="popup_weightarticle_main">
                    <div class="popup_weightarticle_hed">Increase your awareness &amp; lose weight fast!</div>

                    <div class="popup_weightarticle_contents">
                        <img src="images/Increase2.png" class="popup_weightarticle1" alt="Increase2">
                        <p>In behavioral and sport psychology we like to say, &quot;The first key to gaining control
                            over any situation is awareness.&quot; In order to tackle an obstacle that is plaguing your
                            weight loss efforts, you first have to be aware of what that obstacle is.</p>
                        <h1>Keep a food journal</h1>
                        <p>One of the most important tools used in nutrition therapy is the 'food journal.' The food
                            journal can bring about a tremendous amount of enlightenment for us in regards to our eating
                            habits.</p>
                        <p>First, it allows us to become aware of what we are actually eating.</p>

                        <p> Because so many people 'pick' throughout the day, by days end most of us really aren't aware
                            of how many different foods we have consumed.</p>
                        <p>When I have looked over a client's food journal and asked them about a specific food item
                            they consumed, often times they will look at me quite puzzled, and say, &quot;Did I really
                            eat that? I don't remember eating it.&quot;</p> Becoming aware of what you are actually
                        eating is the first step towards becoming successful with your weight loss!

                        <h2>How much did I really eat?</h2>
                        <p>And of course there is the issue of "how much" you have consumed. By keeping track of what
                            food items you have consumed and the amount for each of them, you can now see where you are
                            consuming excess calories due to the sheer volume of what you have chosen to eat.</p>
                        <p>Even more puzzling to clients than seeing what items they have consumed is seeing how much of
                            each item they have consumed!</p>

                        <h2>Don't do this</h2>
                        <p>A good example of why it's important to keep a food journal would be the case of eating chips
                            right out of the bag. When we do this we aren't aware of how much we are consuming while we
                            are eating them. And then we walk away after we're done not aware of how many calories all
                            those chips just added up to. If we are keeping a food journal, we would have to write down
                            how much we just ate which would facilitate us in determining how many calories we just
                            consumed. One of the additional benefits to this is that since we are calories conscious,
                            this would encourage us to measure out a specific amount the next time we reach for a bag of
                            chips instead of just eating mindlessly!</p>

                        <h2>Summary</h2>
                        <p>Simply, keeping a food journal greatly facilitates us in becoming aware of what foods, and
                            how much of them, we are consuming. It also helps us to determine how many total calories we
                            are taking in for the entire day, as well as encourges us to measure foods out before
                            cooking or eating them. Subsequently, when we are snacking we tend to consume less food and
                            less calories which often times leads to losing weight faster, or not gaining the excess
                            weight in the first place!</p>
                    </div>
                </div>
            </div>
        </div>

    </div>
    <?php
} ?>
<!--poppup 18 end-->


<!--poppup 19 start-->
<?php if ($popupFor == 'contect19') { ?>

    <div class="popup_weightarticle_area">
        <div class="popup_weightarticle_top">
            <div class="popup_weightarticle_left">Weight Loss Articles</div>
            <div class="popup_weightarticle_right">
                <a href="javascript:void(0);" onclick="closeOpenedPopup('fadefriend,datafriend,wla4')"
                   title="Close">X</a>
            </div>
        </div>
        <div id="content_1" class="content">
            <div class="popup_weightarticle_bottom">
                <div class="popup_weightarticle_main">
                    <div class="popup_weightarticle_hed">GETTING STARTED WITH TRAINING</div>

                    <div class="popup_weightarticle_contents">
                        <img src="images/older_man_abs.jpg" class="popup_weightarticle1" alt="prevent_overeating2">
                        <p>Many people who would like to manage their weight more effectively would like to start
                            working out, but they have 'approach-avoidance' issues. Simply, they start to take steps
                            that will lead them to working out each week, which is their "approach" phase. But then
                            there is something that holds them back from following through and they never get started.
                            This is their "avoidance" phase. These individuals often will go through this same cycle
                            many times in the future when it comes to starting an exercise program.</p>

                        <h1>FEAR</h1>
                        <p>One main reason people have approach-avoidance issues towards working out, simply, is fear.
                            Most of them have been in some type of gym setting before. But for many of them it was a
                            long time ago! And they want to get back into working out, but avoid it because of fear. For
                            starters, one thing they fear is that they will get hurt while working out because they know
                            that they really don't know how to do the exercises or use the machines properly. So they
                            avoid it altogether!</p>

                        <h1>NAGGING INJURIES</h1>
                        <p>Interestingly enough, these individuals have good reason to believe they will get hurt. In
                            addition to lacking enough knowledge about the equipment and exercises, another reason they
                            might get hurt is that they have some areas of their body which are problematic, such as
                            nagging injuries and tight spots. Not knowing how to compensate for these old injuries and
                            tight areas can lead them to get hurt quite quickly and then decide that they are never
                            working out again! Or if they do keep working out, they may totally avoid working out any
                            body parts that involve these muscles, which can also be a very big mistake often-times.</p>

                        <h1>TARGET LIMITATIONS</h1>
                        <p>One of the jobs of a good personal trainer is to first identify which areas of a client's
                            body are weaknesses or have the potential to be troublesome. Then the client and trainer put
                            together a plan that works out the entire body, with an emphasis on these limiting body
                            parts. While working out the entire body, special attention is placed on keeping these areas
                            out of harm's way. And additionally, learning how to stretch and strengthen these areas
                            needs to be addressed and become a priority!</p>

                        <h1>UTILIZE AVAILABLE RESOURCES</h1>
                        <p>Simply, don't let fear (as rational as it might or might not be) get in your way of creating
                            a better, healthier body. Utilize the help of a qualified personal trainer, as well as a
                            physical therapist, to reach your goals. Getting started with an exercise program can be
                            intimidating for many reasons, but you can utilize the help of others to get you started
                            down the path to a healthier you. You have the power to get started, and if you do, you will
                            likely be very glad that you did!</p>
                    </div>


                </div>
            </div>
        </div>

    </div>
    <?php
} ?>
<!--poppup 19 end-->


<!--poppup 20 start-->
<?php if ($popupFor == 'contect20') { ?>

    <div class="popup_weightarticle_area">
        <div class="popup_weightarticle_top">
            <div class="popup_weightarticle_left">Weight Loss Articles</div>
            <div class="popup_weightarticle_right">
                <a href="javascript:void(0);" onclick="closeOpenedPopup('fadefriend,datafriend,wla4')"
                   title="Close">X</a>
            </div>
        </div>
        <div id="content_1" class="content">
            <div class="popup_weightarticle_bottom">
                <div class="popup_weightarticle_main">
                    <div class="popup_weightarticle_hed">WORKING OUT AT HOME – GETTING STARTED</div>

                    <div class="popup_weightarticle_contents">
                        <img src="images/2_ladies_on_mat_abs.jpg" class="popup_weightarticle1"
                             alt="prevent_overeating2">
                        <p>Are you one of the many people who do not enjoy working out in a gym setting? Would you
                            prefer to work out at home? Many people would and should consider this option. But before
                            you get started working out at home or start an exercise program, get medical clearance from
                            your physician first!</p>

                        <h1>BE IN THE KNOW!</h1>
                        <p>In order to burn calories and create a better body, you don't have to huff and puff in a gym
                            setting with lots of strangers. You can get a great workout at home! However, you should
                            know what to do and how to do it correctly to maximize effectiveness and minimize risk of
                            injury.</p>

                        <h1>USE PROPER FORM</h1>
                        <p>For instance, if you want to lift dumbbells at home you might think 'lifting dumbbells is a
                            no-brainer'. Well you're right in that it is not quantum physics, but like most everything
                            else, there is a right and a wrong way to do it. One thing to keep in mind and focus on when
                            lifting dumbbells is your form. For a lot of beginners, their form when it comes to this
                            'simple' task, is atrocious!</p>

                        <p>For example, whenever I walk past a fitness center that has large windows where you can
                            easily look in and see lots of people lifting weights, I am almost always amazed as to the
                            horrible form that many people use. Literally, it looks like they are working out a
                            different body part than the body part that is intended to be worked by that exercise!</p>

                        <p>For instance, when doing standing dumbbell curls, their form is so bad that they seem to be
                            working their shoulders and back more than their biceps. This sounds ridiculous because it
                            is ridiculous!! So if you want to work out at home, make sure you know what proper form
                            really looks like and use that form.</p>

                        <h1>PHYSICAL LIMITATIONS</h1>
                        <p>Keep in mind that proper form for you may be somewhat different than what it is for someone
                            else because of physical limitations that you may have. And if your physical limitations
                            lead you to think you need to use bad form, then either find out how to do that exercise
                            properly from a qualified professional, or pick a different exercise. Don't use physical
                            limitations as an excuse to workout improperly.</p>

                        <h1>LIMITED RESULTS</h1>
                        <p>Secondly, you need to know numerous exercises for each body part. You need to know this
                            because if you only do the same exercise for a certain body part every time you workout that
                            specific body part, your body will get used to that exercise quickly and you will stop
                            seeing much, if any, improvement. So you need to know multiple exercises for each body part
                            and how to do them correctly.</p>

                        <h1>CORE</h1>
                        <p>One of the most important things that should be addressed when starting (or re-starting) an
                            exercise program is your core. Core includes, but is not limited to your abdominals, glutes,
                            torso and lower back. In order to progress with exercises that use weights for any exercise,
                            you will need to have strong core muscles for numerous reasons.</p>

                        <p>First, you don't want to pull any of your core muscles when working out because that will
                            limit your choice of exercises after that since every exercise incorporates at least some of
                            your core muscles. Plus, of course, nobody wants to pull or strain a muscle anywhere! All
                            strength starts and emanates from the core so it is extremely important to get your core
                            strong and then keep it strong.</p>

                        <p>Also, as you start to move up in weight with your exercises, you will notice a much greater
                            need to have strong core muscles. Literally, if your core is weak you will find it difficult
                            to utilize proper form for weight lifting exercises as the weight becomes heavier as you get
                            stronger. So even if you don't pull a muscle with a weak core, it can negatively impact the
                            progression of your workouts.</p>

                        <h1>TAKE-HOME MESSAGE</h1>
                        <p>The take-home message here is if working out at home works for you, consider doing it! But
                            first find out what to do and how to do it correctly to maximize calorie burning and
                            decrease risk of injury! Good luck!</p>
                    </div>


                </div>
            </div>
        </div>

    </div>
    <?php
} ?>
<!--poppup 20 end-->

<?php if ($popupFor == 'contect23') { ?>
    <div class="popup_weightarticle_area">
        <div class="popup_weightarticle_top">
            <div class="popup_weightarticle_left"></div>
            <div class="popup_weightarticle_right">
                <a href="javascript:void(0);" onclick="closeOpenedPopup('fadefriend,datafriend,ts')" title="Close">X</a>
            </div>
        </div>
        <div id="content_1" class="content">
            <div class="popup_weightarticle_bottom">
                <div class="popup_weightarticle_main">
                    <div class="popup_weightarticle_hed"></div>

                    <div class="popup_weightarticle_contents">
                        <h1>
                            <center>TERMS OF SERVICE AGREEMENT</center>
                        </h1>
                        <ol>
                            <h3><u>
                                    <li>ASSESSMENT FORM:</li>
                                </u></h3>
                            <p>Before any (paid) consulting begins, you MUST fill out the entire assessment form and
                                return it to me, signed. If you do not get the form to me at least 1 day before the time
                                of our first paid consulting appointment, your first appointment is automatically
                                rescheduled for the following week - no exceptions. If you do not want to answer all of
                                the questions on the form, you must put your initials in the blank space provided for
                                each numbered question signifying that you read the question and decided not to answer
                                it. The information I receive on the assessment form is absolutely essential for me
                                being able to see the big picture with your weight loss issues. The assessment form is
                                there for YOUR benefit.</p>

                            <h3><u>
                                    <li>REFUNDS:</li>
                                </u></h3>
                            <p>Full refunds are available for 72 hours starting from the following midnight of the day
                                you purchase the program. There are no partial refunds given at any time unless I make
                                an exception to the refund policy. </p>

                            <h3><u>
                                    <li>(24/7) EMAIL SUPPORT:</li>
                                </u></h3>
                            <p>Email support is limited to short-answer questions only. For questions that require a
                                more detailed response, these questions need to be asked and discussed during our
                                regular weekly session. 24/7 email support limits weekly email questions to 7
                                short-answer questions per week. You have the opportunity to ask one or more questions
                                per day, or, all of them on the same day of the week. This is done to prevent clients
                                from taking advantage of this policy. If for some reason you should need to ask more
                                questions, just request it and if you have not been trying to take advantage of the
                                policy it will almost definitely be answered. Anthony Wilson/ Anthony Wilson Consulting
                                reserves the right to have the final say as to what constitutes a “short-answer”
                                question.</p>

                            <h3><u>
                                    <li>PROGRAM CANCELLATION OF A CLIENT'S PROGRAM BY ANTHONY WILSON/ ANTHONY WILSON
                                        CONSULTING AFTER COACHING HAS BEGUN:
                                    </li>
                                </u></h3>
                            <p>Program cancellation of a clients program by Anthony Wilson/ Anthony Wilson Consulting is
                                unlikely to happen. However, Anthony Wilson/ Anthony Wilson Consulting reserves the
                                right to cancel any of his weight loss coaching programs for any of his clients for any
                                reason. In the unlikely event of this occurring, a partial, pro-rated refund will be
                                given solely for the remaining hours of your weight loss program that were not used
                                through coaching or missed appointments. For instance, if you signed up for the Silver
                                Coaching Program which consists of 20 hours of coaching, and you used 10 hours, did not
                                show up for your appointment for 2 of them (without having given 24 hours advance notice
                                for cancellation), you will be eligible for a pro-rated refund for the 8 hours you still
                                had available in your program. If you paid $2,000 for your weight loss coaching program,
                                which would equate to a $100. per session/ hour in this example, you would be eligible
                                to receive a pro-rated refund in the amount of $800, for example. </p>

                            <h3><u>
                                    <li>COACHING SESSIONS: STARTING AND ENDING TIMES</li>
                                </u></h3>
                            <p>All “hourly” coaching session consist of 55 minutes. Half hour (30 minute) coaching
                                sessions consist of 25 minutes. Coaching sessions will start promptly at the time that
                                has been agreed upon by both client and Anthony Wilson/ Anthony Wilson Consulting. If a
                                client should be unable to begin their session at the time specified and agreed upon,
                                their session will still end at the originally designated time without any refund or
                                additional time added to their program. Thus, if a client has an 8:00 pm – 9:00 pm
                                hourly coaching session appointment for their weight loss coaching program, and they
                                show up at 8:30 pm for their 8:00 pm appointment, they will have used up 1 full hourly
                                coaching session at the end of their session at 9:00 pm. Another example would be if a
                                client has an hourly coaching session that is to begin at 10:00 am, and they do not show
                                up for their coaching session until 9:45am. Their 'hourly' session will end promptly at
                                9:55 am, thus having used up one of their hourly coaching sessions from their
                                program. </p>

                            <h3><u>
                                    <li> WHAT TOPICS FROM THE WEIGHTLOSSHAPPENS.COM WEBSITE'S “COACHING PROGRAMS PAGE”
                                        ARE GUARANTEED TO BE COVERED DURING THE COACHING PROGRAM?
                                    </li>
                                </u></h3>
                            <p>Simply, we cover as many of the topics that are outlined on the website's 'Coaching
                                Programs' page as we can. We may cover every topic there or just a few of them. It
                                really just depends on where we collaboratively decide we want to spend the time
                                (hours). Clients usually need to spend more time on certain topics and sometimes do not
                                have a need for other topics. Therefore, there is no guarantee that all of the topics
                                listed on the 'Coaching Programs' page will be covered during your coaching program,
                                though our goal will certainly be to cover all of them unless you decide otherwise. </p>

                            <h3><u>
                                    <li>ALL COACHING PROGRAMS EXPIRATION TIMELINE:</li>
                                </u></h3>
                            <p>All programs, and their respective coaching sessions, will expire 1 year from the date of
                                purchase regardless of whether or not any or all of the weight loss coaching sessions
                                and services have been used. </p>

                            <h3><u>
                                    <li> DENIAL OF SIGN-UP FOR ANY COACHING PROGRAM:</li>
                                </u></h3>
                            <p>Anthony Wilson/ Anthony Wilson Consulting reserves the right to deny any individual the
                                opportunity to sign-up for and pay for any of his weight loss coaching programs for any
                                reason or no reason at all. If for some reason any individual whom he chooses not to
                                coach for any of his programs does sign up and pay for, in full or part, one of his
                                coaching programs, regardless of whether that individual has been notified in advance or
                                not as to being denied the opportunity to sign up for any of the coaching progams, the
                                individual will be given a full refund (minus any transactions fees) and no coaching
                                services will commence at any time. </p>
                        </ol>
                        <form onsubmit="return checkForm(this);" action="https://www.paypal.com/cgi-bin/webscr">
                            <input type="checkbox" name="terms"/> By checking this box you agree to the terms and
                            conditions of the TERMS OF SERVICE AGREEMENT <br/>
                            <p><input type="submit" class="margin-top-20" name="Submit" value="Submit"></p></form>
                    </div>
                </div>
            </div>
        </div>
    </div>
<?php } ?>



<!-------------------------Weight Loss Articles  page html start----------------------------------------->

<script type="text/javascript">

    function checkForm(form) {
        if (!form.terms.checked) {
            alert("Please indicate that you accept the Terms and Conditions");
            form.terms.focus();
            return false;
        }
        return true;
    }

</script>

<script>
    $(document).ready(function () {
        setpopup();
    });
    //setTimeout('setpopup()', 500);
    function setpopup() {

        if ($("#content_1").length > 0) {
            //$('#content_1').height(500);
            $("#content_1").mCustomScrollbar({
                scrollButtons: {
                    enable: true
                }
            });
        }
    }
</script>

