/*
include "popup.js"
�û��ٱ�����js  2009-12-3 By sv
*/
var userSpam={}; 
userSpam.Alert=function(str,t,w,h)
	{
		var W=w||350;
		var H=h||100;
		var T=t||"�ٱ�";
        var mypop=new Popup({ contentType:4,isReloadOnClose:false,width:W,height:H});
		mypop.setContent("title",T);
		mypop.setContent("alertCon",str);
		mypop.build();
		mypop.show();
		return mypop;
	}

userSpam.ShowTextDialog=function (str,t,w,h)
    {        
        var W=w||500;
        var H=h||280;
        var T=t||"�ٱ�";
        var mypop=new Popup({ contentType:2,isReloadOnClose:false,width:W,height:H});
        mypop.setContent("title",T);
        mypop.setContent("contentHtml",str);
        mypop.build();
        mypop.show();
        return mypop;
    }

userSpam.ShowTipOff=function(){
    var str='<div style="padding:10px;"><form onsubmit="if(userSpam.checkReason()) setTimeout(function(){userSpam.ShowTipOK();},500); else return false;" name="_antiSpamSubForm" id="_antiSpamSubForm" action="http://act.hi.baidu.com/userspam/submit" method="post" target="_antiSpamSubIfr">\
        <b>�ٶȿռ���������л������ٱ������ǻᾡ�촦�����ľٱ��� <br>�ռ�������ͬŬ��Ϊ�û��ṩ��ɫ�������Ļ���������������</b>\
        <div style="border-top:1px solid #ccc; margin-top:5px; height:5px; line-height:0; font-size:0;"> </div>\
            <input type="hidden" name="spSpamUser" value=""  />\
            <input type="hidden" name="spBlogID" value=""  />\
            <input type="hidden" name="spPhotoID" value=""  />\
            <input type="hidden" name="spMsgID" value=""  />\
            <input type="hidden" name="spSubType" value="" />\
            <textarea style="display:none;" name="spSubContent"></textarea>\
���ʵ�� <br>\
�����ھٱ����������£�\
            <div style="margin:10px 20px;padding:10px; border:1px solid #ccc; height:80px; overflow-y:auto;" id="_spSubContentShow"></div>\
����ȷ�ٱ����ɣ�����ѡ��\
            <div style="margin:10px 20px;padding:10px; border:1px solid #ccc;">\
            <label for="_spam_radio1" style="width:120px; float:left;"><input type="radio" name="spSubReason" value="1" id="_spam_radio1" />���</label>\
            <label for="_spam_radio2" style="width:120px; float:left;"><input type="radio" name="spSubReason" value="2" id="_spam_radio2" />ɧ�š�á��</label>\
            <label for="_spam_radio3" style="width:120px; float:left;"><input type="radio" name="spSubReason" value="3" id="_spam_radio3" />�н�����թ��Ϣ</label><br>\
            <label for="_spam_radio4" style="width:120px; float:left;"><input type="radio" name="spSubReason" value="4" id="_spam_radio4" />ɫ����Ϣ</label>\
            <label for="_spam_radio5" style="width:120px; float:left;"><input type="radio" name="spSubReason" value="5" id="_spam_radio5" />��������</label>\
            <label for="_spam_radio6" style="width:120px; float:left;"><input type="radio" name="spSubReason" value="6" id="_spam_radio6" />����</label>\
            <div style="clear:both;"></div>\
            </div>\
            <div align="center">\
            <input type="submit" value=" ȷ�� " />  <input type="button" name="" onclick="g_pop.close();" value=" ȡ�� "  />\
            </div>\
        </form>\
        <iframe style="display:none;" name="_antiSpamSubIfr"></iframe></div>';

    return userSpam.ShowTextDialog(str);
}

userSpam.ShowTipOK=function(){
    var str='<div style="padding:10px;">\
    <b>�ٶȿռ���������л������ٱ������ǻ����ȡ֤�󣬾��촦�����ľٱ��� <br>�ռ�������ͬŬ��Ϊ�û��ṩ��ɫ�������Ļ���������������</b>\
    <div style="border-top:1px solid #ccc; margin-top:5px; height:5px; line-height:0; font-size:0;"> </div>\
    <div style="padding:20px; text-align:center;"><img src="http://img.baidu.com/hi/img/antiuserok.gif" border="0" align="absmiddle" /> �ٱ���ɣ���л�����ύ</div>';

    var dialog=userSpam.ShowTextDialog(str,"",500,150);
    setTimeout(function(){dialog.close();},1000);
}


userSpam.submit=function (antiText,type,antiuser,msgid,blogid,picid){

    var dialog;
    dialog=g_pop=userSpam.ShowTipOff();   /*���ɶԻ���*/

    var F=G("_antiSpamSubForm");
    G("_spSubContentShow").innerHTML=antiText;

    F.spSubContent.value=antiText; /*�ٱ�����*/
    F.spSubType.value=type;            /*�ٱ����� [0=>board, 1=>blog, 2=>album, 3=>friend]*/
    F.spSpamUser.value=antiuser;        /*���ٱ��û���*/
    F.spMsgID.value=msgid;             /*���ٱ���Ϣid*/
    F.spBlogID.value=blogid;             /*���ٱ�������������id*/
    F.spPhotoID.value=picid;             /*���ٱ�����������Ƭid*/
}


userSpam.tipBlogCmt=function(obj, spamuser, msgid, blogid){

    var pObj=obj.parentNode.parentNode.parentNode.parentNode.parentNode;    
    
    var _div=document.createElement("div");
    _div.appendChild(pObj.cloneNode(true));
    
    var sps=_div.getElementsByTagName("span");
    for(var i=0, n=sps.length; i<n; i++)
    {
        if(sps[i].className=="date") 
        {
            sps[i].parentNode.removeChild(sps[i]);
            break;
        }
    }  

    userSpam.submit(_div.innerHTML.replace('width="10%"', 'width="65"'), 1, spamuser, msgid, blogid);

}

userSpam.tipBoardCmt=function(obj, spamuser, msgid){
    var pObj=obj.parentNode.parentNode.parentNode.parentNode.parentNode;    
    
    var _div=document.createElement("div");
    _div.appendChild(pObj.cloneNode(true));
    
    var sps=_div.getElementsByTagName("span");
    for(var i=0, n=sps.length; i<n; i++)
    {
        if(sps[i].className=="date") 
        {
            sps[i].parentNode.removeChild(sps[i]);
            break;
        }
    }  

    userSpam.submit(_div.innerHTML.replace('width="10%"', 'width="65"'), 0, spamuser, msgid);
}


userSpam.tipNoteCmt=function(obj){

    var pObjs=obj.parentNode.parentNode.getElementsByTagName("div");
    var cObj, uObj, tObj, stype, rObj, spamuser="", msgid="", blogid="";

    for(var i=0, n=pObjs.length; i<n; i++)
    {
        if(pObjs[i].getAttribute("name")=="cmtcontent") cObj=pObjs[i];
        else if(pObjs[i].className=="userhead") uObj=pObjs[i];
        else if(pObjs[i].className=="content") tObj=pObjs[i];
        else if(pObjs[i].className=="remsg") rObj=pObjs[i];
    }

    
    if(tObj.innerHTML.indexOf('������')>-1 && tObj.innerHTML.indexOf('blog/item')>-1)
    stype=1; /*��������*/
    else if(tObj.innerHTML.indexOf('����')>-1 && tObj.innerHTML.indexOf('/board')>-1)
    stype=0; /*����*/

    var alinks=tObj.getElementsByTagName("a");
    
    if(uObj.innerHTML.indexOf('/sys/portraitn/item')>-1)
    {   //��¼�û����ԡ�����     
        spamuser=alinks[0].innerHTML;
    }
    
    var _tlink=rObj.getElementsByTagName("a")[0];
    if(stype==1)
    {   
        var args=_tlink.href.match(/\/blog\/item\/(\w+)\.html\/cmtid\/(\w+)#/);
        blogid=args[1];
        msgid=args[2];
    }else if(stype==0){
        var args=_tlink.href.match(/\/board\/boardid\/(\w+)#/);
        msgid=args[1];
    }

    var _div=document.createElement("div");
    _div.appendChild(cObj.cloneNode(true));
    
    var sps=_div.getElementsByTagName("div");
    for(var i=0, n=sps.length; i<n; i++)
    {
        if(sps[i].className=="remsg") 
        {
            sps[i].parentNode.removeChild(sps[i]);
            break;
        }
    }

    userSpam.submit(_div.innerHTML.replace('class="userhead"','style="float:left; width:70px;"').replace('class="content"','style="float:left; width:330px;"'), stype, spamuser, msgid, blogid);
}

userSpam.checkReason=function(){
    var F=G("_antiSpamSubForm");
    var rds=F["spSubReason"];
    for(var i=0, n=rds.length; i<n; i++)
    {
        if(rds[i].checked) return true;
    }

    alert("��ѡ��ٱ�ԭ��");
    return false;
}