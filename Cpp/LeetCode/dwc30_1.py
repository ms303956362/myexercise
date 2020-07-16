class Solution:
    def reformatDate(self, date: str) -> str:
        l = date.split(' ')
        day_s = l[0][:-2]
        if day_s < 10:
            day_s = '0' + day_s
        mon_d = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]
        mon = 0
        for i in range(1, 13):
            if mon_d[i - 1] == l[1]:
                mon = i
                break
        mon_s = str(mon)
        if mon < 10:
            mon_s = '0' + mon_s
        return l[2] + '-' + mon_s + '-' + day_s