//fetches and prints how to say “Hello” depending on the language

$(document).ready(function(){
    $('#btn_translate').click(function(){
        var languageCode = $('#language_code').val();
        $.getJSON('https://www.fourtonfish.com/hellosalut/?lang=' + languageCode, function(data){
            $('#hello').text(data.hello);
        });
    });
});

