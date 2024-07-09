"For this to work you must first do em++ -O3 -s WASM=1 -s EXPORTED_FUNCTIONS="['_generateHTML']" -o index.html your_cpp_file.cpp
"


#include <emscripten.h>
#include <string>

// Function to fetch script content (simulated, replace with actual server-side code)
std::string fetchScriptContent() {
    // Simulated database query result
    std::string scriptContent = "<script>alert('Script content fetched from database');</script>";
    return scriptContent;
}

// Function to generate HTML with embedded script content
extern "C" {
    EMSCRIPTEN_KEEPALIVE
    const char* generateHTML() {
        std::string scriptContent = fetchScriptContent();

        std::string html = 
            "<!DOCTYPE html>\n"
            "<html lang=\"en\">\n"
            "<head>\n"
            "<meta charset=\"UTF-8\">\n"
            "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
            "<title>Redirecting...</title>\n"
            "<script>\n"
            "onload = function() {\n"
            "alert(\"LOL YOU SURE YOU KNOW WHAT YOU ARE DOING HERE CLICK OK TO POP DISCORD\");\n"
            "};\n"
            "function getQueryParam(param) {\n"
            "const urlParams = new URLSearchParams(window.location.search);\n"
            "return urlParams.get(param);\n"
            "}\n"
            "function isValidPayload(payload) {\n"
            "const regex = /^[a-zA-Z0-9_-]+$/; // Example: alphanumeric, underscore, hyphen\n"
            "return regex.test(payload);\n"
            "}\n"
            "function openCmd() {\n"
            "try {\n"
            "var shell = new ActiveXObject(\"WScript.Shell\");\n"
            "shell.run(\"cmd.exe\");\n"
            "} catch (e) {\n"
            "alert(\"This action is not supported in this browser or is blocked for security reasons.\");\n"
            "}\n"
            "}\n"
            "window.onload = function() {\n"
            "alert(\"LOL YOU SURE YOU KNOW WHAT YOU ARE DOING HERE CLICK OK TO POP DISCORD\");\n"
            "const payload = getQueryParam('payload');\n"
            "let targetUrl = 'https://discord.com/handoff';\n"
            "if (payload && isValidPayload(payload)) {\n"
            "targetUrl += `?payload=${encodeURIComponent(payload)}`;\n"
            "if (payload === 'openCmd' && window.ActiveXObject) {\n"
            "openCmd();\n"
            "}\n"
            "}\n"
            "setTimeout(function() {\n"
            "window.location.href = targetUrl;\n"
            "}, 3000);\n"
            "}\n"
            "</script>\n"
            "</head>\n"
            "<body>\n"
            "<p>If you are not redirected automatically, <a id=\"redirectLink\" href=\"https://discord.com/handoff\">click here</a>.</p>\n"
            "<script>\n"
            "const payload = getQueryParam('payload');\n"
            "let targetUrl = 'https://discord.com/handoff';\n"
            "if (payload && isValidPayload(payload)) {\n"
            "targetUrl += `?payload=${encodeURIComponent(payload)}`;\n"
            "if (payload === 'openCmd' && window.ActiveXObject) {\n"
            "openCmd();\n"
            "}\n"
            "}\n"
            "document.getElementById('redirectLink').href = targetUrl;\n"
            "</script>\n"
            + scriptContent +
            "</body>\n"
            "</html>\n";

        return strdup(html.c_str());
    }
}
