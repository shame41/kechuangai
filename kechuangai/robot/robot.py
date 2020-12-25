import requests
from bs4 import BeautifulSoup
head = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.105 Safari/537.36',
        'Cookie': 'bid=FRoXjYn7E2Q; douban-fav-remind=1; __gads=ID=15b228217b5fd9ba-22c93585ebc200fe:T=1597380415:RT=1597380415:R:S=ALNI_MZIsyihgWe9fu0grK5AckD8jJnNQA; viewed="10594787"; gr_user_id=96cfdfcf-908f-4c40-8275-28aa361d3136; _vwo_uuid_v2=D1F394702D8A2878CDED93BF05C43AF57|79844f949557977a113e2d93d0417049; __utmc=30149280; __utmc=81379588; dbcl2="199842583:lefFvk+3TtA"; ck=Wp1D; push_noty_num=0; push_doumail_num=0; __utma=30149280.1541497210.1607839780.1608294408.1608297333.6; __utmz=30149280.1608297333.6.6.utmcsr=baidu|utmccn=(organic)|utmcmd=organic; __utma=81379588.23299441.1604224523.1608294408.1608297333.6; __utmz=81379588.1608297333.6.6.utmcsr=baidu|utmccn=(organic)|utmcmd=organic; _pk_ref.100001.3ac3=%5B%22%22%2C%22%22%2C1608297333%2C%22https%3A%2F%2Fwww.baidu.com%2Flink%3Furl%3DGpuQXVZCwYO7hrxcSi2Nx0t1s7KQ8YjBCo5dpBy3-cbSSutiCKe5I-J7_6obxB_Xqd8_9sFfczuMwZ66jbVmcK%26wd%3D%26eqid%3Dd26c522f000ca720000000055fdcab72%22%5D; _pk_ses.100001.3ac3=*; __utmt_douban=1; __utmt=1; __utmb=30149280.4.10.1608297333; __utmb=81379588.4.10.1608297333; _pk_id.100001.3ac3=e40260baf311f26f.1604224523.6.1608298709.1608295179.',
}
booktitle = []
bookmessage = []
bookcomment = []
bookrate = []
etitle = []
ntitle = []
numofcom = []
robot = open("robot.txt","w",encoding='utf-8')
for page in range(10):
    r = requests.get("https://book.douban.com/top250?start="+str(page*25),headers = head,)
    demo = r.text
    soup = BeautifulSoup(demo,"html.parser")
    for tag in soup.find_all(name = 'div',attrs={'class':'pl2'}):
        booktitle.append(tag.a.contents[0].strip())
    for tag in soup.find_all(name = 'p',attrs={'class':'pl'}):
        bookmessage.append(tag.string)
    for tag in soup.find_all(attrs={'class':'inq'}):
        bookcomment.append(tag.string)
    for tag in soup.find_all(attrs={'class':'rating_nums'}):
        bookrate.append(tag.string)
    for tag in soup.find_all(name='div',attrs={'class':'pl2'}):
        if tag.br == None:
            etitle.append("无")
        else:
            for a in tag.br.next_siblings:
                if a.string.isspace() != True:
                    etitle.append(a.string)
    for tag in soup.find_all(name='div',attrs={'class':'pl2'}):
        if tag.a.span != None :
            ntitle.append(tag.a.span.string)
        else:
            ntitle.append(tag.a.span)
    for tag in soup.find_all(name ='div',attrs={'class':'star clearfix'}):
        a = tag.contents[5].string.strip('(')
        b = a.strip(')')
        c = b.strip()
        numofcom.append(c)

for i in range(250):
    try:
        robot.write(str(i+1)+".书名："+booktitle[i]+ntitle[i]+"\n")
    except TypeError as identifier:
        robot.write(str(i+1)+".书名："+booktitle[i]+"\n")
    robot.write("   英文名："+etitle[i]+"\n")
    robot.write("   书本基本信息："+bookmessage[i]+"\n")
    robot.write("   评价："+bookrate[i]+"   ("+numofcom[i]+")"+"\n")
    try:
        robot.write("   评语："+bookcomment[i]+"\n")
    except IndexError as identifier:
        robot.write("\n")

