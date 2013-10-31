$checkResponse = function (func){
	return func;
}
var api={
	path:'/api/',
	fail:function(instance){
		if (!unloading) alert('无法访问网站，请检查互联网连接，然后重试');
	},
	
	deleteDialog:function(dialogId,callback){
		$.post(this.path+'dialog/delete/', {'dialogId':dialogId}, $checkResponse(callback), 'json');
	},

	deletePost:function(postId,callback){
		$.post(this.path+'topic/delete-post/', {'postId':postId}, $checkResponse(callback), 'json');
    },
    
    deleteTopic:function(topicId,callback){
		$.post(this.path+'topic/delete-topic/', {'topicId':topicId},$checkResponse(callback), 'json');
    },
	
	/*	注册相关	*/
	logout:function(callback){
		$.post(this.path+'auth/logout/', {}, $checkResponse(callback), 'json');
	},
	checkEmail:function(email,callback){
		$.post(this.path+'auth/check-email/', {'email':email}, $checkResponse(callback), 'json');
	},
	checkName:function(user_name,callback){
		$.post(this.path+'auth/check-name/', {'user_name':user_name}, $checkResponse(callback), 'json');
	},
	checkDomain:function(domain,callback){
		$.post(this.path+'auth/check-domain/', {'domain':domain}, $checkResponse(callback), 'json');
	}
};
