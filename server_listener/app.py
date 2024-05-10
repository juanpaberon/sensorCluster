from flask import Flask, render_template, request, redirect, session
import json

app = Flask(__name__)

@app.route('/', methods=['POST'])
def handle_post():
    if request.method == 'POST':
        # print(json.loads(request.data.decode('utf-8')))
        print(request)
        print(request.data.decode('utf-8'))
        return "got post request"
 
if __name__ == '__main__':
    app.run(port=5000, host='0.0.0.0')