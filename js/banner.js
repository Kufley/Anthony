// JavaScript Document
  $(function() {
	if(window.location.host=='server')
		var siteurl=	"http://server/anthony-wilson-rd/";
else if(window.location.host=='www.weightlosshappens.com' || window.location.host=='weightlosshappens.com')
		var siteurl=	"http://www.weightlosshappens.com/";
	else
		var siteurl=	"http://antony.local/";

    $('#fadeshow1').crossSlide({

      sleep: 5,
      fade: 1
    }, [
      { src: siteurl+'images/slider/fad1.jpg'},
      { src: siteurl+'images/slider/fad11.jpg' },
      { src: siteurl+'images/slider/fad111.jpg' }
    ])


	$('#fadeshow2').crossSlide({
      sleep: 6,
      fade: 1
    }, [
      { src: siteurl+'images/slider/fad2.jpg' },
      { src: siteurl+'images/slider/fad22.jpg' },
      { src: siteurl+'images/slider/fad222.jpg' }
    ])

	$('#fadeshow3').crossSlide({
      sleep: 7,
      fade: 1
    }, [
      { src: siteurl+'images/slider/fad3.jpg' },
      { src: siteurl+'images/slider/fad33.jpg' },
      { src: siteurl+'images/slider/fad333.jpg' }
    ])


	$('#fadeshow4').crossSlide({
      sleep: 8,
      fade: 1
    }, [
      { src: siteurl+'images/slider/fad4.jpg' },
      { src: siteurl+'images/slider/fad44.jpg' },
      { src: siteurl+'images/slider/fad444.jpg' }
    ])

	$('#fadeshow5').crossSlide({
      sleep: 9,
      fade: 1
    }, [
      { src: siteurl+'images/slider/fad5.jpg' },
      { src: siteurl+'images/slider/fad55.jpg' },
      { src: siteurl+'images/slider/fad555.jpg' }
    ])

	$('#fadeshow6').crossSlide({
      sleep: 5,
      fade: 1
    }, [
      { src: siteurl+'images/slider/fad6.jpg' },
      { src: siteurl+'images/slider/fad66.jpg' },
      { src: siteurl+'images/slider/fad666.jpg' }
    ])

	$('#fadeshow7').crossSlide({
      sleep: 9,
      fade: 1
    }, [
      { src: siteurl+'images/slider/fad7.jpg' },
      { src: siteurl+'images/slider/fad77.jpg' },
      { src: siteurl+'images/slider/fad777.jpg' }
    ])

  });
