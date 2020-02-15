from wsgiref.simple_server import make_server

def app(env, start_response):
    start_response('200 OK', [('Content-Type', 'text/html')])

    body = '<h1>Hello, %s!</h1>' % (env['PATH_INFO'][1:] or 'Web')
    return [body.encode('utf-8')]

http_server = make_server('', 8000, app)
http_server.serve_forever()
