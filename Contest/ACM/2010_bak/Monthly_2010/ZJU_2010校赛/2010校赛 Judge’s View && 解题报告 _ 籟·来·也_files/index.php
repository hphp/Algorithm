function mngl_request_friend( mingle_url, user_id, friend_id, friend_requested_text )
{
  mngl_replace_id_with_loading_indicator('friend_request_button-' + friend_id);
  jQuery.ajax( {
    type: "POST",
    url: mingle_url,
    data: "controller=friends&action=friend_request&user_id=" + user_id + "&friend_id=" + friend_id,
    success: function(html) {
      jQuery("#friend_request_button-" + friend_id ).replaceWith( friend_requested_text );
    }
  });
}

function mngl_escape(message)
{
  // escape problematic characters -- don't escape utf8 chars
  return message.replace(/&/g,'%26').replace(/=/g,'%3D').replace(/ /g, '%20').replace(/\?/g, '%3F');
}

function mngl_post_to_board( mingle_url, owner_id, author_id, message, controller )
{
  mngl_replace_id_with_loading_indicator('mngl-board-post-button');
  jQuery.ajax( {
    type: "POST",
    url: mingle_url,
    data: "controller=" + controller + "&action=post&owner_id=" + owner_id + "&author_id=" + author_id + "&message=" + mngl_escape(message),
    success: function(html) {
      jQuery('.mngl-board').replaceWith('<div class="mngl-board">'+html+'</div>');
      mngl_load_growables();
    }
  });
}

function mngl_clear_status(user_id)
{
  mngl_replace_id_with_loading_indicator('mngl-clear-status-button');
  jQuery.ajax( {
    type: "POST",
    url: 'http://www.hhanger.com/blog/index.php?plugin=mingle',
    data: "controller=boards&action=clear_status&u=" + user_id,
    success: function(html) {
      jQuery('.mngl-profile-status').slideUp();
    }
  });
}

function mngl_show_older_posts( pagenum, loc, screenname )
{
  mngl_replace_id_with_loading_indicator('mngl-older-posts');
  jQuery.ajax( {
    type: "POST",
    url: 'http://www.hhanger.com/blog/index.php?plugin=mingle',
    data: "controller=boards&action=older_posts&mdp=" + pagenum + "&loc=" + loc + "&u=" + screenname,
    success: function(html) {
      jQuery('#mngl-older-posts').replaceWith(html);
      mngl_load_growables();
    }
  });
}

function mngl_comment_on_post( mingle_url, author_id, board_post_id, message, controller )
{
  mngl_replace_id_with_loading_indicator('mngl-comment-button-' + board_post_id);
  jQuery.ajax( {
    type: "POST",
    url: mingle_url,
    data: "controller=" + controller + "&action=comment&author_id=" + author_id + "&board_post_id=" + board_post_id + "&message=" + mngl_escape(message),
    success: function(html) {
      jQuery('#mngl-comment-form-wrap-'+board_post_id).replaceWith(html);
      mngl_load_growables();
      jQuery("#mngl-board-comment-list-" + board_post_id).show();
      jQuery("#mngl-fake-board-comment-" + board_post_id).show();
    }
  });
}

function mngl_delete_board_post( mingle_url, board_post_id, controller )
{
  if(confirm("Are you sure you want to delete this post?"))
  {
    jQuery.ajax( {
      type: "POST",
      url: mingle_url,
      data: "controller=" + controller + "&action=delete_post&board_post_id=" + board_post_id,
      success: function(html) {
        jQuery('#mngl-board-comment-list-' + board_post_id).slideUp();
        jQuery('.mngl-board-post-' + board_post_id).slideUp();
      }
    });
  }
}

function mngl_delete_board_comment( mingle_url, board_comment_id, controller )
{
  if(confirm("Are you sure you want to delete this comment?"))
  {
    jQuery.ajax( {
      type: "POST",
      url: mingle_url,
      data: "controller=" + controller + "&action=delete_comment&board_comment_id=" + board_comment_id,
      success: function(html) {
        jQuery('#mngl-board-comment-' + board_comment_id).slideUp();
      }
    });
  }
}

function mngl_toggle_comment_form( update_id )
{
  jQuery('#mngl-board-comment-list-' + update_id).show();
  jQuery('#mngl-comment-form-' + update_id).toggle();
  jQuery('#mngl-fake-board-comment-' + update_id).toggle();
  jQuery('#mngl-board-comment-input-' + update_id).focus();
}

function mngl_show_board_post_form()
{
  jQuery('#mngl-fake-board-post-form').toggle();
  jQuery('#mngl-board-post-form').toggle();
  jQuery('#mngl-board-post-input').focus();
}

function mngl_toggle_hidden_comments(board_post_id)
{
  jQuery('.mngl-hidden-comment-'+board_post_id).show();
  jQuery('#mngl-show-hidden-comments-'+board_post_id).hide();
}

function mngl_delete_friend( mingle_url, user_id, friend_id )
{
  if(confirm("Are you sure you want to delete this friend?"))
  {
    jQuery.ajax( {
      type: "POST",
      url: mingle_url,
      data: "controller=friends&action=delete_friend&user_id=" + user_id + "&friend_id=" + friend_id,
      success: function(html) {
        jQuery('#mngl-friend-'+friend_id).slideUp();
      }
    });
  }
}

function mngl_accept_friend_request( mingle_url, request_id, requestor_name )
{
  mngl_replace_id_with_loading_indicator('request-' + request_id);
  jQuery.ajax( {
    type: "POST",
    url: mingle_url,
    data: "controller=friends&action=accept_friend&request_id=" + request_id,
    success: function(html) {
      jQuery( '#request-' + request_id ).replaceWith( 'You\'re now friends with ' + requestor_name );
    }
  });
}

function mngl_ignore_friend_request( mingle_url, request_id )
{
  mngl_replace_id_with_loading_indicator('request-' + request_id);
  jQuery.ajax( {
    type: "POST",
    url: mingle_url,
    data: "controller=friends&action=ignore_friend&request_id=" + request_id,
    success: function(html) {
      jQuery( '#request-' + request_id ).slideUp();
    }
  });
}

function mngl_search_directory( search_query )
{
  mngl_replace_id_with_loading_indicator('mngl-profile-results');
  jQuery.ajax( {
    type: "POST",
    url: 'http://www.hhanger.com/blog/index.php?plugin=mingle',
    data: "&controller=profile&action=search&q=" + search_query,
    success: function(html) {
      jQuery( '#mngl-profile-results' ).replaceWith(html);
      if( search_query != '' )
      {
        jQuery( '.mngl-search-reset-button' ).show();
      }
      else
      {
        jQuery( '.mngl-search-reset-button' ).hide();
      }
    }
  });
}

function mngl_search_friends( search_query, page_params )
{
  mngl_replace_id_with_loading_indicator('mngl-friends-directory');
  jQuery.ajax( {
    type: "POST",
    url: 'http://www.hhanger.com/blog/index.php?plugin=mingle',
    data: "&controller=friends&action=search&q=" + search_query + page_params,
    success: function(html) {
      jQuery( '#mngl-friends-directory' ).replaceWith(html);
    }
  });
}
function mngl_delete_profile_avatar( mingle_url, user_id )
{
  if(confirm("Are you sure you want to delete your avatar?"))
  {
    jQuery.ajax( {
      type: "POST",
      url: mingle_url,
      data: "controller=profile&action=delete_avatar&user_id=" + user_id,
      success: function(html) {
        jQuery('#mngl-avatar-edit-display').replaceWith(html);
      }
    });
  }
}

function mngl_toggle_two_ids( first_id, second_id )
{
  jQuery(first_id).toggle();
  jQuery(second_id).toggle();
}

function mngl_show_search_form()
{
  jQuery('#mngl-fake-search-form').hide();
  jQuery('#mngl-search-form').show();
  jQuery('#mngl-search-input').focus();
}

function mngl_remove_tag( html_tag )
{
  jQuery( html_tag ).remove();
}

function mngl_add_default_user()
{
  jQuery.ajax( {
    type: "POST",
    url: 'http://www.hhanger.com/blog/index.php?plugin=mingle',
    data: "controller=options&action=add_default_user",
    success: function(html) {
      jQuery('.mngl-default-friends-table').append(html);
    }
  });
}

function mngl_replace_id_with_loading_indicator(tagname)
{
  jQuery('#'+tagname).replaceWith('<img id="' + tagname + '" src="http://www.hhanger.com/wordpress/wp-content/plugins/mingle/images/ajax-loader.gif" alt="Loading..." />');
}

function mngl_replace_class_with_loading_indicator(tagname)
{
  jQuery('.'+tagname).replaceWith('<img class="' + tagname + '" src="http://www.hhanger.com/wordpress/wp-content/plugins/mingle/images/ajax-loader.gif" alt="Loading..." />');
}

function mngl_load_growables()
{
  jQuery(".mngl-growable-hidden").show();
  jQuery(".mngl-growable").elastic();
  jQuery(".mngl-growable-hidden").hide();
}

function mngl_show_tooltip( tooltip_content, tooltip_element )
{
  jQuery(tooltip_element).qtip({
    content: tooltip_content
  });
}

function mngl_set_active_tab( tab )
{
  jQuery('#mngl-profile-tab-control li').removeClass('mngl-active-profile-tab');
  jQuery('#mngl-' + tab + '-tab-button').addClass('mngl-active-profile-tab');
  jQuery('.mngl-profile-tab').hide();
  jQuery('#mngl-' + tab + '-tab').show();
}

function mngl_mailer_options()
{
  if( jQuery('#mngl_mailer-type').val() == 'smtp' )
  {
    jQuery('#mngl-sendmail-form').slideUp( 'normal', function() {
      jQuery('#mngl-smtp-form').slideDown();
    } );
  }
  else if( jQuery('#mngl_mailer-type').val() == 'sendmail' )
  {
    jQuery('#mngl-smtp-form').slideUp( 'normal', function() {
      jQuery('#mngl-sendmail-form').slideDown();
    } );
  }
  else
  {
    jQuery('#mngl-sendmail-form').slideUp();
    jQuery('#mngl-smtp-form').slideUp();
  }
}

function mngl_center_image( curr_obj )
{
  var obj_height = jQuery( curr_obj ).height();
  var img_height = jQuery( curr_obj ).find('img').height();
  
  var img_tb_margin = (obj_height - img_height) / 2;
  
  //alert( "obj height: " + obj_height + " img height: " + img_height + " img_tb_margin " + img_tb_margin );
  
  jQuery( curr_obj ).find('img').css('margin-top', img_tb_margin);
  jQuery( curr_obj ).find('img').css('margin-bottom', img_tb_margin);
}

jQuery(document).ready(function() {
  mngl_load_growables();

  // By suppling no content attribute, the library uses each elements title attribute by default
  jQuery('.mngl-grid-cell a').each(function()
  {
    jQuery(this).qtip({
      content: {
        text: jQuery(this).parent().attr('rel')
      },
      position: {
        corner: {
          target: 'bottomMiddle',
          tooltip: 'topMiddle'
        }
      },
      style: {
        border: {
            width: 5,
            radius: 5
        },
        padding: 5, 
        textAlign: 'center',
        tip: true
      }
    });
  });
});

jQuery(function() {
  jQuery(".mngl-datepicker").datepicker({ dateFormat: 'MM d, yy', changeMonth: true, changeYear: true, firstDay: 0, monthNames: ['January','February','March','April','May','June','July','August','September','October','November','December'], monthNamesShort: ['Jan','Feb','Mar','Apr','May','Jun','Jul','Aug','Sept','Oct','Nov','Dec'], dayNames: ['Sunday','Monday','Tuesday','Wednesday','Thursday','Friday','Saturday'], dayNamesShort: ['Sun','Mon','Tue','Wed','Thu','Fri','Sat'], dayNamesMin: ['Su','Mo','Tu','We','Th','Fr','Sa'], isRTL: false, minDate: '-100y', maxDate: '+5y', yearRange: '-100y:+5y' });
})
