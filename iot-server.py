from flask import Flask, request
from flask_restful import reqparse
import datetime
import pymongo

app = Flask(__name__)

myclient = pymongo.MongoClient("mongodb://localhost:27017/")
db_connect = myclient["test_DB"]  # database name
db_collection = db_connect["sensor_data"]  # collection name


# REST API to get sensor data
@app.route('/update', methods=['GET'])
def update():
    parser = reqparse.RequestParser()
    parser.add_argument('api_key', type=str)
    parser.add_argument('field1', type=float)

    data = parser.parse_args()
    data['date'] = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
    db_collection.insert_one(data)
    return '200 OK'


# REST API to show sensor data
@app.route('/feeds.json', methods=['GET'])
def feeds():
    parser = reqparse.RequestParser()
    parser.add_argument('api_key', type=str)
    data = parser.parse_args()  # data = {"api_key": "KDT6QF1NGR35KXKL0Q-DOG"}

    reply_got = [i for i in db_collection.find(data)][-1]
    reply = {"data": reply_got['field1'], "date": reply_got['date']}
    return reply


if __name__ == '__main__':
    app.run(host="192.168.0.106")