(function(_){/* 
 
 Copyright The Closure Library Authors. 
 SPDX-License-Identifier: Apache-2.0 
*/ 
'use strict';var ea,fa,ka,ma,A,va,wa,xa,Aa,Ia,Ma,Ra,$a,ab,bb,db,fb,ib,kb,nb,pb,ob,qb,rb,vb,wb,Cb,Db,Gb,Ib,Jb,Lb,Ob,Pb,Rb,Ub,Vb,Wb,Xb,Yb,ac,bc,dc,hc,fc,ic,mc,oc,qc,uc,Bc,Ec;_.ca=function(a){return function(){return _.aa[a].apply(this,arguments)}};_.r=function(a,b,c){a=a.split(".");c=c||_.q;a[0]in c||"undefined"==typeof c.execScript||c.execScript("var "+a[0]);for(var d;a.length&&(d=a.shift());)a.length||void 0===b?c[d]&&c[d]!==Object.prototype[d]?c=c[d]:c=c[d]={}:c[d]=b};_.da=function(){}; 
ea=function(a,b,c){return a.call.apply(a.bind,arguments)};fa=function(a,b,c){if(!a)throw Error();if(2<arguments.length){var d=Array.prototype.slice.call(arguments,2);return function(){var e=Array.prototype.slice.call(arguments);Array.prototype.unshift.apply(e,d);return a.apply(b,e)}}return function(){return a.apply(b,arguments)}};_.t=function(a,b,c){Function.prototype.bind&&-1!=Function.prototype.bind.toString().indexOf("native code")?_.t=ea:_.t=fa;return _.t.apply(null,arguments)}; 
_.w=function(a,b){var c=Array.prototype.slice.call(arguments,1);return function(){var d=c.slice();d.push.apply(d,arguments);return a.apply(this,d)}};_.ia=function(){return Date.now()};_.x=function(a,b){function c(){}c.prototype=b.prototype;a.T=b.prototype;a.prototype=new c;a.prototype.constructor=a;a.Tb=function(d,e,f){for(var g=Array(arguments.length-2),h=2;h<arguments.length;h++)g[h-2]=arguments[h];return b.prototype[e].apply(d,g)}};ka=function(a){let b=!1,c;return function(){b||(c=a(),b=!0);return c}}; 
_.la=function(a,b){return Array.prototype.indexOf.call(a,b,void 0)};ma=function(a,b){Array.prototype.forEach.call(a,b,void 0)};_.na=function(a,b){b=_.la(a,b);let c;(c=0<=b)&&Array.prototype.splice.call(a,b,1);return c};_.oa=function(a){const b=a.length;if(0<b){const c=Array(b);for(let d=0;d<b;d++)c[d]=a[d];return c}return[]};_.pa=function(a){return a instanceof _.y&&a.constructor===_.y?a.g:"type_error:SafeUrl"};A=function(a){return-1!=qa.indexOf(a)}; 
_.sa=function(a){return a instanceof _.ra&&a.constructor===_.ra?a.g:"type_error:SafeHtml"};va=function(a,b){b instanceof _.y||b instanceof _.y||(b="object"==typeof b&&b.X?b.W():String(b),ta.test(b)||(b="about:invalid#zClosurez"),b=new _.y(b,_.ua));a.href=_.pa(b)};wa=function(){return A("iPhone")&&!A("iPod")&&!A("iPad")};xa=function(a){xa[" "](a);return a};_.ya=function(a,b){try{return xa(a[b]),!0}catch(c){}return!1};Aa=function(a){Array.isArray(a)&&!Object.isFrozen(a)&&(a[za]=!0);return a};_.Ba=function(){}; 
_.Fa=function(a,b,c){a.g=null;Ca&&(b||(b=Ca),Ca=null);var d=a.constructor.Ub;b||(b=d?[d]:[]);a.l=d?0:-1;a.h=b;a:{if(b=a.h.length)if(--b,d=a.h[b],!(null===d||"object"!=typeof d||Array.isArray(d)||Da&&d instanceof Uint8Array)){a.v=b-a.l;a.j=d;break a}a.v=Number.MAX_VALUE}a.A={};if(c)for(b=0;b<c.length;b++)if(d=c[b],d<a.v){d+=a.l;var e=a.h[d];e?Aa(e):a.h[d]=Ea}else e=a.v+a.l,a.h[e]||(a.j=a.h[e]={}),(e=a.j[d])?Aa(e):a.j[d]=Ea}; 
_.Ga=function(a,b){if(b<a.v){b+=a.l;var c=a.h[b];return c!==Ea?c:a.h[b]=Aa([])}if(a.j)return c=a.j[b],c!==Ea?c:a.j[b]=Aa([])};_.B=function(a,b,c){a=_.Ga(a,b);return null==a?c:a};_.D=function(a,b){return _.B(a,b,"")};_.F=function(a,b){a=_.Ga(a,b);a=null==a?a:!!a;return null==a?!1:a};_.Ha=function(a,b,c){a.g||(a.g={});if(!a.g[c]){let d=_.Ga(a,c);d&&(a.g[c]=new b(d))}return a.g[c]}; 
Ia=function(a,b,c){a.g||(a.g={});if(!a.g[c]){let d=_.Ga(a,c),e=[];for(let f=0;f<d.length;f++)e[f]=new b(d[f]);a.g[c]=e}b=a.g[c];b==Ea&&(b=a.g[c]=[]);return b};_.Ka=function(a){if(a.g)for(var b in a.g){var c=a.g[b];if(Array.isArray(c))for(var d=0;d<c.length;d++)c[d]&&_.Ka(c[d]);else c&&_.Ka(c)}return a.h};Ma=function(a){return Ia(a,_.La,1)}; 
_.Na=function(a,b){if(!a||/[?&]dsh=1(&|$)/.test(a))return null;if(/[?&]ae=1(&|$)/.test(a)){var c=/[?&]adurl=([^&]+)/.exec(a);if(!c)return null;b=b?c.index:a.length;try{return{sa:a.slice(0,b)+"&act=1"+a.slice(b),I:decodeURIComponent(c[1])}}catch(d){return null}}if(/[?&]ae=2(&|$)/.test(a)){c=a;let d="";b&&(b=a.indexOf("&adurl="),0<b&&(c=a.slice(0,b),d=a.slice(b)));return{sa:`${c}&act=1${d}`,I:`${c}&dct=1${d}`}}return null}; 
_.Qa=function(a){if(a instanceof Oa)if(a instanceof Pa)a=a.g;else throw Error("wrong type");else a=_.pa(a);return a};_.I=function(a,b,c){a.addEventListener&&a.addEventListener(b,c,!1)};Ra=function(a,b){this.x=void 0!==a?a:0;this.y=void 0!==b?b:0};_.Sa=function(a,b){b=String(b);"application/xhtml+xml"===a.contentType&&(b=b.toLowerCase());return a.createElement(b)}; 
_.Ta=function(a,b,c,d,e,f,g){var h="";a&&(h+=a+":");c&&(h+="//",b&&(h+=b+"@"),h+=c,d&&(h+=":"+d));e&&(h+=e);f&&(h+="?"+f);g&&(h+="#"+g);return h};_.Ua=function(a){var b=a.indexOf("#");0>b&&(b=a.length);var c=a.indexOf("?");if(0>c||c>b){c=b;var d=""}else d=a.substring(c+1,b);return[a.substr(0,c),d,a.substr(b)]};_.Va=function(a,b){return b?a?a+"&"+b:b:a};_.Wa=function(a,b){if(!b)return a;a=_.Ua(a);a[1]=_.Va(a[1],b);return a[0]+(a[1]?"?"+a[1]:"")+a[2]}; 
_.Xa=function(a,b,c){if(Array.isArray(b))for(var d=0;d<b.length;d++)_.Xa(a,String(b[d]),c);else null!=b&&c.push(a+(""===b?"":"="+encodeURIComponent(String(b))))};_.Ya=function(a){var b=[],c;for(c in a)_.Xa(c,a[c],b);return b.join("&")};_.Za=function(a,b){b=_.Ya(b);return _.Wa(a,b)};$a=function(a){try{return!!a&&null!=a.location.href&&_.ya(a,"foo")}catch(b){return!1}};ab=function(a,b){if(a)for(const c in a)Object.prototype.hasOwnProperty.call(a,c)&&b.call(void 0,a[c],c,a)}; 
_.cb=function(a,b,c=null){bb(a,b,c)};bb=function(a,b,c){a.google_image_requests||(a.google_image_requests=[]);const d=a.document.createElement("img");if(c){const e=f=>{c&&c(f);d.removeEventListener&&d.removeEventListener("load",e,!1);d.removeEventListener&&d.removeEventListener("error",e,!1)};_.I(d,"load",e);_.I(d,"error",e)}d.src=b;a.google_image_requests.push(d)};db=function(a,b=null){return b&&b.getAttribute("data-jc")===String(a)?b:document.querySelector(`[${"data-jc"}="${a}"]`)}; 
fb=function(a){return new eb(b=>b.substr(0,a.length+1).toLowerCase()===a+":")};ib=function(a,b=gb){for(let c=0;c<b.length;++c){const d=b[c];if(d instanceof eb&&d.Ua(a))return new Pa(a)}};kb=function(a,b=gb){return ib(a,b)||jb};_.lb=function(a,b,c){if(a instanceof _.y)return a;c=kb(a,c);c===jb&&b(a);return new _.y(_.Qa(c),_.ua)};nb=function(a,b){const c={};c[a]=b;return[c]};pb=function(a,b,c,d,e){const f=[];ab(a,function(g,h){(g=ob(g,b,c,d,e))&&f.push(h+"="+g)});return f.join(b)}; 
ob=function(a,b,c,d,e){if(null==a)return"";b=b||"&";c=c||",$";"string"==typeof c&&(c=c.split(""));if(a instanceof Array){if(d=d||0,d<c.length){const f=[];for(let g=0;g<a.length;g++)f.push(ob(a[g],b,c,d+1,e));return f.join(c[d])}}else if("object"==typeof a)return e=e||0,2>e?encodeURIComponent(pb(a,b,c,d,e+1)):"...";return encodeURIComponent(String(a))};qb=function(a){let b=1;for(const c in a.h)b=c.length>b?c.length:b;return 3997-b-a.j.length-1}; 
rb=function(a,b,c){b=b+"//pagead2.googlesyndication.com"+c;let d=qb(a)-c.length;if(0>d)return"";a.g.sort(function(f,g){return f-g});c=null;let e="";for(let f=0;f<a.g.length;f++){const g=a.g[f],h=a.h[g];for(let k=0;k<h.length;k++){if(!d){c=null==c?g:c;break}let m=pb(h[k],a.j,",$");if(m){m=e+m;if(d>=m.length){d-=m.length;b+=m;e=a.j;break}c=null==c?g:c}}}a="";null!=c&&(a=e+"trn="+c);return b+a}; 
_.tb=function(a,b,c,d,e,f){if((d?a.g:Math.random())<(e||.01))try{let g;c instanceof sb?g=c:(g=new sb,ab(c,(k,m)=>{var p=g,n=p.l++;k=nb(m,k);p.g.push(n);p.h[n]=k}));const h=rb(g,a.h,"/pagead/gen_204?id="+b+"&");h&&("undefined"!==typeof f?_.cb(_.q,h,f):_.cb(_.q,h))}catch(g){}};vb=function(a){a&&J&&ub()&&(J.clearMarks(`goog_${a.label}_${a.uniqueId}_start`),J.clearMarks(`goog_${a.label}_${a.uniqueId}_end`))}; 
wb=function(a){let b=a.toString();a.name&&-1==b.indexOf(a.name)&&(b+=": "+a.name);a.message&&-1==b.indexOf(a.message)&&(b+=": "+a.message);if(a.stack){a=a.stack;try{-1==a.indexOf(b)&&(a=b+"\n"+a);let c;for(;a!=c;)c=a,a=a.replace(/((https?:\/..*\/)[^\/:]*:\d+(?:.|\n)*)\2/,"$1");b=a.replace(/\n */g,"\n")}catch(c){}}return b}; 
_.yb=function(a,b,c){let d,e;try{a.g&&a.g.g?(e=a.g.start(b.toString(),3),d=c(),a.g.end(e)):d=c()}catch(f){c=!0;try{vb(e),c=a.v(b,new xb(f,{message:wb(f)}),void 0,void 0)}catch(g){a.xa(217,g)}if(c){let g,h;null==(g=window.console)||null==(h=g.error)||h.call(g,f)}else throw f;}return d};Cb=function(a){const {$:b,fa:c}=_.zb(a.href);va(a,_.lb(b,_.Ab(599),Bb));return c}; 
Db=function(a,b,c=-1){if(b)if(300>Date.now()-c)a=!1;else if(b=a.getAttribute("data-orig-async-clicktrack-url")){const {$:d,fa:e}=_.zb(b);va(a,_.lb(d,_.Ab(599),Bb));a=e}else a.setAttribute("data-orig-async-clicktrack-url",a.href),a=Cb(a);else a=Cb(a);return a};_.zb=function(a){const b=_.Na(a,!0);return b?navigator.sendBeacon?navigator.sendBeacon(_.Eb(b.sa,"&ri=1"),"")?{$:b.I,fa:!0}:{$:_.Eb(a,"&ri=2"),fa:!1}:{$:_.Eb(a,"&ri=16"),fa:!1}:{$:a,fa:!1}}; 
_.Eb=function(a,b){const c=a.search(/&adurl=/);return 0>c?a+b:a.slice(0,c)+b+a.slice(c)};_.Fb=function(a){return null!=a&&-1===a.indexOf("dbm/clk")&&null!==_.Na(a)};Gb=function(a){return _.Fb(a.href)||(a.getAttribute("data-orig-async-clicktrack-url")?_.Fb(a.getAttribute("data-orig-async-clicktrack-url")):!1)};Ib=function(a,b,c){let d=b=b.getAttribute("data-original-click-url");if(d)for(let e=0;e<a.D.length;e++)d=Hb(d,b,a.D[e],c);return d};Jb=function(a,b=Date.now()){return b-a.A>_.B(a.g,39,0)}; 
Lb=function(a,b){-1===b.href.indexOf("dbm/clk")&&(Gb(b)||_.F(a.g,38))&&_.yb(_.Kb,446,()=>{const c=Date.now();Jb(a,c)&&Db(b,_.F(a.g,45),a.A)&&(a.A=c)})}; 
Ob=function(a,b,c,d){if(0!=a.v.length&&(d.preventDefault?!d.defaultPrevented:!1!==d.returnValue)){var e=1==d.which&&!d.ctrlKey&&"_blank"!=b.target&&"_new"!=b.target;e&&_.Mb(d);var f=[];for(let g=0;g<a.v.length;g++){const h=a.v[g](c);if(h){const k=new Promise(m=>{_.cb(_.K,h,m)});f.push(k)}}c=Promise.all(f);f=new Promise(g=>{window.setTimeout(g,2E3)});e&&Promise.race([c,f]).then((0,_.t)(Nb.prototype.da,a,b,d))}}; 
Pb=function(a,b,c){const d=b.href;if(a.j){const e=Date.now(),f=Jb(a,e);if(a.j.g(b,c,a.g,a.B,f))return f&&(a.A=e),!0}else if(_.q.googdlu&&(_.q.googdlu.tryOpenPlayStore&&_.q.googdlu.tryOpenPlayStore(c,d,_.D(a.g,15))||_.q.googdlu.tryOpenItunesStore&&_.q.googdlu.tryOpenItunesStore(c,d,_.D(a.g,15),_.F(a.g,42),_.F(a.g,43),_.D(a.l,7),_.D(a.l,8))))return!0;return _.F(a.g,31)&&_.F(a.g,30)&&_.D(a.g,28)&&_.q.googdlu&&_.q.googdlu.tryOpenAppUrl?(_.q.googdlu.tryOpenAppUrl(c,d,_.D(a.g,32),_.D(a.g,28)),!0):!1}; 
Rb=function(a,b,c,d){if(a.j){const e=Jb(a,Date.now());Ia(a.l,Qb,23);return a.j.h(b,c,a.g,a.B,e,d)}return new Promise(e=>{e(!1)})};Ub=function(a,b,c){const d=Ia(a.l,Qb,23);Sb(d)&&(_.Tb.ga().g.avoid_appify_double_billing=!0);a.j&&2===a.H?(_.Mb(c),Rb(a,b,c,a.H).then(e=>{e||Lb(a,b)})):Pb(a,b,c)||Lb(a,b)};Vb=function(a,b,c,d){a.h[d]||(a.h[d]={});a.h[d][c]||(a.h[d][c]=[]);_.I(b,d,(0,_.t)(a.V,a,b,c,d))}; 
Wb=function(a){return"string"==typeof a.className?a.className:a.getAttribute&&a.getAttribute("class")||""};Xb=function(a,b){"string"==typeof a.className?a.className=b:a.setAttribute&&a.setAttribute("class",b)};Yb=function(a,b){a.classList?b=a.classList.contains(b):(a=a.classList?a.classList:Wb(a).match(/\S+/g)||[],b=0<=_.la(a,b));return b};_.Zb=function(a,b){if(a.classList)a.classList.add(b);else if(!Yb(a,b)){var c=Wb(a);Xb(a,c+(0<c.length?" "+b:b))}}; 
_.$b=function(a,b){a.classList?a.classList.remove(b):Yb(a,b)&&Xb(a,Array.prototype.filter.call(a.classList?a.classList:Wb(a).match(/\S+/g)||[],function(c){return c!=b}).join(" "))}; 
ac=function(){var a=_.q.MessageChannel;"undefined"===typeof a&&"undefined"!==typeof window&&window.postMessage&&window.addEventListener&&!A("Presto")&&(a=function(){var e=_.Sa(document,"IFRAME");e.style.display="none";document.documentElement.appendChild(e);var f=e.contentWindow;e=f.document;e.open();e.close();var g="callImmediate"+Math.random(),h="file:"==f.location.protocol?"*":f.location.protocol+"//"+f.location.host;e=(0,_.t)(function(k){if(("*"==h||k.origin==h)&&k.data==g)this.port1.onmessage()}, 
this);f.addEventListener("message",e,!1);this.port1={};this.port2={postMessage:function(){f.postMessage(g,h)}}});if("undefined"!==typeof a&&!A("Trident")&&!A("MSIE")){var b=new a,c={},d=c;b.port1.onmessage=function(){if(void 0!==c.next){c=c.next;var e=c.Ja;c.Ja=null;e()}};return function(e){d.next={Ja:e};d=d.next;b.port2.postMessage(0)}}return function(e){_.q.setTimeout(e,0)}};bc=function(a){_.q.setTimeout(()=>{throw a;},0)}; 
dc=function(){var a=cc;let b=null;a.g&&(b=a.g,a.g=a.g.next,a.g||(a.h=null),b.next=null);return b};hc=function(a){ec||fc();gc||(ec(),gc=!0);cc.add(a,void 0)};fc=function(){if(_.q.Promise&&_.q.Promise.resolve){var a=_.q.Promise.resolve(void 0);ec=function(){a.then(ic)}}else ec=function(){var b=ic;"function"!==typeof _.q.setImmediate||_.q.Window&&_.q.Window.prototype&&!A("Edge")&&_.q.Window.prototype.setImmediate==_.q.setImmediate?(jc||(jc=ac()),jc(b)):_.q.setImmediate(b)}}; 
ic=function(){for(var a;a=dc();){try{a.h.call(a.g)}catch(c){bc(c)}var b=kc;b.l(a);100>b.h&&(b.h++,a.next=b.g,b.g=a)}gc=!1};_.L=function(){this.l=this.l;this.j=this.j};_.lc=function(a){_.L.call(this);this.C=1;this.v=[];this.A=0;this.g=[];this.h={};this.D=!!a};mc=function(a,b,c){hc(function(){a.apply(b,c)})}; 
oc=function(a,b){if((null==_.Ga(a.v,28)||!_.F(_.Ha(a.v,nc,28),12))&&a.h[b]&&a.l(b)){a.B.push(b);var c=a.j;a=a.h[b];for(let d=0;d<a.length;d++){const e=a[d],f=e;f.href&&f.setAttribute("data-original-click-url",f.href);Vb(c,e,b,"mousedown");Vb(c,e,b,"click")}c.K[b]=!0}};_.pc=function(a,b,c){a=a.getElementsByAdPiece(b);if(c)for(b=0;b<a.length;b++){const d=a[b].getAttribute(c);if(d)return d}return null};qc=function(a,b){a=a.getElementsByAdPiece(b);for(b=0;b<a.length;b++)if(!a[b].href)return!1;return!0}; 
uc=function(a){rc([a]);a=new sc(new tc(a));return window.adSlot=a};_.vc=function(){const a=window.adSlot;return a?a:(_.Kb.xa(536,Error("no adslot"),void 0,void 0),uc(null))};Bc=function(a,b){var c=wc;const d={};if(!b)return null;d[0]=[b];xc(yc,e=>{c[e]&&(d[e]=_.oa(_.zc(2,c[e],b)))});return new Ac(d,b,a)};Ec=function(a,b){const c=_.Ha(b,Cc,16);c&&_.F(c,12)&&_.F(b,5)&&Dc(a,{backgroundColor:"transparent",backgroundImage:"none"})};_.aa=[];_.q=this||self;_.Fc=String.prototype.trim?function(a){return a.trim()}:function(a){return/^[\s\xa0]*([\s\S]*?)[\s\xa0]*$/.exec(a)[1]};var ta;_.y=class{constructor(a,b){this.g=b===_.ua?a:""}};_.l=_.y.prototype;_.l.X=!0;_.l.W=function(){return this.g.toString()};_.l.va=!0;_.l.aa=_.ca(2);_.l.toString=function(){return this.g.toString()};ta=/^(?:(?:https?|mailto|ftp):|[^:/?#]*(?:[/?#]|$))/i;_.ua={};var qa;a:{var Gc=_.q.navigator;if(Gc){var Hc=Gc.userAgent;if(Hc){qa=Hc;break a}}qa=""};var Jc;_.ra=class{constructor(a,b,c){this.g=c===_.Ic?a:"";this.h=b}};_.l=_.ra.prototype;_.l.va=!0;_.l.aa=_.ca(1);_.l.X=!0;_.l.W=function(){return this.g.toString()};_.l.toString=function(){return this.g.toString()};_.Ic={};Jc=new _.ra(_.q.trustedTypes&&_.q.trustedTypes.emptyHTML||"",0,_.Ic);_.Kc=ka(function(){var a=document.createElement("div"),b=document.createElement("div");b.appendChild(document.createElement("div"));a.appendChild(b);b=a.firstChild.firstChild;a.innerHTML=_.sa(Jc);return!b.parentElement});xa[" "]=_.da;_.Lc=A("Gecko")&&!(-1!=qa.toLowerCase().indexOf("webkit")&&!A("Edge"))&&!(A("Trident")||A("MSIE"))&&!A("Edge");_.Mc=A("Android");_.Nc=wa();_.Oc=A("iPad");_.Pc=wa()||A("iPod");_.Qc=A("iPad");_.Rc=A("Android")&&!((A("Chrome")||A("CriOS"))&&!A("Edge")||A("Firefox")||A("FxiOS")||A("Opera")||A("Silk"));var Da="function"===typeof Uint8Array,za=Symbol("IS_REPEATED_FIELD");var Ca,Ea=Object.freeze(Aa([]));var Sc;_.La=class extends _.Ba{constructor(a){super();_.Fa(this,a,Sc)}};Sc=[20,33];var nc=class extends _.Ba{constructor(a){super();_.Fa(this,a,null)}};var Qb=class extends _.Ba{constructor(a){super();_.Fa(this,a,null)}};_.Tc=class extends _.Ba{constructor(a){super();_.Fa(this,a,null)}};var Cc=class extends _.Ba{constructor(a){super();_.Fa(this,a,null)}};var tc=class extends _.Ba{constructor(a){super();_.Fa(this,a,Uc)}},Uc=[1,23];var yc={nb:0,Nb:1,Ob:45,Pb:46,Bb:48,URL:2,eb:3,Wa:4,Mb:5,Gb:7,tb:8,bb:9,vb:6,yb:34,ob:13,Xa:14,ub:15,wb:16,xb:40,Kb:47,Sb:29,jb:30,Lb:49,Cb:17,fb:18,lb:19,kb:20,Ib:23,$a:24,Fb:25,Eb:26,ab:27,Db:28,Rb:39,Qb:31,ib:32,Za:33,pb:35,zb:36,Ya:37,gb:38,Ab:42,Hb:43,Jb:44,cb:50,qb:1E3,rb:1001,sb:1002};var Vc={};var Oa=class{},Pa=class extends Oa{constructor(a){super();if(Vc!==Vc)throw Error("Bad secret");this.g=a}toString(){return this.g}},jb=new Pa("about:invalid#zTSz");var xb=class{constructor(a,b){this.error=a;this.context=b.context;this.msg=b.message||"";this.id=b.id||"jserror";this.meta={}}};Ra.prototype.ceil=function(){this.x=Math.ceil(this.x);this.y=Math.ceil(this.y);return this};Ra.prototype.floor=function(){this.x=Math.floor(this.x);this.y=Math.floor(this.y);return this};Ra.prototype.round=function(){this.x=Math.round(this.x);this.y=Math.round(this.y);return this};_.N=/^(?:([^:/?#.]+):)?(?:\/\/(?:([^\\/?#]*)@)?([^\\/?#]*?)(?::([0-9]+))?(?=[\\/?#]|$))?([^?#]+)?(?:\?([^#]*))?(?:#([\s\S]*))?$/;_.Mb=a=>{a.preventDefault?a.preventDefault():a.returnValue=!1};_.Wc=0;_.Xc=document;_.K=window;var eb=class{constructor(a){this.Ua=a}},Yc=new eb(a=>/^[^:]*([/?#]|$)/.test(a)),Zc=fb("http"),$c=fb("https"),ad=fb("ftp"),bd=fb("mailto"),gb=[fb("data"),Zc,$c,bd,ad,Yc];var Bb;Bb=[Zc,$c,bd,ad,Yc,fb("market"),fb("itms"),fb("intent"),fb("itms-appss")];_.Ab=a=>{var b=`${"http:"===_.K.location.protocol?"http:":"https:"}//${"pagead2.googlesyndication.com"}/pagead/gen_204`;return c=>{c=_.Za(b,{id:"unsafeurl",ctx:a,url:c});navigator.sendBeacon&&navigator.sendBeacon(c,"")}};var xc,cd,dd,Dc,Sb;xc=(a,b)=>{if(a)for(let c in a)Object.prototype.hasOwnProperty.call(a,c)&&b.call(void 0,a[c],c,a)};cd=!!window.google_async_iframe_id;dd=cd&&window.parent||window;_.zc=(a,b,c=_.Xc)=>{switch(a){case 2:return c.getElementsByClassName(b);case 3:return c.getElementsByTagName(b)}return[]};_.O=(a,b,c=_.Xc)=>{switch(a){case 1:if(c.getElementById)return c.getElementById(b);break;case 2:case 3:if(a=_.zc(a,b,c),0<a.length)return a[0]}return null};Dc=(a,b)=>{a&&xc(b,(c,d)=>{a.style[d]=c})}; 
Sb=a=>{for(const b of a)if("avoid_appify_double_billing"===_.D(b,1)&&"true"===_.D(b,2).toLowerCase())return!0;return!1};var ed=/^https?:\/\/(\w|-)+\.cdn\.ampproject\.(net|org)(\?|\/|$)/,fd=class{constructor(a,b){this.g=a;this.h=b}},gd=class{constructor(a,b){this.url=a;this.Ma=!!b;this.depth=null}};var sb=class{constructor(){this.j="&";this.h={};this.l=0;this.g=[]}};var hd=class{constructor(){this.h="http:"===_.K.location.protocol?"http:":"https:";this.g=Math.random()}};var id=null;var jd=()=>{const a=_.q.performance;return a&&a.now&&a.timing?Math.floor(a.now()+a.timing.navigationStart):_.ia()},kd=()=>{const a=_.q.performance;return a&&a.now?a.now():null};var ld=class{constructor(a,b){var c=kd()||jd();this.label=a;this.type=b;this.value=c;this.duration=0;this.uniqueId=Math.random();this.slotId=void 0}};var J=_.q.performance,md=!!(J&&J.mark&&J.measure&&J.clearMarks),ub=ka(()=>{var a;if(a=md){var b;if(null===id){id="";try{a="";try{a=_.q.top.location.hash}catch(c){a=_.q.location.hash}a&&(id=(b=a.match(/\bdeid=([\d,]+)/))?b[1]:"")}catch(c){}}b=id;a=!!b.indexOf&&0<=b.indexOf("1337")}return a}),od=class{constructor(){var a=nd;this.events=[];this.h=a||_.q;let b=null;a&&(a.google_js_reporting_queue=a.google_js_reporting_queue||[],this.events=a.google_js_reporting_queue,b=a.google_measure_js_timing);this.g= 
ub()||(null!=b?b:1>Math.random())}start(a,b){if(!this.g)return null;a=new ld(a,b);b=`goog_${a.label}_${a.uniqueId}_start`;J&&ub()&&J.mark(b);return a}end(a){if(this.g&&"number"===typeof a.value){a.duration=(kd()||jd())-a.value;var b=`goog_${a.label}_${a.uniqueId}_end`;J&&ub()&&J.mark(b);!this.g||2048<this.events.length||this.events.push(a)}}};_.rd=class{constructor(){var a=pd;this.j=_.qd;this.h=null;this.v=this.xa;this.g=void 0===a?null:a;this.l=!1}xa(a,b,c,d,e){e=e||"jserror";let f;try{const E=new sb;var g=E;g.g.push(1);g.h[1]=nb("context",a);b.error&&b.meta&&b.id||(b=new xb(b,{message:wb(b)}));if(b.msg){g=E;var h=b.msg.substring(0,512);g.g.push(2);g.h[2]=nb("msg",h)}var k=b.meta||{};b=k;if(this.h)try{this.h(b)}catch(Ja){}if(d)try{d(b)}catch(Ja){}d=E;k=[k];d.g.push(3);d.h[3]=k;d=_.q;k=[];b=null;do{var m=d;if($a(m)){var p=m.location.href; 
b=m.document&&m.document.referrer||null}else p=b,b=null;k.push(new gd(p||""));try{d=m.parent}catch(Ja){d=null}}while(d&&m!=d);for(let Ja=0,sf=k.length-1;Ja<=sf;++Ja)k[Ja].depth=sf-Ja;m=_.q;if(m.location&&m.location.ancestorOrigins&&m.location.ancestorOrigins.length==k.length-1)for(p=1;p<k.length;++p){var n=k[p];n.url||(n.url=m.location.ancestorOrigins[p-1]||"",n.Ma=!0)}var u=k;let M=new gd(_.q.location.href,!1);m=null;const G=u.length-1;for(n=G;0<=n;--n){var C=u[n];!m&&ed.test(C.url)&&(m=C);if(C.url&& 
!C.Ma){M=C;break}}C=null;const ba=u.length&&u[G].url;0!=M.depth&&ba&&(C=u[G]);f=new fd(M,C);if(f.h){u=E;var z=f.h.url||"";u.g.push(4);u.h[4]=nb("top",z)}var v={url:f.g.url||""};if(f.g.url){var H=f.g.url.match(_.N);var ha=_.Ta(H[1],null,H[3],H[4])}else ha="";z=E;v=[v,{url:ha}];z.g.push(5);z.h[5]=v;_.tb(this.j,e,E,this.l,c)}catch(E){try{_.tb(this.j,e,{context:"ecmserr",rctx:a,msg:wb(E),url:f&&f.g.url},this.l,c)}catch(M){}}return!0}};_.rd.prototype.pinger=_.ca(3);if(cd&&!$a(dd)){let a="."+_.Xc.domain;try{for(;2<a.split(".").length&&!$a(dd);)_.Xc.domain=a=a.substr(a.indexOf(".")+1),dd=window.parent}catch(b){}$a(dd)||(dd=window)}var nd=dd,pd=new od,sd=()=>{if(!nd.google_measure_js_timing){var a=pd;a.g=!1;a.events!=a.h.google_js_reporting_queue&&(ub()&&ma(a.events,vb),a.events.length=0)}};_.qd=new hd;"number"!==typeof nd.google_srt&&(nd.google_srt=Math.random());var td=_.qd,ud=nd.google_srt;0<=ud&&1>=ud&&(td.g=ud);_.Kb=new _.rd; 
_.Kb.h=a=>{var b=_.Wc;0!==b&&(a.jc=String(b),b=(b=db(b,document.currentScript))&&b.getAttribute("data-jc-version")||"unknown",a.shv=b)};_.Kb.l=!0;"complete"==nd.document.readyState?sd():pd.g&&_.I(nd,"load",()=>{sd()});var vd=(a,b,c,d,e)=>{c="&"+b+"="+c;const f=a.indexOf("&"+d+"=");c=0>f?a+c:a.substring(0,f)+c+a.substring(f);return 2E3<c.length?void 0!==e?vd(a,b,e,d,void 0):a:c};var Hb=(a,b,c,d)=>{b=c(d,b);if(!(b instanceof Array))return a;ma(b,e=>{if(2!==e.length&&3!==e.length)return a;a=vd(a,e[0],e[1],"adurl",e[2])});return a};_.Tb=class{constructor(){this.g={}}};(function(){var a=_.Tb;a.wa=void 0;a.ga=function(){return a.wa?a.wa:a.wa=new a}})();var Nb=class{constructor(a,b,c){this.g=a;this.l=b;this.j=c;this.D=[];this.v=[];this.K={};this.h={};this.B=this.C=!1;a=this.g;this.H=_.F(a,31)&&_.D(a,28)?1:_.D(a,22)&&_.D(a,23)?_.F(a,44)?3:2:0;this.A=-1}da(a,b){this.C=!0;var c=!1;if(b.target){{c=b.target;var d=b.button,e=b.ctrlKey,f=b.shiftKey,g=b.metaKey,h=b.altKey,k=new Ra(b.x,b.y);let m;document.createEvent?(m=document.createEvent("MouseEvents"),m.initMouseEvent("click",!0,!0,null,0,k.x,k.y,k.x,k.y,e,h,f,g,d,null),c.dispatchEvent?(c.dispatchEvent(m), 
c=!0):c=!1):c=!1}}!a.href||c||Pb(this,a,b)||(Lb(this,a),_.K.top.location=a.href)}V(a,b,c,d){if(this.C)this.C=!1;else{d||(d=_.K.event);this.h[c][b].forEach(e=>{e(d)});if(a.href){const e=Ib(this,a,d.type);e&&(a.href=e)}"click"==c&&(Ob(this,a,b,d),(d.preventDefault?d.defaultPrevented:!1===d.returnValue)||Ub(this,a,d))}}registerCallback(a,b,c,d){const e=("click"==c||"mousedown"==c)&&this.K[b];this.h[c]||(this.h[c]={});this.h[c][b]||(this.h[c][b]=[]);this.h[c][b].push(d);if(!e)for(b=0;b<a.length;b++)_.I(a[b], 
c,d)}};var jc;var wd=class{constructor(){this.h=this.g=null}add(a,b){const c=kc.get();c.set(a,b);this.h?this.h.next=c:this.g=c;this.h=c}},kc=new class{constructor(a,b){this.j=a;this.l=b;this.h=0;this.g=null}get(){let a;0<this.h?(this.h--,a=this.g,this.g=a.next,a.next=null):a=this.j();return a}}(()=>new xd,a=>a.reset()),xd=class{constructor(){this.next=this.g=this.h=null}set(a,b){this.h=a;this.g=b;this.next=null}reset(){this.next=this.g=this.h=null}};var ec,gc=!1,cc=new wd;_.L.prototype.l=!1;_.L.prototype.ta=_.ca(4);_.L.prototype.J=_.ca(6);_.x(_.lc,_.L);_.lc.prototype.subscribe=function(a,b,c){var d=this.h[a];d||(d=this.h[a]=[]);var e=this.C;this.g[e]=a;this.g[e+1]=b;this.g[e+2]=c;this.C=e+3;d.push(e);return e};_.lc.prototype.H=function(a){var b=this.g[a];b&&(b=this.h[b],0!=this.A?(this.v.push(a),this.g[a+1]=_.da):(b&&_.na(b,a),delete this.g[a],delete this.g[a+1],delete this.g[a+2]))}; 
_.lc.prototype.B=function(a,b){var c=this.h[a];if(c){for(var d=Array(arguments.length-1),e=1,f=arguments.length;e<f;e++)d[e-1]=arguments[e];if(this.D)for(e=0;e<c.length;e++){var g=c[e];mc(this.g[g+1],this.g[g+2],d)}else{this.A++;try{for(e=0,f=c.length;e<f&&!this.l;e++)g=c[e],this.g[g+1].apply(this.g[g+2],d)}finally{if(this.A--,0<this.v.length&&0==this.A)for(;c=this.v.pop();)this.H(c)}}}};_.lc.prototype.J=_.ca(5);var yd=class{constructor(a,b,c){var d=_.vc().g,e=_.vc().h;this.A=new _.lc;this.h=a;this.h[0]=[b];this.B=[];this.j=new Nb(c,d,e);this.v=d;this.g=c;b=_.D(this.g,22);c=_.D(this.g,23);b&&c&&e&&(e.canOpenIntents([{url:b,id:b,G:c}],(0,_.t)(this.C,this))||e.canOpenURLs(b,(0,_.t)(this.C,this)));(e=_.O(1,"common_15click_anchor"))?(a[20]=[e],oc(this,20)):(e=_.oa(_.zc(2,"common_15click_anchor")),0<e.length&&(a[20]=e,oc(this,20)))}C(a,b){b=(a=_.D(this.g,22))&&b?b[a]:!1;this.j.B=!!b;this.F(0,"app_installed",!b); 
this.F(0,"rh-ani",b)}navigationAdPieces(){return this.B}l(){return!0}has(a){return(a=this.h[a])&&0<a.length}listen(a,b,c){const d=this.h[a];d&&this.j.registerCallback(d,a,b,_.w(c,a,this))}F(a,b,c){if(b){a=this.getElementsByAdPiece(a);for(let d=0;d<a.length;d++)c?_.$b(a[d],b):_.Zb(a[d],b)}}getElementsByAdPiece(a){return this.h[a]?this.h[a]:[]}creativeConversionUrl(){return _.D(this.g,6)}redirectUrl(){return _.D(this.g,8)}getIndex(){return _.B(this.g,2,0)}listenOnObject(a,b){this.A.subscribe(a,b)}fireOnObject(a, 
b){this.A.B(a,b)}};var rc=(a=[])=>{_.q.google_logging_queue||(_.q.google_logging_queue=[]);_.q.google_logging_queue.push([10,a])};var sc=class{constructor(a){this.A=new _.lc;this.B=null;this.j=[];this.g=a;this.v=[];this.C=!1;this.h=null}forEachAd(a){ma(this.j,a)}l(a){this.j.push(a)}D(a){if(a=_.O(1,a))this.B=a;if(0==this.j.length)_.q.css=null;else{for(a=0;a<this.v.length;++a)this.v[a]();this.C=!0}}listenOnObject(a,b){this.A.subscribe(a,b)}fireOnObject(a,b){this.A.B(a,b)}registerFinalizeCallback(a){this.C?a():this.v.push(a)}getSerializedAdSlotData(){return _.Ka(this.g)}getAdsLength(){return this.j.length}getAd(a){return 0<=a&& 
a<this.j.length&&this.j[a].getIndex()==a?this.j[a]:null}getContainer(){return this.B}openSystemBrowser(a){return this.h?(this.h.openSystemBrowser(a,{useFirstPackage:!0,useRunningProcess:!0}),!0):!1}openAttribution(a){return this.h?(this.h.openSystemBrowser(a,{useFirstPackage:!0,useRunningProcess:!0,useCustomTabs:!0}),!0):!1}};var Ac=class extends yd{constructor(a,b,c){super(a,b,c);for(a=0;a<zd.length;a++)oc(this,zd[a])}l(a){return qc(this,a)||4===a}D(a,b){return this.l(b)?a:""}},zd=[1,2,3,4,8,6,40,33,36,37,38,9];var Ad="UNKNOWN",Bd="UNKNOWN",Cd=null,Dd=(a,b,c)=>{b.gqid=Ad;b.qqid=Bd;b.com=a;_.tb(_.qd,"glaurung",b,!0,c,void 0)},wc={[1]:"title-link",[2]:"url-link",[3]:"body-link",[4]:"button-link",[8]:"favicon-link",[6]:"image-link",[26]:"price",[23]:"reviews",[43]:"rating-stars",[44]:"reviews-count",[24]:"app-store",[25]:"promo-headline",[33]:"app-icon",[16]:"image-gallery",[40]:"image-gallery-image-link",[36]:"logo-link",[37]:"advertiser-link",[38]:"call-to-action-link",[39]:"video",[42]:"logo",[50]:"badge-box", 
[9]:"ad-background"},Ed=(a,b,c)=>{_.O(2,"app-icon-link",b)&&(wc[33]="app-icon-link");var d=a.g,e=_.O(1,"adunit",b),f=_.O(1,"ads",b);if(!e||!f)return 1;var g={overflow:"hidden"};0==_.B(d,32,0)?(g.width=_.B(d,2,0)+"px",g.height=_.B(d,3,0)+"px",g.position="absolute",g.top="0",g.left="0"):(g.width="100%",g.height="100%");Dc(e,g);Ec(e,d);Ec(f,d);try{c(f,a)}catch(m){return _.F(d,13)&&(Cd=m),2}c=0;d=Ma(d);for(e=0;e<d.length;e++){var h=d[e];g="taw"+_.B(h,2,0);f=_.O(1,g,b);if(!f)return 3;f=Bc(h,f);if(!f)return 1; 
var k=_.K.registerAd;k?k(f,g):c=4;_.F(h,11)&&_.K.initAppPromo&&_.K.initAppPromo(f,a);g=f;if(_.F(h,19)&&(h=_.Ga(h,33),0<h.length))for(k=0;k<h.length;k++){const m=(0,_.t)(Ac.prototype.D,g,h[k]);g.j.v.push(m)}a.l(f)}return c};var Fd=class extends yd{constructor(a,b,c){const d=[];d[0]=[c];d[15]=[b];(b=_.O(1,"abgc"))&&(d[27]=[b]);(b=_.O(1,"cbc"))&&(d[28]=[b]);(b=_.O(1,"cta-button-anchor"))&&(d[4]=[b]);super(d,c,a);oc(this,15);b&&oc(this,4)}};var Gd=class extends yd{constructor(a){var b=_.Xc.body;const c={};c[0]=[b];super(c,b,a)}};var Id=class extends yd{constructor(a,b,c){super(a,b,c);for(a=0;a<Hd.length;a++)oc(this,Hd[a]);this.listen(4,"mouseover",(0,_.t)(this.F,this,0,"onhoverbg",!1));this.listen(4,"mouseout",(0,_.t)(this.F,this,0,"onhoverbg",!0))}l(a){return qc(this,a)||4==a}},Jd={[1]:"rhtitle",[45]:"rhtitleline1",[46]:"rhtitleline2",[48]:"rhlongtitle",[3]:"rhbody",[2]:"rhurl",[4]:"rhbutton",[8]:"rhfavicon",[14]:"rhaddress",[6]:"rhimage",[34]:"rhimagetemplate",[49]:"rh-scrollflow",[16]:"rhimagegallery",[47]:"rhreviewgallery", 
[29]:"rhviewimagegallery",[30]:"rhcloseimagegalleryview",[31]:"rhtrydemobutton",[32]:"rhclosetrydemoview",[39]:"rhvideo",[9]:"rhbackground",[13]:"rh-icore-empty",[5]:"rhsitelink",[7]:"rhradlink",[17]:"rh-multiframe",[18]:"rh-box-breadcrumbs",[23]:"rhstarratings",[24]:"rhstoreicon",[25]:"rhpromotext",[26]:"rhprice",[27]:"abgc",[28]:"cbc",[35]:"rhdemocountdowntimer",[36]:"rhlogo",[1001]:"rhoverlap-imagegallery",[1002]:"rhoverlap-trydemo"},Hd=[1,45,46,48,2,4,5,7,8,3,9,6,14,15,34,26,24,36];_.Wc=5;sc.prototype.forEachAd=sc.prototype.forEachAd;sc.prototype.addAd=sc.prototype.l;sc.prototype.finalize=sc.prototype.D;_.r("buildAdSlot",uc,void 0);_.r("buildGlaurungAds",(a,b,c)=>{const d=(new Date).getTime();let e=1,f=!1;Cd=null;try{const g=a.g;f=_.F(g,13);Ad=_.D(g,8);Bd=_.D(g,7);e=Ed(a,b,c)}catch(g){f&&(Cd=g),e=1}Dd("bridge",{["r"]:e,["d"]:(new Date).getTime()-d});return e},void 0);_.r("glaurungError",()=>Cd,void 0);_.r("glaurungBridge.log",Dd,void 0); 
_.r("glaurungBridge.getAdPieceClassName",a=>wc[a],void 0);_.r("buildImageAd",function(a,b){if(0>b||b>=Ma(a.g).length)a=null;else{a=Ma(a.g)[b];b=_.O(1,"google_image_div");const c=_.O(1,"aw0");a=b&&c?new Fd(a,c,b):null}return a},void 0);_.r("buildRichmediaAd",function(a,b){return 0>b||b>=Ma(a.g).length?null:new Gd(Ma(a.g)[b])},void 0); 
_.r("buildTextAd",(a,b)=>{const c=a.g;if(!(0>b||b>=Ma(c).length)){if(0>b||b>=Ma(a.g).length)var d=null;else{{d=Ma(a.g)[b];const g=_.O(1,"taw"+b);if(g){var e=g;const h={};h[0]=[e];for(const k in yc){var f=yc[k];const m=Jd[f];m&&(h[f]=_.oa(_.zc(2,m,e)))}d=new Id(h,g,d)}else d=null}}d&&(_.K.registerAd&&_.K.registerAd(d,"taw"+b),a.l(d),_.F(Ma(c)[b],11)&&_.K.initAppPromo&&_.K.initAppPromo(d,a))}},void 0);})(window.hydra=window.hydra||{});
