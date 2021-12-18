import requests
from termcolor import colored


repo = "https://github.com/nothings/stb/blob/master/stb_image.h"
url = 'https://raw.githubusercontent.com/nothings/stb/master/stb_image.h'

print(f"Download stb_image.h, single header image loading library from {repo}")

try:
    req = requests.get(url, allow_redirects=True)
except requests.exceptions.RequestException as error:
    print(colored(f"Error during download a file {error}", "red"))


with open("stb_image.h", "wb") as header_lib:
    header_lib.write(req.content)


print(colored("File downloaded successfully", "green"))
