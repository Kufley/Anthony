// JavaScript Document
 	  
  	function createDiv(newDivId,divType,zIndex,width100percent,height100percent,className){
		var H=$(document).height();
			
		//- ADDING A DIV TO BODY
		//alert(newDivId)
		var classNm=newDivId;
		
		if(typeof className!='undefined')
			classNm=(jQuery.trim(className)=='')?newDivId:className;
		
			
		if(!$('#'+newDivId).length)
			$("body").append('<div id="'+newDivId+'" class="'+classNm+'"></div>');	
	  	//else
			//alert(newDivId+' div already exist.');
		
		if(divType=='fade'){
			if(width100percent && height100percent)
				$('#'+newDivId).css({'height':H+'px','width':'100%','opacity':.7,'z-index':zIndex});
			else if(!width100percent && height100percent)
				$('#'+newDivId).css({'height':H+'px','opacity':.7,'z-index':zIndex});
			else if(width100percent && !height100percent)	
				$('#'+newDivId).css({'width':'100%','opacity':.7,'z-index':zIndex});
			else if(!width100percent && !height100percent)	
				$('#'+newDivId).css({'opacity':.7,'z-index':zIndex});
		}else{
			$('#'+newDivId).css({'z-index':zIndex});
		}
	} 

	function removeDiv(divId){
		if($('#'+divId).length)	
			$('#'+divId).remove();
		
	} 
  
	function pleaseWaitHtml(divName){
		return '<div class="'+divName+'">Please Wait...</div>';
	}
  
  	function dGetScreenWH(){
		var dW=0;
		var dH=0;
		 // the more standards compliant browsers (mozilla/netscape/opera/IE7) use window.innerWidth and window.innerHeight
		 
		 if (typeof window.innerWidth != 'undefined')
		 {
			  dW = window.innerWidth,
			  dH = window.innerHeight
		 }
		 
		// IE6 in standards compliant mode (i.e. with a valid doctype as the first line in the document)
		
		 else if (typeof document.documentElement != 'undefined'
			 && typeof document.documentElement.clientWidth !=
			 'undefined' && document.documentElement.clientWidth != 0)
		 {
			   dW = document.documentElement.clientWidth,
			   dH = document.documentElement.clientHeight
		 }
		 
		 var dWH=[{'dWidth':dW,'dHeight':dH}];
		// dWH['dWidth']=dW;
		 //dWH['dHeight']=dH;
	
		return dWH[0];
	 
	}

	function dDisplayDivInCenter(divId,adjustWidth,adjustHeight){
  		
		//var availH=window.screen.availHeight;
		var WH=dGetScreenWH();
		//alert(WH.dWidth+'-'+WH.dHeight);
 		var availH=WH.dHeight;
		var availW=WH.dWidth;
				
		var divH=$('#'+divId).height();
		var divW=$('#'+divId).width();
		
		var T;var L;
		
		//var passedWidth=parseInt(adjustWidth);
		//var passedHeight=parseInt(adjustHeight);
		
		if(divH>=availH)
			T=25;
		else	
			T=(availH-divH)/2;
		var L=(availW-divW)/2;
		
		//T=T-passedHeight;
		//L=L+passedWidth;
		
		$('#'+divId).css({'top':T+'px','left':L+'px'});
  	}
  
  function dWidthCenter(divId,adjustWidth,adjustHeight){
  		//alert('sdfsd');
		//var availH=window.screen.availHeight;
		// ==========================================================
		//var availW=window.screen.availWidth;
		
		var WH=dGetScreenWH();
		var availW=WH.dWidth;
		//========================================================
		//var divH=$('#'+divId).height();
		var divW=$('#'+divId).width();
		
		var T=adjustHeight;
		var L=(availW-divW)/2;
		
		//T=T-parseInt(adjustHeight);
		L=L+parseInt(adjustWidth);
		//alert(divH);	
		$('#'+divId).css({'top':T+'px','left':L+'px'});
  	}
  
  function dSetCookie(c_name,value,exdays){
		//document.cookie = name + "=" + value;
		var exdate=new Date();
		exdate.setDate(exdate.getDate() + exdays);
		var c_value=escape(value) + ((exdays==null) ? "" : "; expires="+exdate.toUTCString());
		document.cookie=c_name + "=" + c_value;
		
		
	}
	function dGetCookie(c_name){ 
	
	var i,x,y,ARRcookies=document.cookie.split(";");
		for (i=0;i<ARRcookies.length;i++){
			x=ARRcookies[i].substr(0,ARRcookies[i].indexOf("="));
			y=ARRcookies[i].substr(ARRcookies[i].indexOf("=")+1);
			x=x.replace(/^\s+|\s+$/g,"");
			if (x==c_name){
				return unescape(y);
			}
		}
	
		//var re=new RegExp(Name+"=[^;]+", "i") 
//		if (document.cookie.match(re)) //if cookie found
//			return document.cookie.match(re)[0].split("=")[1] //return its value
//		return null
	}
	
	
	function dTextOnFocus(ifText,replaceWith,txtId){
		if(jQuery.trim($('#'+txtId).val())==ifText){
			$('#'+txtId).val(replaceWith);
		}
 	}
 
 function dTextOnBlur(ifText,replaceWith,txtId){
		
		if(jQuery.trim($('#'+txtId).val())==ifText || jQuery.trim($('#'+txtId).val())==''){
			$('#'+txtId).val(replaceWith);
		}
 	}
	