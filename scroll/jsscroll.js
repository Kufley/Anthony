var scrollIncrement = 15;

var blockTrackClick = false;
var scrollInterval;
var scrollHoldInterval = 250;
var activeScrollArea = null;
var activeScrollResetTimer;



function SetScrollAreaActive(elem)
{
	
	clearTimeout(activeScrollResetTimer);
	activeScrollArea = elem;
}

function SetScrollAreaInactive(elem)
{
	activeScrollResetTimer = setTimeout("activeScrollArea = null", 100);
}

function StartScrollUp(elem)
{
	ScrollUp(elem);
	scrollInterval = setInterval("ScrollUp('" + elem + "');", scrollHoldInterval);
}

function StartScrollDown(elem)
{
	ScrollDown(elem);
	scrollInterval = setInterval("ScrollDown('" + elem + "');", scrollHoldInterval);
}

function StopScroll()
{
	clearInterval(scrollInterval);
}

function ScrollUp(elem)
{
	var scrollPos = GetTopScrollAmount(elem) + scrollIncrement;
	if (scrollPos > 0) scrollPos = 0;
	document.getElementById(elem + "_ScrollingArea").style.top = scrollPos + "px";
	
	SetScrollBarPercentage(elem, GetScrollPercentage(elem));
}

function ScrollDown(elem)
{
	//alert("HI"+elem) ;
	var scrollPos = GetTopScrollAmount(elem) - scrollIncrement;
	
	scrollHeight = GetScrollHeight(elem);
	//alert(elem + "_ScrollingArea");
	
	//alert(scrollPos);
	if (scrollPos < (-1 * scrollHeight)) scrollPos = (-1 * scrollHeight);
	document.getElementById(elem + "_ScrollingArea").style.top = scrollPos + "px";
	
	SetScrollBarPercentage(elem, GetScrollPercentage(elem));
}

function ScrollBarTrackClick(elem, event)
{
	if (blockTrackClick) return;
	
	var y, yMove;
	
	if (browser.isIE)
		y = window.event.clientY + document.documentElement.scrollTop  + document.body.scrollTop;
	if (browser.isNS)
		y = event.clientY + window.scrollY;
	
	if (y > GetPosY(document.getElementById(elem + "_Gripper")))
	{
		ScrollDown(elem);
		ScrollDown(elem);
	}
	else
	{
		ScrollUp(elem);
		ScrollUp(elem);
	}
}

function GetTopScrollAmount(elem)
{
	return GetPosY(document.getElementById(elem + "_ScrollingArea")) - GetPosY(document.getElementById(elem + "_Content"));
}

function GetScrollHeight(elem)
{
	return document.getElementById(elem + "_ScrollingArea").offsetHeight - document.getElementById(elem + "_Content").offsetHeight;
}

function GetTrackDistance(elem)
{
	return document.getElementById(elem + "_GripperContainer").offsetHeight - document.getElementById(elem + "_Gripper").offsetHeight;
}

function GetGripperPosition(elem)
{
	return GetPosY(document.getElementById(elem + "_Gripper")) - GetPosY(document.getElementById(elem + "_GripperContainer"));
}

function GetScrollBarPercentage(elem)
{
	var topOffset = GetGripperPosition(elem);
	var trackDistance = GetTrackDistance(elem);
	
	return topOffset / trackDistance;
}

function SetScrollBarPercentage(elem, percentage)
{
	GetTrackDistance(elem)
	
	document.getElementById(elem + "_Gripper").style.top = Math.floor(GetTrackDistance(elem) * percentage) + "px";
}

function GetScrollPercentage(elem)
{
	return -1 * (GetTopScrollAmount(elem) / GetScrollHeight(elem));
}

function SetScrollPercentage(elem, percentage)
{
	document.getElementById(elem + "_ScrollingArea").style.top = (-1 * Math.floor(GetScrollHeight(elem) * percentage)) + "px";
}

function SetScrollbarHeight(elem)
{
	var visiblePercentage = document.getElementById(elem + "_Content").offsetHeight / document.getElementById(elem + "_ScrollingArea").offsetHeight;
	
		
	if (visiblePercentage > 1)
		visiblePercentage = 1;
	
	var gripperHeight = Math.floor(document.getElementById(elem + "_GripperContainer").offsetHeight * visiblePercentage);
	
	if (gripperHeight < 20)
		gripperHeight = 20;
	
	document.getElementById(elem + "_Gripper").style.height = gripperHeight + "px";
}

function GetPosX(obj)
{
	var curleft = 0;
	if (obj.offsetParent)
	{
		while (obj.offsetParent) 
		{
			curleft += obj.offsetLeft
			obj = obj.offsetParent;
		}
	}
	else if (obj.x)
		curleft += obj.x;

	return curleft;
}

function GetPosY(obj)
{
	var curtop = 0;
	if (obj.offsetParent)
	{
		while (obj.offsetParent)
		{
			curtop += obj.offsetTop
			obj = obj.offsetParent;
		}
	}
	else if (obj.y)
		curtop += obj.y;

	return curtop;
}

//*****************************************************************************
// Javascript Mouse Wheel handling code - based on an article by:
// http://adomas.org/javascript-mouse-wheel/
//*****************************************************************************

function handleMouseWheelScroll(scrollDelta)
{
	var safety = 0;
	
	if (scrollDelta < 0)
	{
		for (var x=0; x > scrollDelta && safety < 3; x--)
		{
			ScrollDown(activeScrollArea);
			safety++;
		}
	}
	
	if (scrollDelta > 0)
	{
		for (var x=0; x < scrollDelta && safety < 3; x++)
		{
			ScrollUp(activeScrollArea);
			safety++;
		}
	}
	
}

function mouseWheelActive(event)
{
	if (activeScrollArea == null)
		return;
	
	var delta = 0;
	if (!event) event = window.event;
	if (event.wheelDelta) {
		delta = event.wheelDelta/120; 
		if (window.opera) delta = -delta;
	} else if (event.detail) {
		delta = -event.detail/4;
	}
	if (delta)
		handleMouseWheelScroll(delta);
        if (event.preventDefault)
                event.preventDefault();
        event.returnValue = false;
}

if (window.addEventListener)
	window.addEventListener('DOMMouseScroll', mouseWheelActive, false);
window.onmousewheel = document.onmousewheel = mouseWheelActive;

//*****************************************************************************
// Do not remove this notice.
//
// Copyright 2001 by Mike Hall.
// Modified to bound allowable drag area to relative parent by Adam Hamilton.
//*****************************************************************************

// Determine browser and version.

function Browser() {

  var ua, s, i;

  this.isIE    = false;
  this.isNS    = false;
  this.version = null;

  ua = navigator.userAgent;

  s = "MSIE";
  if ((i = ua.indexOf(s)) >= 0) {
    this.isIE = true;
    this.version = parseFloat(ua.substr(i + s.length));
    return;
  }

  s = "Netscape6/";
  if ((i = ua.indexOf(s)) >= 0) {
    this.isNS = true;
    this.version = parseFloat(ua.substr(i + s.length));
    return;
  }

  // Treat any other "Gecko" browser as NS 6.1.

  s = "Gecko";
  if ((i = ua.indexOf(s)) >= 0) {
    this.isNS = true;
    this.version = 6.1;
    return;
  }
}

var browser = new Browser();

// Global object to hold drag information.

var dragObj = new Object();
dragObj.zIndex = 0;

function ScrollBarDragStart(event, id) {
	
	//alert(id) ;

  blockTrackClick = true;

  var el;
  var x, y;

  // If an element id was given, find it. Otherwise use the element being
  // clicked on.

  if (id)
    dragObj.elNode = document.getElementById(id);
  else {
    if (browser.isIE)
      dragObj.elNode = window.event.srcElement;
    if (browser.isNS)
      dragObj.elNode = event.target;

    // If this is a text node, use its parent element.

    if (dragObj.elNode.nodeType == 3)
      dragObj.elNode = dragObj.elNode.parentNode;
  }

  // Get cursor position with respect to the page.

  if (browser.isIE) {
    x = window.event.clientX + document.documentElement.scrollLeft
      + document.body.scrollLeft;
    y = window.event.clientY + document.documentElement.scrollTop
      + document.body.scrollTop;
  }
  if (browser.isNS) {
    x = event.clientX + window.scrollX;
    y = event.clientY + window.scrollY;
  }

  // Save starting positions of cursor and element.

  dragObj.cursorStartX = x;
  dragObj.cursorStartY = y;
  dragObj.elStartLeft  = parseInt(dragObj.elNode.style.left, 10);
  dragObj.elStartTop   = parseInt(dragObj.elNode.style.top,  10);

  if (isNaN(dragObj.elStartLeft)) dragObj.elStartLeft = 0;
  if (isNaN(dragObj.elStartTop))  dragObj.elStartTop  = 0;

  // Update element's z-index.

  dragObj.elNode.style.zIndex = ++dragObj.zIndex;

  // Capture mousemove and mouseup events on the page.

  if (browser.isIE) {
    document.attachEvent("onmousemove", ScrollBarDragGo);
    document.attachEvent("onmouseup",   ScrollBarDragStop);
    window.event.cancelBubble = true;
    window.event.returnValue = false;
  }
  if (browser.isNS) {
    document.addEventListener("mousemove", ScrollBarDragGo,   true);
    document.addEventListener("mouseup",   ScrollBarDragStop, true);
    event.preventDefault();
  }
}

function ScrollBarDragGo(event) {

  var x, y; //alert("jkjl") ;

  // Get cursor position with respect to the page.

  if (browser.isIE) {
    x = window.event.clientX + document.documentElement.scrollLeft
      + document.body.scrollLeft;
    y = window.event.clientY + document.documentElement.scrollTop
      + document.body.scrollTop;
  }
  if (browser.isNS) {
    x = event.clientX + window.scrollX;
    y = event.clientY + window.scrollY;
  }
  
  // Bound the movement of the element to within it's parent
  var ctx, cty, mtx, mty; //, cbx, cby;
  
  ctx = dragObj.elStartLeft + x - dragObj.cursorStartX;
  cty = dragObj.elStartTop  + y - dragObj.cursorStartY;
  
  mtx = dragObj.elNode.parentNode.offsetWidth  - dragObj.elNode.offsetWidth;
  mty = dragObj.elNode.parentNode.offsetHeight - dragObj.elNode.offsetHeight;
  
  if (ctx > mtx) ctx = mtx;
  if (ctx < 0) ctx = 0;
  
  if (cty > mty) cty = mty;
  if (cty < 0) cty = 0;  

  // Move drag element by the same amount the cursor has moved.

  dragObj.elNode.style.left = (ctx) + "px";
  dragObj.elNode.style.top  = (cty) + "px";

  if (browser.isIE) {
    window.event.cancelBubble = true;
    window.event.returnValue = false;
  }
  if (browser.isNS)
    event.preventDefault();
   
  var elemName = dragObj.elNode.id.split('_')[0];
  SetScrollPercentage(elemName, GetScrollBarPercentage(elemName));
}

function ScrollBarDragStop(event) {

  setTimeout("blockTrackClick = false;", 100);

  // Stop capturing mousemove and mouseup events.

  if (browser.isIE) {
    document.detachEvent("onmousemove", ScrollBarDragGo);
    document.detachEvent("onmouseup",   ScrollBarDragStop);
  }
  if (browser.isNS) {
    document.removeEventListener("mousemove", ScrollBarDragGo,   true);
    document.removeEventListener("mouseup",   ScrollBarDragStop, true);
  }
}