#include <stdio.h>
#include <string.h>
char a[101][200]={"1","47","2161","99359","4568353","210044879","9657496081","444034774847","20415942146881","938689303981679","43159292041010353","1984388744582494559","91238722958753739361","4194996867358089516047","192878617175513363998801","8868221393206256654428799","407745305470312292739725953","18747415830241159209372965039","861973382885623011338416665841","39632028196908417362357793663647","1822211323674901575657120091861921","83782088860848564062865166431984719","3852153876275359045316140535779435153","177115296219805667520479599479422032319","8143451472234785346896745435517634051521","374421652426580320289729810434331744337647","17215252560150459947980674534543742605480241","791527196114494577286821298778577828107753439","36393035768706600095245799069280036350351177953","1673288118164389109804019935888103094288046432399","76934860399793192450889671251783462300899784712401","3537330290272322463631120857646151162747102050338047","162640258492127040134580669780471170024065794530837761","7477914560347571523727079689044027669944279446368198959","343821429517496163051311085026244801647412788738406314353","15808307843244475928836582831518216848111044002520322261279","726838339359728396563431499164811730211460611327196417704481","33418755302704261765989012378749821372879077077048514892144847","1536535905585036312838931137923326971422226084932904488620958481","70647232901608966128824843332094290864049520829836557961671945279","3248236177568427405613103862138414052774855732087548761748288524353","149348216935246051692073952815034952136779314155197406482459600174959","6866769742843749950429788725629469384239073595406993149431393319523761","315722059953877251668078207426140556722860606074566487467361633097918047","14516347988135509826781167752876836139867348805834651430349203729184706401","667436285394279574780265638424908321877175184462319399308596009909398576399","30687552780148724930065438199792905970210191136460857716765067252103149807953","1410959991601447067208229891552048766307791617092737135571884497586835492589439","64873472060886416366648509573194450344188204195129447378589921821742329509306241","2982768754809173705798623210475392667066349601358861842279564519302560321935497647","137142489249161104050370019172294868234707893458312515297481377966096032479523585521","6305571736706601612611222258715088546129496749481016841841863821921114933736149436319","289919157399254513076065853881721778253722142582668462209428254430405190919383350485153","13329975668629000999886418056300486711125089062053268244791857839976717667357897972880719","612888961599534791481699164735940666933500374711867670798216032384498607507543923402027921","28179562257909971407158275159796970192229892147683859588473145631846959227679662578520403647","1295646974902259149937798958185924688175641538418745673398966483032575625865756934688536539841","59571581283246010925731593801392738685887280875114617116763985073866631830597139333094160429039","2738997092054414243433715515905880054862639278716853641697744346914832488581602652387642843195953","125934294653219809187025182137869089784995519540100152900979475973008427842923124870498476626584799","5790238556956056808359724662826072250054931259565890179803358150411472848285882141390542281979704801","266225039325325393375360309307861454412741842420490848118053495442954742593307655379094446494439836047","12240561570408012038458214503498800830736069820083013123250657432225506686443866265296953996462252753361","562799607199443228375702506851636976759446469881398112821412188386930352833824540548280789390769186818559","25876541369603980493243857100671802130103801544724230176661710008366570723669484998955619357978920340900353","1189758103394583659460841724124051261008015424587433190013617248196475322935962485411410209677639566494597679","54702996214781244354705475452605686204238605729477202510449731707029498284330604843925914025813441138410592881","2515148067776542656656991029095737514133967848131363882290674041275160445756271860335180634977740652800392674847","115642108121506180961866881862951319963958282408313261382860556166950351006504174970574383294950256587679652450081","5317021825521507781589219574666664980827947022934278659729294909638440985853435776786086450932734062380463620028879","244467361865867851772142233552803637798121604772568505086164705287201334998251541557189402359610816612913646868878353","11240181624004399673736953523854300673732765872515216955303847148301622968933717475853926422091164830131647292348375359","516803887342336517140127719863745027353909108530927411438890804116587455235952752347723426013833971369442861801156388161","23761738636123475388772138160208416957606086226550145709233673142214721317884892890519423670214271518164239995560845480047","1092523173374337531366378227649723435022526057312775775213310073737760593167469120211545765403842655864185596933997735694001","50232304236583402967464626333727069594078592550161135514103029718794772564385694636840585784906547898234373218968334996443999","2309593471709462198972006433123795477892592731250099457873526056990821777368574484174455400340297360662916982475609412100729953","106191067394398677749744831297360864913465187044954413926668095591859006986390040577388107829868772042595946820659064621637133839","4882479506670629714289290233245475990541506011336652941168858871168523499596573292075678504773623216598750636767841363183207426641","224487866239454568179557605897994534699995811334441080879840839978160221974455981394903823111756799191499933344500043641805904491647","10321559367508239506545360581074503120209265815372953067531509780124201687325378570873500184636039139592398183210234166159888399189121","474567243039139562732907029123529148994926231695821400025569609045735117394992958278786104670146043622058816494326271599713060458207919","21819771620432911646207177979101266350646397392192411448108670506323691198482350702253287314642081967475113160555798259420640892678375153","1003234927296874796162797280009534722980739353809155105212973273681844060012793139345372430368865624460233146569072393661749768002747049119","46126986884035807711842467702459495990763363877828942428348661918858503069390002059184878509653176643203249629016774310181068687233685884321","2120838161738350279948590717033127280852133999026322196598825474993809297131927301583159039013677259962889249788202545874667409844746803629647","97512428453080077069923330515821395423207400591332992101117623187796369164999265870766130916119500781649702240628300335924519784171119281079441","4483450870679945194936524613010751062186688293202291314454811841163639172292834302753658863102483358695923413819113612906653242662026740126024639","206141227622824398890010208867978727465164454086714067472820227070339605556305378660797541571798114999230827333438597893370124642669058926516053953","9478013019779242403745533083314010712335378199695644812435275633394458216417754584093933253439610806605922133924356389482119080320114683879612457199","435782457682222326173404511623576514039962232731912947304549858909074738349660405489660132116650298988873187333186955318284107570082606399535656977201","20036515040362447761572862001601205635125927327468299931196858234184043505867960897940272144112474142681560695192675588251586829143479779694760608494047","921243909398990374706178247562031882701752694830809883887750928913556926531576540899762858497057160264362918791529890104254710033029987259559452333748961","42357183317313194788722626525851865398645498034889786358905345871789434576946652920491151218720516898018012703715182269207465074690235934160040046743958159","1947509188687007969906534641941623776454991156910099362625758159173400433613014457801693193202646720148564221452106854493439138725717822984102282697888326353","89543065496285053420911870902788841851530947719829680894425969976104630511621718405957395736103028609935936174093200124428992916308329621334544964056119054079","4117033503640425449392039526886345101393968603955255221780968860741639603100986032216238510667536669336904499786835098869240235011457444758404966063883588161281","189293998101963285618612906365869085822271024834221910521030141624139317112133735763541014094970583760887671054020321347860621817610734129265293893974588936364847","8703406879186670713006801653303091602723073173770252628745605545849666947555050859090670409857979316331495963985147946902719363375082312501445114156767207484621681","400167422444484889512694263145576344639439094968597399011776824967460540270420205782407297839372077967487926672262785236177230093436175640937209957317316955356232479","18398998025567118246870929303043208761811475295381710101912988342957335185491774415131645030201257607188113130960102972917249864934688997170610212922439812738902072353"};
char b[101][200]={"0","21","988","45449","2089688","96080221","4417600500","203113542801","9338805368368","429381933402149","19742230131130508","907713204098601241","41735065158404526600","1918905284082509622381","88227908002637038102948","4056564862837221243113249","186513755782509540145106528","8575576201132601625431787061","394289991496317165229717098300","18128764032629456998941554734761","833528855509458704786081800700728","38324198589402470963160821277498749","1762079606257004205600611696964241748","81017337689232790986664977239077621681","3725035454098451381180988341300606355600","171270613550839530743338798722588814735941","7874723187884519962812403752897784871497708","362065996029137078758627233834575515274158649","16647161094152421102934040352637575917739800168","765407344334982233656207228987493916700756649101","35192090678315030327082598493072082592317066058500","1618070763858156412812143323452328305329884282041921","74396063046796879959031510280314029962582359907869888","3420600829388798321702637329570993049973458671479972949","157273242088837925918362285649985366268816516528170885788","7231148535257155793922962502569755855315586301624380773321","332475559379740328594537912832558783978248153358193344687000","15286644582932797959554821027795134307144099468175269474828701","702853175255528965810927229365743619344650327382704202497433268","32315959417171399629343097729796411355546770960136218045407101649","1485831280014628853983971568341269178735806813838883325886229242608","68315922921255755883633349045968585810491566665628496772721138058341","3141046623097750141793150084546213678103876259805071968219286121441100","144419828739575250766601270540079860606967816384367682041314440448232281","6640171075397363785121865294759127374242415677421108301932244974497243848","305303449639539158864839202288379779354544153344986614206841954386424984749","14037318512343403943997481439970710722934788638191963145212797656801052054628","645411348118157042265019307036364313475645733203485318065581850258461969528161","29674884694922880540246890642232787709156768938722132667871552314232449546240800","1364399284618334347809091950235671870307735725448014617404025824604434217157548661","62732692207748457118677982820198673246446686601669950267917316379489741539700997628","2884339442271810693111378117778903297466239847951369697706792527631923676609088342249","132616881652295543426004715435009353010200586319161336144244538954688999382478362745848","6097492216563323186903105531892651335171760730833470092937541999388062047917395597966781","280352025080260571054116849751626952064890793032020462938982687432896165204817719143726100","12890095661475422945302471983042947143649804718742107825100266079913835537373697685013433841","592664048402789194912859594370223941655826126269104939491673256988603538553985275791474230608","27249656130866827543046238869047258369024352003660085108791869555395848937945948988722801174149","1252891517971471277785214128381803661033464366042094810064934326291220447606959668205457379780268","57605760170556811950576803666693921149170336485932701177878187139840744740982198788462316668718201","2648612076327641878448747754539538569200802013986862159372331674106383037637574184601061109381257000","121778549750900969596691819905152080262087722306909726629949378821753778986587430292860348714869103821","5599164676465116959569374967882456153486834424103860562818299094126567450345384219286974979774597518788","257439796567644479170594556702687830980132295786470676163011808951000348936901086656907988720916616760449","11836631477435180924887780233355757768932598771753547242935724912651889483647104601998480506182389773461888","544227608165450678065667296177662169539919411204876702498880334173035915898829910605273195295669012962486421","25022633344133296010095807843939104041067360316652574767705559647047000241862528783240568503094592206500913500","1150496906221966165786341493525021123719558655154813562611956863429988975209777494118460877947055572486079534601","52897835052866310330161612894307032587058630776804771305382310158132445859407902200665959817061461742153157678168","2432149915525628309021647851644598477880977457077864666484974310410662520557553723736515690706880184566559173661149","111825998279126035904665639562757222949937904394804969887003435968732343499788063389679055812699427028319568830734708","5141563770924272023305597772035187657219262624703950750135673080251277138469693362201500051693466763118133607040135441","236400107464237387036152831874055875009136142831986929536353958255590016026106106597879323322086771676405826355015495600","10869263379583995531639724668434535062763043307646694807922146406676889460062411210140247372764298030351549878723672662181","499749715353399557068391181916114557012090856008915974234882380748881325146844809559853499823835622624494888594933926964748","22977617642876795629614354643472835087493416333102488119996667368041864067294798828543120744523674342696413325488236967716249","1056470661856979199405191922417834299467685060466705537545611816549176865770413901303423700748265184141410518083863966587982728","48574672827778166377009214076576904940426019365135352238978146893894093961371744661128947113675674796162187418532254226079489261","2233378479415938674143018655600119792960129205735759497455449145302579145357329840510628143528332775439319210734399830433068523300","102686835380305400844201848943528933571225517444479801530711682537024746592475800918827765655189631995412521506363859945695072582561","4721361049014632500159142032746730824483413673240335110915281947557835764108529512425566591995194739013536670082003157671540270274528","217079921419292789606476331657406088992665803451610935300572257905123420402399881770657235466123768362627274302265781392945157360045749","9980955024238453689397752114207933362838143545100862688715408581688119502746286031937807264849698149941841081234143940917805698291829948","458906851193549576922690120921907528601561937271188072745608222499748373705926757587368476947619991128962062462468355500826116964064131881","21099734199879042084754347810293538382309010970929550483609262826406737070969884562987012132325669893782313032192310209097083574648658236600","970128866343242386321777309152580858057612942725488134173280481792210156890908763139815189610033195122857437418383801262965018316874214751741","44604828117589270728717001873208425932267886354401524621487292899615260479910833219868511709929201305757659808213462547887293759001565220343508","2050851964542763211134660308858435012026265159359744644454242192900509771919007419350811723467133226869729493740400893401552547895755125921049649","94294585540849518441465657205614802127275929444193852120273653580523834247794430456917470767778199234701799052250227633923529909445734227147940368","4335500082914535085096285571149422462842666489273557452888133822511195865626624793598852843594330031569413026909770070267080823286608019322884207301","199338709228527764395987670615667818488635382577139448980733882181934485984576946075090313334571403252958297438797173004651794341274523154625525595500","9165245124429362627130336562749570228014384932059141095660870446546475159424912894660555560546690219604512269157760188143715458875341457093451293185721","421401937014522153083599494215864562670173071492143350951419306658955922847561416208310465471813178698554606083818171481606259313924432503144133960947688","19375323857543589679218446397367020312599946903706535002669627235865425975828400232687620856142859529913907367586478127965744212981648553687536710910407949","890843495509990603090964934784667069816927384499008466771851433543150638965258849287422248917099725197341184302894175714942627537841909037123544567917817988","40959425469602024152505168553697318191266059740050682936502496315749063966426078666988735829330444499547780570565545604759395122527746167153995513413309219521","1883242728106183120412146788535291969728421820657832406612342979090913791816634359832194425900283347254000565061712203643217233008738481780046670072444306280000","86588206067414821514806247104069733289316137690520240021231274541866285359598754473613954855583703529184478212268195821983233323279442415714992827819024779660501","3981174236372975606560675219998672439338813911943273208570026285946758212749726071426409728930950078995231997199275295607585515637845612641109623409602695558103068","183047426667089463080276253872834862476296123811700047354199977879009011501127800531141233575968119930251487392954395402126950486017618739075327684013904970893080649","8416200452449742326086147002930405001470282881426258905084628956148467770839129098361070334765602566712573188078702913202232136841172616384823963841230025965523606808"};
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)break;
		printf("%s %s\n",a[n],b[n]);	
	}	
}
