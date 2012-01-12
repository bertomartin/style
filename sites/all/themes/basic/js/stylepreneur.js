function populateElement(selector, defvalue) {
    if(jQuery.trim(jQuery(selector).val()) == "") {
        jQuery(selector).val(defvalue);
    }
    jQuery(selector).focus(function() {
        if(jQuery(selector).val() == defvalue) {
            jQuery(selector).val("");
        }
    });
    jQuery(selector).blur(function() {
        if(jQuery.trim(jQuery(selector).val()) == "") {
            jQuery(selector).val(defvalue);
        }
    });
}


jQuery(document).ready(function(){
  /* Rock out with the login block to make it super sweet */
  populateElement('#user-login-form #edit-name', 'Username');
  populateElement('#user-login-form #edit-pass', 'Password');
  populateElement('#simplenews-block-form-4 #edit-mail', 'Email');
});