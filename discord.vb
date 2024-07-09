Sub LoadHTMLContent()
    Dim htmlContent As String
    Dim payload As String
    
    ' Simulated payload (you can modify this as per your needs)
    payload = "openCmd"
    
    ' Simulated script content from database query
    Dim scriptContent As String
    scriptContent = "<script>alert('Script content fetched from database');</script>"
    
    ' Construct HTML content
    htmlContent = "<html><head><title>Redirecting...</title></head><body>" & _
                  "<h1>Redirecting...</h1>" & _
                  "<p>If you are not redirected automatically, <a href='javascript:onLoad();'>click here</a>.</p>" & _
                  "<script type='text/javascript'>" & _
                  "function onLoad() {" & _
                  "   alert('LOL YOU SURE YOU KNOW WHAT YOU ARE DOING HERE CLICK OK TO POP DISCORD');" & _
                  "   openCmd();" & _
                  "}" & _
                  "function openCmd() {" & _
                  "   ' Example of opening cmd.exe" & _
                  "   Dim objShell As Object" & _
                  "   Set objShell = CreateObject('WScript.Shell')" & _
                  "   objShell.Run 'cmd.exe'" & _
                  "   Set objShell = Nothing" & _
                  "}" & _
                  "</script>" & _
                  "<p><b>Script content:</b></p>" & _
                  scriptContent & _
                  "</body></html>"
    
    ' Display HTML content in an embedded browser (Internet Explorer)
    DisplayHTMLContent htmlContent
End Sub

Sub DisplayHTMLContent(html As String)
    Dim ie As Object ' InternetExplorer.Application
    Set ie = CreateObject("InternetExplorer.Application")
    
    ' Hide the IE window (optional)
    ie.Visible = False
    
    ' Navigate to a blank page first (required)
    ie.Navigate "about:blank"
    
    ' Wait until IE is ready
    Do While ie.Busy Or ie.ReadyState <> 4
        DoEvents
    Loop
    
    ' Display the HTML content
    ie.Document.Write html
    ie.Document.Close
    
    ' Show the IE window
    ie.Visible = True
    
    ' Optionally, clean up resources
    Set ie = Nothing
End Sub
