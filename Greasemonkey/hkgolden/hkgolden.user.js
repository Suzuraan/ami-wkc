// ==UserScript==
// @name           hkgolden
// @namespace      amiwkc-4aadd81d4be80 
// @version        0.0.1
// @description    Shortcut to hkgolden
// @include        http://forum*.hkgolden.com/*
// @require        http://code.jquery.com/jquery-nightly.js
// ==/UserScript==
//
$("td.repliers_left").hover(
	function(){
		var uid=/\d+/.exec($(this).find("a:first").attr("href"));
		var str='<tr><td class="font-size:10%;text-align:center;"><a href="'+window.location.toString()+'&highlight_id='+uid+'">highlight</a></td></tr>';
		$(this).find("table").append(str);
	},
	function(){
		$(this).find("table tr:last").remove();
	}
);


