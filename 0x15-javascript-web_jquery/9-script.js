//JavaScript script that fetches fro API 
// displays the value of hello from that fetch in the HTML tag DIV#hello.

$(document).ready(function(){
    $.ajax({
        url: "https://hellosalut.stefanbohacek.dev/?lang=fr",
        method: "GET",
        success: function(response) {
            $("#hello").text(response.hello);
        },
        error: function(xhr, status, error) {
            console.error("Error fetching translation:", error);
        }
    });
});

