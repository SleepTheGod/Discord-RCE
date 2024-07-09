# Discord RCE

This project demonstrates a simple HTML page that performs a URL redirection and attempts to open `cmd.exe` on Internet Explorer using ActiveXObject. 

## How It Works

1. On page load, the script alerts the user with a message.
2. The script checks for a `payload` parameter in the URL query string.
3. If the `payload` is valid and matches `openCmd`, it tries to execute `cmd.exe` using ActiveXObject (works only in Internet Explorer).
4. Regardless of the payload, the script redirects the user to a specified URL after 3 seconds.

## Usage

1. Clone the repository:

git clone https://github.com/SleepTheGod/Discord-RCE.git


2. Open the `index.html` file in a browser: file:///path/to/Discord-RCE/index.html?payload=openCmd


3. The page will display an alert, and if opened in Internet Explorer with the payload `openCmd`, it will attempt to open `cmd.exe`.

## Important Notes

- This script includes potentially dangerous operations for educational purposes only. Use it responsibly and only in a controlled, authorized environment.
- The `openCmd` functionality works only in Internet Explorer with specific security settings. Modern browsers like Chrome and Firefox do not support such operations for security reasons.
- Ensure you have explicit permission to run scripts that execute commands on a user's system.

## Example URL

file:///path/to/Discord-RCE/index.html?payload=openCmd


## Disclaimer

This code is for educational purposes only. The author is not responsible for any misuse or damage caused by this code. Always follow ethical guidelines and legal requirements when using or sharing this code.

Found by Taylor Christian Newsome 
