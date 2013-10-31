function ctrlenterkey(e){
	/*
	e=new Event(e);
	if (e.key=='enter' && e.control) {
		if (this.form.onsubmit)
			this.form.onsubmit(e)
		else
			$(this.form).fireEvent('submit');
	}*/
}

//ajax执行结果返回函数
var local={
	/**
	 * 在指定DOM元素中显示
	 * 本来是visibility:hidden，改成visibility:visible
	 */
	update:function(el){
		return function(rsp,txt){
			el.set('html',rsp.message);
		}
	},
	
	/**
	 * 在Notice框中显示
	 * 本来是display:none，改成display:block
	 */
	
	showMessage:function(rsp,txt){
	 	//new Notice(rsp.message,{'icon':rsp.result});
		alert(rsp.message);
	},
	
	/**
	 * 页面跳转
	 */
	redirect:function(rsp,txt) {
		if (typeof rsp != 'object') {
			alert(rsp);
		}
		else{
			switch (rsp.result){
				case 'SUCCESS':
					if (rsp.redirect)
						location.href = rsp.redirect;
					else
						location.reload();
					break;
				case 'ERROR':	
					alert(rsp.message);
					break;
				default:
					alert(rsp.result);
			}
			$('form :submit').each(function(){this.disabled = false;});
		}
	},

	
	/**
	 * 显示评论
	 */
	injectHTML:function(el,where,form){ 
		
		return function(html,txt){
			switch (where){
			case 'top':
				el.html(html+el.html());
				break;
			case 'bottom':
			default:
				el.html(el.html()+html);
			}
			if (form) {
				$(form).find(':submit').each(function(){this.disabled = false;});
				form.reset();
			}
		};
	},
	
	/**
	 * 删除指定DOM元素
	 */
	remove:function(el){
		return function(json,text){
			var ul = $(el).getParent();
			if (ul.counter){
				var count = ul.counter.innerHTML ? eval(ul.counter.innerHTML) : 0;
				ul.counter.set('html', --count ? '('+count+')': '');
			}
			$(el).dispose();
		}
	}
}

function checkAll(el){
	el.getElements('input[type=checkbox]').each(function(cb){
		cb.checked = !cb.checked;
	});
}

function replyPost(postId,userName){
	this.parentId.value = $defined(postId) ? postId : '';
	var focus = function (){
		this.content.focus();
		this.content.value = $defined(userName) ? '回复' + userName + '：' : '';
	}.bind(this);
	var _1c = getScrollTop()+window.getSize().y;
	var _1d = $(this).getCoordinates().top + $(this).getCoordinates().height;
	if(_1d>_1c)
		new Fx.Scroll(window,{wait:false,duration:300}).start(0,(_1d-_1c+getScrollTop())).chain(focus);
	else
		focus();
}

function postRemovePost(rsp,txt){
	if (typeof rsp != 'object'){
		alert(rsp);
	}
	else{
		$('#post-'+rsp.postId).hide();
	}
}

function topicRemoveTopic(rsp,txt) {
	local.redirect(rsp, txt);
}
