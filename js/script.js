// JavaScript Document


( function( $ ) {
$( document ).ready(function() {
// Cache the elements we'll need
var menu = $('.top_nav');
var menuList = menu.find('ul:first');
var listItems = menu.find('li').not('#responsive-tab');

// Create responsive trigger
menuList.prepend('<li id="responsive-tab"><a href="#">Menu</a></li>');

// Toggle menu visibility
menu.on('click', '#responsive-tab', function(){  
	listItems.slideToggle('fast');
	listItems.addClass('collapsed');
});
});
} )( jQuery );


$(document).ready(function () {

    $("#owl-demo").owlCarousel({
        items: 1,
        lazyLoad: true,
        navigation: true,
        autoPlay: 60000,
        slideSpeed:45000,
        itemsDesktop: [1200, 1],
        itemsDesktopSmall: [992, 1],
        itemsTablet: [768, 1],
        itemsTabletSmall: [639, 1],
        itemsMobile: [479, 1],
    });

});

$(function() {
  $('a[href*="#"]:not([href="#"])').click(function() {
    if (location.pathname.replace(/^\//,'') == this.pathname.replace(/^\//,'') && location.hostname == this.hostname) {
      var target = $(this.hash);
      target = target.length ? target : $('[name=' + this.hash.slice(1) +']');
      if (target.length) {
        $('html, body').animate({
          scrollTop: target.offset().top
        }, 1000);
        return false;
      }
    }
  });
});
