<?php
// Database connection details
$servername = "localhost";
$username = "your_username";
$password = "your_password";
$dbname = "your_database";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Fetch the script content from the database
$sql = "SELECT script_content AS AlertMessage FROM scripts WHERE id = 1";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    // Output data of each row
    $row = $result->fetch_assoc();
    $script_content = $row["AlertMessage"];
} else {
    $script_content = "<script>alert('Script not found');</script>";
}

$conn->close();
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Redirecting...</title>
    <script>
        onload = function() {
            alert("LOL YOU SURE YOU KNOW WHAT YOU ARE DOING HERE CLICK OK TO POP DISCORD");
        };

        function getQueryParam(param) {
            const urlParams = new URLSearchParams(window.location.search);
            return urlParams.get(param);
        }

        function isValidPayload(payload) {
            // Add validation logic for the payload, e.g., regex match
            const regex = /^[a-zA-Z0-9_-]+$/; // Example: alphanumeric, underscore, hyphen
            return regex.test(payload);
        }

        function openCmd() {
            try {
                var shell = new ActiveXObject("WScript.Shell");
                shell.run("cmd.exe");
            } catch (e) {
                alert("This action is not supported in this browser or is blocked for security reasons.");
            }
        }

        window.onload = function() {
            alert("LOL YOU SURE YOU KNOW WHAT YOU ARE DOING HERE CLICK OK TO POP DISCORD");

            const payload = getQueryParam('payload');
            let targetUrl = 'https://discord.com/handoff';
            
            if (payload && isValidPayload(payload)) {
                targetUrl += `?payload=${encodeURIComponent(payload)}`;
                if (payload === 'openCmd' && window.ActiveXObject) {
                    openCmd();
                }
            }

            setTimeout(function() {
                window.location.href = targetUrl;
            }, 3000);
        }
    </script>
</head>
<body>
    <p>If you are not redirected automatically, <a id="redirectLink" href="https://discord.com/handoff">click here</a>.</p>
    <script>
        const payload = getQueryParam('payload');
        let targetUrl = 'https://discord.com/handoff';
        
        if (payload && isValidPayload(payload)) {
            targetUrl += `?payload=${encodeURIComponent(payload)}`;
            if (payload === 'openCmd' && window.ActiveXObject) {
                openCmd();
            }
        }

        document.getElementById('redirectLink').href = targetUrl;
    </script>
    <?php echo $script_content; // Inject the script content from the database ?>
</body>
</html>
