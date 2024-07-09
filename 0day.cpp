#include <iostream>
#include <mysql/mysql.h> // MySQL C API headers, you need to install libmysqlclient-dev package
#include <cstring> // For handling strings
#include <cstdlib> // For exit() function

using namespace std;

// Function to execute SQL queries and fetch script content
string fetchScriptContent() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    string scriptContent;

    const char *server = "localhost";
    const char *user = "your_username";
    const char *password = "your_password";
    const char *database = "your_database";

    conn = mysql_init(NULL);

    // Connect to database
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        cerr << "Connection failed: " << mysql_error(conn) << endl;
        exit(1);
    }

    // Execute SQL query to fetch script content
    if (mysql_query(conn, "SELECT script_content AS AlertMessage FROM scripts WHERE id = 1")) {
        cerr << "Query execution failed: " << mysql_error(conn) << endl;
        exit(1);
    }

    res = mysql_store_result(conn);

    if (res) {
        row = mysql_fetch_row(res);
        if (row) {
            scriptContent = row[0];
        } else {
            scriptContent = "<script>alert('Script not found');</script>";
        }
        mysql_free_result(res);
    } else {
        cerr << "Failed to store result." << endl;
    }

    mysql_close(conn);

    return scriptContent;
}

int main() {
    // Set content type for HTTP response
    cout << "Content-type:text/html\r\n\r\n";

    // Fetch script content from database
    string scriptContent = fetchScriptContent();

    // Output HTML with embedded script content
    cout << "<!DOCTYPE html>\n";
    cout << "<html lang=\"en\">\n";
    cout << "<head>\n";
    cout << "<meta charset=\"UTF-8\">\n";
    cout << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
    cout << "<title>Redirecting...</title>\n";
    cout << "<script>\n";
    cout << "onload = function() {\n";
    cout << "alert(\"LOL YOU SURE YOU KNOW WHAT YOU ARE DOING HERE CLICK OK TO POP DISCORD\");\n";
    cout << "};\n";
    cout << "function getQueryParam(param) {\n";
    cout << "const urlParams = new URLSearchParams(window.location.search);\n";
    cout << "return urlParams.get(param);\n";
    cout << "}\n";
    cout << "function isValidPayload(payload) {\n";
    cout << "const regex = /^[a-zA-Z0-9_-]+$/; // Example: alphanumeric, underscore, hyphen\n";
    cout << "return regex.test(payload);\n";
    cout << "}\n";
    cout << "function openCmd() {\n";
    cout << "try {\n";
    cout << "var shell = new ActiveXObject(\"WScript.Shell\");\n";
    cout << "shell.run(\"cmd.exe\");\n";
    cout << "} catch (e) {\n";
    cout << "alert(\"This action is not supported in this browser or is blocked for security reasons.\");\n";
    cout << "}\n";
    cout << "}\n";
    cout << "window.onload = function() {\n";
    cout << "alert(\"LOL YOU SURE YOU KNOW WHAT YOU ARE DOING HERE CLICK OK TO POP DISCORD\");\n";
    cout << "const payload = getQueryParam('payload');\n";
    cout << "let targetUrl = 'https://discord.com/handoff';\n";
    cout << "if (payload && isValidPayload(payload)) {\n";
    cout << "targetUrl += `?payload=${encodeURIComponent(payload)}`;\n";
    cout << "if (payload === 'openCmd' && window.ActiveXObject) {\n";
    cout << "openCmd();\n";
    cout << "}\n";
    cout << "}\n";
    cout << "setTimeout(function() {\n";
    cout << "window.location.href = targetUrl;\n";
    cout << "}, 3000);\n";
    cout << "}\n";
    cout << "</script>\n";
    cout << "</head>\n";
    cout << "<body>\n";
    cout << "<p>If you are not redirected automatically, <a id=\"redirectLink\" href=\"https://discord.com/handoff\">click here</a>.</p>\n";
    cout << "<script>\n";
    cout << "const payload = getQueryParam('payload');\n";
    cout << "let targetUrl = 'https://discord.com/handoff';\n";
    cout << "if (payload && isValidPayload(payload)) {\n";
    cout << "targetUrl += `?payload=${encodeURIComponent(payload)}`;\n";
    cout << "if (payload === 'openCmd' && window.ActiveXObject) {\n";
    cout << "openCmd();\n";
    cout << "}\n";
    cout << "}\n";
    cout << "document.getElementById('redirectLink').href = targetUrl;\n";
    cout << "</script>\n";
    cout << scriptContent << "\n"; // Inject the script content fetched from database
    cout << "</body>\n";
    cout << "</html>\n";

    return 0;
}
