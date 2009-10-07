// ==UserScript==
// @name           hkgolden
// @namespace      amiwkc-4aadd81d4be80 
// @version        0.0.1
// @description    Shortcut to hkgolden
// @include        http://forum*.hkgolden.com/*
// @require        http://code.jquery.com/jquery-nightly.js
// ==/UserScript==
//
//

$(document).ready(
	function(){
		$("td.repliers_left a").hover(
			function(){
				var pattern=new RegExp("\d+");
				var uid=pattern.exec($(this).href);
				alert(uid);
				var str="<span><a href="+window.location.toString()+"&highlight_id="+uid+"</a></span>";
				$(this).append(str);
			},
			function(){
				$(this).find("span:last").remove();
			}
		);
	}
);


