def replace(d: dict)->dict:
    ret = {}
    for k, v in d.items():
        if isinstance(v, str):
            if v == 'a':
                v = 'b'
        elif isinstance(v, list):
            v = ['b' if s == 'a' else s for s in v]
        elif isinstance(v, dict):
            for k1, v1 in v.items():
                if v1 == 'a':
                    v[k1] = 'b'
        ret[k] = v
    return ret


if __name__ == '__main__':
    dt = {"A":"a", "B":["c", "a", "b"], "D": {"F":"c", "M":"a", "b":"a"}}
    print(dt)
    dt1 = replace(dt)
    print(dt1)
