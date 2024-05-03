//avaScript script that fetches and prints how to say “Hello” depending on the language


$(document).ready(function(){
    function fetchTranslation() {
        var languageCode = $('#language_code').val();
        $.getJSON('https://www.fourtonfish.com/hellosalut/?lang=' + languageCode, function(data){
            $('#hello').text(data.hello);
        });
    }

    $('#btn_translate').click(fetchTranslation);

    $('#language_code').keypress(function(event){
        if(event.which == 13){
            fetchTranslation();
        }
    });
});
