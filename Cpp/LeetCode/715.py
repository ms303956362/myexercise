from typing import List


def generate_cpp_test_code(methods: List, args: List[List]):
    s = methods[0] + " *obj = new " + methods[0] + "(" + ",".join(args[0]) + ");\n"
    for method, arg in zip(methods, args):
        s += "obj->" + method + "(" + ",".join([str(a) for a in arg]) + ");\n"
    return s

if __name__ == '__main__':
    methods = ["RangeModule","addRange","removeRange","queryRange","queryRange","queryRange","removeRange","removeRange","removeRange","addRange","addRange","addRange","removeRange","addRange","queryRange","addRange","addRange","queryRange","queryRange","addRange","removeRange","removeRange","removeRange","queryRange","queryRange","addRange","addRange","queryRange","addRange","addRange","removeRange","addRange","addRange","queryRange","removeRange","queryRange","removeRange","addRange","addRange","queryRange","removeRange","removeRange","addRange","queryRange","queryRange","removeRange","removeRange","removeRange","queryRange","addRange","removeRange","removeRange","queryRange","removeRange","removeRange","queryRange","addRange","addRange","removeRange","queryRange","queryRange","addRange","removeRange","removeRange","addRange","addRange","addRange","addRange","queryRange","removeRange","addRange","addRange","addRange","queryRange","addRange","removeRange","queryRange","removeRange","removeRange","removeRange","queryRange","queryRange","queryRange","queryRange","queryRange","removeRange","queryRange","removeRange","queryRange","addRange","queryRange"]
    args = [[],[14,100],[1,8],[77,80],[8,43],[4,13],[3,9],[45,49],[41,90],[58,79],[4,83],[34,39],[84,100],[8,9],[32,56],[35,46],[9,100],[85,99],[23,33],[10,31],[15,45],[52,70],[26,42],[30,70],[60,69],[10,94],[2,89],[26,39],[46,93],[30,83],[42,48],[47,74],[39,45],[14,64],[3,97],[16,34],[28,100],[19,37],[27,91],[55,62],[64,65],[2,48],[55,78],[21,89],[31,76],[13,32],[2,84],[21,88],[12,31],[89,97],[56,72],[16,75],[18,90],[46,60],[20,62],[28,77],[5,78],[58,61],[38,70],[24,73],[72,96],[5,24],[43,49],[2,20],[4,69],[18,98],[26,42],[14,18],[46,58],[16,90],[32,47],[19,36],[26,78],[7,58],[42,54],[42,83],[3,83],[54,82],[71,91],[22,37],[38,94],[20,44],[37,89],[15,54],[1,64],[63,65],[55,58],[23,44],[25,87],[38,85],[27,71]]
    print(generate_cpp_test_code(methods, args))
