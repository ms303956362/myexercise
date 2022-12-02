from typing import Dict, List

class SlashDict:
    def __init__(self, d: Dict) -> None:
        self._check_keys([], d)
        self._d = d

    def _check_keys(self, paths: List, d: Dict):
        for key, value in d.items():
            if not isinstance(key, str):
                raise TypeError('The type of {} on path {} is not str'.format(key, '/'.join(paths)))
            if isinstance(value, dict):
                paths.append(key)
                self._check_keys(paths, value)
                paths.pop()

    def __repr__(self) -> str:
        return 'SlashDict({})'.format(self._d)
    
    def __getitem__(self, path: str):
        return self.get(path)
    
    def __setitem__(self, path: str, value):
        self.insert(path, value)

    def get(self, path: str):
        if not isinstance(path, str):
            raise TypeError('The type of {} is not str'.format(path))
        if path == '':
            return self._d
        keys = path.split('/')
        prefixs = []
        data = self._d
        for k in keys:
            if k not in data:
                raise KeyError("Dict under key '{}' does not have key key '{}'".format('/'.join(prefixs), k))
            data = data[k]
            prefixs.append(k)
        if isinstance(data, dict):
            return SlashDict(data)
        return data

    def pop(self, path: str):
        if not isinstance(path, str):
            raise TypeError('The type of {} is not str'.format(path))
        if path == '':
            self._d = {}
        keys = path.split('/')
        prefixs = []
        father = self._d
        for k in keys[:-1]:
            if k not in father:
                raise KeyError("Dict under key '{}' does not have key key '{}'".format('/'.join(prefixs), k))
            if not isinstance(father[k], dict):
                raise TypeError("Item under key '{}/{}' is not a dict".format('/'.join(prefixs), k))
            father = father[k]
            prefixs.append(k)
        if keys[-1] not in father:
            raise KeyError("Dict under key '{}' does not have key key '{}'".format('/'.join(keys[:-1]), keys[-1]))
        return father.pop(keys[-1])

    def insert(self, path: str, value):
        if not isinstance(path, str):
            raise TypeError('The type of {} is not str'.format(path))
        keys = path.split('/')
        father = self._d
        for k in keys[:-1]:
            if k not in father or not isinstance(father[k], dict):
                father[k] = {}
            father = father[k]
        father[keys[-1]] = value
    
    def deep_keys(self) -> List[str]:
        path_list = []
        def dfs(paths: List[str], data: Dict):
            for key, value in data.items():
                paths.append(key)
                if isinstance(value, dict):
                    dfs(paths, value)
                else:
                    path_list.append('/'.join(paths))
                paths.pop()
        dfs([], self._d)
        return path_list

if __name__ == '__main__':
    from slashdict import SlashDict
    sd = SlashDict({'a': {'b': {'c': {'x': 1, 'y': 2}, 'd': 3}}, 'e': {'f': 4}})
    print(sd['a/b/c'])
    print(sd['a/b/d'])
    # print(sd['a/b/k'])
    print(sd.pop('a/b/c/y'))
    sd['e/f/g'] = 5
    print(sd)
    print(list(sd.deep_keys()))
