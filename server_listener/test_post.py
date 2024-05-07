import json
import urllib.request

data = {
        'ids': [12, 3, 4, 5, 6]
}

req = urllib.request.Request('http://127.0.0.1:5000')
jsondata = json.dumps(data).encode('utf-8')
req.add_header('Content-Type', len(jsondata))

response = urllib.request.urlopen(req, jsondata)