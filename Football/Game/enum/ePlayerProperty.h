#pragma once

namespace game
{
	/**
	*	球员属性
	*/
	enum ePlayerProperty
	{
		/**
		门将
		在稳定的前提下，门将的第一属性：反应，制空，一对一
		门将的第一精神属性：勇敢，预判，位置感，集中
		身体方面，弹跳和灵活比较重要

		中后卫
		技术属性第一等 铲球，盯人，头球
		精神属性一等属性预判，位置感，决断力，集中
		精神属性二等属性侵略性，勇敢，镇定
		边后卫的技能属性铲球，盯人，头球
		精神能力一等属性预判，位置感，决断力，集中，
		精神能力二等属性侵略性，勇敢，镇定
		边后卫多进攻的话，自然需要一点创造力和无球跑

		后腰
		技能属性第一等当然是铲球，盯人，传球
		精神第一等：决断力，位置感，预判，集中，侵略性，工作投入度
		精神第二等：勇敢，团队合作，镇定

		中场MC
		第一等技术属性：传球，技术，停球
		第二等技术属性：盘带，远射，射门
		精神第一等：创造力，决断力，无球跑动，团队合作
		精神第二等：才华，决心
		前腰
		第一技术属性：传球，技术，停球，射门
		第二技术属性：远射，盘带，传中
		第一精神属性：创造力，决断力，无球跑动，决心，才华
		第二精神属性：团队合作，镇定

		边前卫（ML，AML MR,AMR)
		第一技术属性：传球，技术，停球，盘带，传中第二技能属性：射门，远射
		精神属性第一等：创造力，决心，无球跑动，才华
		精神属性第二等：团队合作，镇定

		前锋
		第一等技术属性：射门，技术，停球，头球
		第二等技术属性：远射，盘带，传球
		第一等精神属性：决心，无球跑动，才华，镇定
		第二等精神属性：集中，预判，勇敢，创造
		*/
		/**
		*	体重
		*	球员的体重。这是一个纯数据性属性，不会对球员的表现产生影响
		*/
		EPP_WEIGHT = 0,
		/**
		*	本国声望
		*	球员在他母国的人们中声望怎样。这不会总是和他的能力一样高，尤其当他表现很不稳定或者还没有证明自己时。当他在母国的一家俱乐部中效力时，这项属性会和他的当前声望(CURRENT REPUTATION)一致。
		*/
		EPP_HOMEREPUTATION,
		/**
		*	当前声望
		*	球员在他的俱乐部所在的国家的人们中声望怎样。这不会总是和他的能力一样高，尤其当他表现很不稳定或者还没有证明自己时。
		*/
		EPP_CURRENTREPUTATION,
		/**
		*	世界声望
		*	球员在世界范围内声望怎样。这不会总是和他的能力一样高，尤其当他表现很不稳定或者还没有证明自己时。这是定义一个球员身价的基础之一。
		*/
		EPP_WORLDREPUTATION,
		/**
		*	适应力
		*	球员对于生活在非母国的国家有多适应。
		*/
		EPP_ADAPTABILITY,
		/**
		*	野心
		*	球员对于尽他所能在一个较高水平的环境踢球的志向。
		*/
		EPP_AMBITION,
		/**
		*	争论
		*	球员在场下多喜欢争吵，这是一个负面属性。
		*/
		EPP_CONTROVERSY,
		/**
		*	忠诚
		*	球员大体上有多忠诚。
		*/
		EPP_LOYALTY,
		/**
		*	压力
		*	球员在场上和场下处理压力的能力有多好。
		*/
		EPP_PRESSURE,
		/**
		*	职业道德
		*	球员在场上和场下的行为多有职业道德。
		*/
		EPP_PROFESSIONALISM,
		/**
		*	体育精神
		*	球员在场上和场下的行为多有体育精神。
		*/
		EPP_SPORTSMANSHIP,
		/**
		*	气质
		*	球员在场上和场下控制脾气的能力有多好。
		*/
		EPP_TEMPERAMENT,
		/**
		*	状态稳定性
		*	球员比赛中有多稳定。
		*/
		EPP_CONSISTENCY,
		/**
		*	肮脏
		*	球员在场上有多肮脏。
		*/
		EPP_DIRTINESS,
		/**
		*	重要比赛
		*	球员在重要比赛中表现多好。
		*/
		EPP_IMPORTANTMATCHES,
		/**
		*	多位置性
		*	球员去打一个不熟悉的位置有多适应。
		*/
		EPP_VERSATILITY,

		//------------- 精神类属性(MENTAL ATTRIBUTES) ---------
		/**
		*	侵略性
		*	它反映一个球员在比赛中的心态，但并不能与该球员的肮脏(DIRTINESS)划等号。一个更富有侵略性的球员会全身心地投入每一次拼抢，也许会冒获得一两张黄牌的风险。一个侵略性较低的球员可能会躲避拼抢并只是站在他的舒适区域。
		*	这项属性反映一个球员在面对一个对手或在双方机会均等（50%—50%）的情况下拼抢时有多积极。富有侵略性的球员会更经常被警告（这将使他们经常被禁赛），但他们不会不为你的球队全身心地投入！
		*/
		EPP_AGGRESSION,
		/**
		*	判断
		*	球员对一个事件判断并据此作出反应的能力。有高判断属性的球员会很好地阅读比赛并比其他人更快地对新情况作出反应。这项属性与无球跑相得益彰。
		*	如果你的中场球员判断属性很高，他们更可能在比赛中作出更多的断球并因此使你的球队获得更多控球率。高的判断属性对后卫和前锋也都是十分重要的。它与无球跑(OFF THE BALL MOVEMENT)和决断(DECISIONS)相得益彰。
		*/
		EPP_ANTICIPATION,
		/**
		*	勇敢
		*	球员有敢于承担义务和勇敢。相对勇敢的球员会更愿意冒受伤的风险，而较不勇敢的就可能躲开这类情形。勇敢的球员会参与可能使自己受伤害的情形并甘心为球队冒风险。
		*	勇敢应该成为任何球员的必要属性。较高的勇敢属性会增加你的球员赢得双方机会均等（50%—50%）情况下的拼抢的机会，也一般会使他们去易受伤的地方。它与铲断相得益彰，而且你应注意大多的守门员的这项属性（注：原文是AND MOST GOALKEEPER STATS YOU CARE TO MENTION，似乎不是很通，不知我这样理解对不对）。
		*/
		EPP_BRAVERY,
		/**
		*	镇定
		*	球员心理和能力的坚定性，尤其在有球状态下。比如说，当面对射门得分的绝佳机会或承受高压力进行防守时，有较高镇定属性的球员会更能够保持冷静并时常作出较为理智的决定使球队获益。
		*/
		EPP_COMPOSURE,
		/**
		*	集中
		*	它反映球员对于场上每一件事情的集中程度。较高的集中属性意味着球员可以努力地集中更长时间，并能够像在比赛初一样在比赛后期对事件进行反应。较低的集中值会使球员丧失注意力并容易在比赛中关键时刻掉链子。
		*/
		EPP_CONCENTRATION,
		/**
		*	创造力
		*	它反映球员发现可能的空档的视野和能力，但不反映球员利用空档的能力。一个球员可能能够看见能加以利用的东西，但他也需具有熟练的技术来成功利用它。
		*	如果你在中场拥有创造性的球员，你就能够进更多球（注：有助攻能力）。最好用防守型中场支援他，因为创造力天才一般不是杰出的铲断手，当然，例外是有的……
		*/
		EPP_CREATIVITY,
		/**
		*	决断
		*	球员在大部分时间里作出正确决定的能力。这项属性对每个人都很重要，但可能对于中卫和中场更是如此。因为他们会经常得球并在此时拥有很多选择。
		*	快速的思考在令人兴奋的足球赛中相当关键。你会喜欢在激战正酣的时候能作出正确决定的球员。高决断值与创造力、传球和—较为次要的—判断属性相得益彰。
		*/
		EPP_DECISIONS,
		/**
		*	决心
		*	取得成功的信念。一个坚决的球员会为胜利贡献一切。这项属性与勇敢有联系—这两项属性中任意一项较高的球员可能另一项属性也会较高，因为这两种特性必然是类似的
		*	决心反映球员对获胜的欲望。这是对一支球队上下都十分好的属性。如果你在带一支较差的球队，当你在落后一两球时想扳平时，你可能会尤其需要决心值较高的球员。有高决心的球员会战斗到哨响前最后一刻。
		*/
		EPP_DETERMINATION,
		/**
		*	才华
		*	本能地作出有创造性和非常规的不可预测动作的能力。一个才华横溢的球员在任何球队都会是核心进攻成员之一，但同时他也需要战术上的克制以发挥最佳水平。才华和创造力相得益彰。
		*	一个才华横溢的球员可能导致球队遭遇很多挫折但同样地也可能凭一己之力赢得比赛。有些时候，当他将一脚倒钩球踢进看台，你会觉得他当时应该作出简单的传球；然而，也会有其它时候，你会起身为你所见过的最好的个人主义表演鼓掌喝彩。
		*/
		EPP_FLAIR,
		/**
		*	影响力
		*	影响力是球员非有意地影响事件或其他球员的能力。有较高影响力的球员会成为场上的领袖，队友们会倾向于团结在他们周围并重整旗鼓。
		*	一个具有较高影响力的球员会毫无疑问地成为队长的主要候选人。然而，还是请明智地选择。一个有较高影响力却看上去不让周围球员肃然起敬的球员将不会是好选择。请记住，即使当你已经选好了队长，在场上各处都拥有影响力较高的球员仍是好的。
		*/
		EPP_INFLUENCE,
		/**
		*	无球跑
		*	一个球员的无球移动。与判断(ANTICIPATION)类似，这是一个球员，尤其是进攻型球员，评定形势并以此进行无球移动，以让他们能够在有威胁位置接到传球的能力。
		*	无球跑恐怕是足球运动中最被疏忽的方面之一了，但FM把它看做最重要的之一。一个有较高无球跑属性的球员能够牵扯防线并通常给对手造成很多麻烦。试着寻找一个结合了无球跑、速度、位置感和判断的球员。
		*/
		EPP_OFFTHEBALL,
		/**
		*	位置感
		*	位置感是一个球员阅读状况并把自己摆在最好的位置以处理正演变的事件的能力。判断会在初期阶段帮助他，但是在实际站位这一方面是涉及到这项属性的。较好的位置感会确保球员占据一个更好的位置。
		*	如果你对越位陷阱这一战术感兴趣，你会知道位置感是你后卫需要具有的主要能力。它与强壮和判断结合起来，能够为球队营造出可靠的氛围。
		*/
		EPP_POSITIONING,
		/**
		*	团队合作
		*	球员按照战术指示比赛，为队友做事和与队友一同合作有多好。一个满是有高团队合作值的球队会更好地作为一个整体工作。属性较低的球员会松懈而且不会融入球队整体。
		*	如果你不是那种喜欢依靠超级球星赢得比赛的人，你会需要具有高团队合作属性的球员使球队融为一体。队中较高的团队合作值会使你的球员十分努力地为同伴工作。它与工作投入和决心相得益彰。
		*/
		EPP_TEAMWORK,
		/**
		*	工作投入
		*	它反映球员对于努力工作的心理驱动力。较高的属性会确保球员整场比赛都想不遗余力地工作，但他会需要必要的身体属性来在现实中实现它。虽然如此，它仍是极好的属性。
		*	就像之前提到过的一样，这是与高团队合作相得益彰的。如果你想让你的球队紧逼对手，中场球员的高工作投入值会相当有用。可是，也不要忘记保证他们有足够的体能……
		*/
		EPP_WORKRATE,

		//------------- 技术类属性(TECHNICAL ATTRIBUTES) ---------
		/**
		*	角球
		*	这项属性反映了这球员发角球有多好。在定位球上占有优势很重要，拥有一位能干的角球手将球发进关键区域是很有用的。
		*/
		EPP_CORNERS,
		/**
		*	传中
		*	这项属性反映球员将球从开阔区域（注：大概指球场两边）传进禁区的熟练程度。
		*	如果你想使边前卫/边锋和边后卫常下底，他们有向前锋送出好球的能力是万分重要的。训练中的定位球项目是提升这项属性的好方法。
		*/
		EPP_CROSSING,
		/**
		*	盘带
		*	这项属性是关于球员带球的能力的。这纯粹是关于他脚下带球的熟练度—他的速度（PACE）、爆发力（ACCELERATION）、灵活性（AGILITY）和平衡性（BALANCE）在不同情况下会帮助他的盘带。尽管较高的盘带属性会在不同的情况下帮助他，独自盘带也不会有什么好后果。
		*	我认为拥有一名结合灵活和平衡的好盘带手对你是十分重要的—尤其是当战术中有球员肩负拥有利用空间向对方后卫发动袭击这一职责时。如果你不拥有足够多的盘带手，请当心，尽管盘带手们会倾向于忽视你设定的任何传球策略。虽然一个盘带手可能凭借一己之力赢得比赛，他也可能在己方禁区内丢球并导致你输掉比赛。
		*/
		EPP_DRIBBLING,
		/**
		*	射门
		*	这名球员在得到机会时将球射进球门的能力。有较高的射门属性的球员会在大部分时候将球射正，而且会将球射向守门员不便扑救的地方。这纯粹是球员将球射得精准的能力。
		*	再简单不过了。射门属性较差=错失必进球。还要提醒你，你的球员必须处在合适的位置以进球，所以请确保你的球员同时也具有好的无球跑(OFF THE BALL）、平衡(BALANCE)和强壮(STRENGTH)属性。
		*/
		EPP_SHOOT,
		/**
		*	停球
		*	当得到球权时，球员的第一下触球有多好。较高的该属性会确保该球员能更快地将球拿住（注：原文是TRAP THE BALL）并放在有用的位置以便下一步行动。拥有较低该属性的球员会更加费劲地控球，且可能在得球时被立即紧逼的情况下丢失球权。
		*/
		EPP_FIRSTTOUCH,
		/**
		*	任意球
		*	这项属性反应该球员发任意球有多好。这对任意球直接射门和将球从更开阔、更深的位置发进危险区域都是有关的。一个精通任意球的球员可以成为一个十分有价值的“日用品“—每赛季进五个任意球球外加五个任意球助攻可是极大的额外加成。
		*/
		EPP_FREEKICKTAKING,
		/**
		*	头球
		*	这是球员在对空时的能力。头球属性对所有的对空情形都适用（注：大概是指不用脚的出球情况）。头球只是关于球员将球顶好的技术性能力。弹跳(JUMPING)和—较为次要的—强壮(STRENGTH)的结合，对于更好地利用头球能力十分重要。
		*	它对于你想用作“进攻核心”(TARGET MAN)和中后卫的球员都很重要。任何使用长传战术或要对付长传战术的球队都会想在己方拥有更多好的头球手。这项属性与弹跳（JUMPING）相得益彰。
		*/
		EPP_HEADING,
		/**
		*	远射
		*	这是球员从禁区外射门的威力。这在很大程度上是一个独立属性，但也请注意球员具有的任何有可能会对远射产生帮助的球员习惯动作（注：原文写的是”PPMS”，想来应该是PREFERRED PLAYER MOVES）。
		*	如果你的球员的射门不中目标，你永远不能进球。偶尔的一些远射也确实能考验一个机警的门将。一旦你确定你有一个像哈曼一样可以从中线射门的中场（注：应该是指远射很强），指示他多进行一些远射。他可能还很会发任意球呢……
		*/
		EPP_LONGSHOTS,
		/**
		*	界外球
		*	这是球员投掷能在进攻状况中使己方占据优势的界外球的能力。
		*	界外球能力对于边后卫来说尤其有用，因为你可能会想让他们投掷大多数的进攻界外球，以此来释放更多的进攻球员。
		*/
		EPP_LONGTHROWS,
		/**
		*	盯人
		*	球员，主要是防守类型球员盯对手盯得多好。如果他们此项属性很高，他们在人盯人时会做得很好。但请记住其它属性—强壮、无球跑、判断，和盯人者与被盯防者的身体能力—会对盯人的效力产生影响。
		*	如果一个后卫的盯人很差，这并不意味着他就是垃圾。然而，这种情况下你肯定想避免用盯人战术。如果你的后卫不能紧盯对手，也许你应该考虑使用清道夫系统或让后卫比你一般的设置中防得更深（注：后缩后防线）。在“软化”（注：大概是吓怕）对手方面，一个铲断凶狠的策略与盯人会配合得很好。
		*/
		EPP_MARKING,
		/**
		*	传球
		*	该球员传球有多好。他的技术和该项属性会决定他的长距离传球的结果。
		*	如果你有一队能与皇马中场有得一拼的中场球员（注：应该是指传球十分强），你就可以使用短传或混合传球以取得最佳效果。然而，你的中场更可能像一群提线木偶（注：指传球很糟），所以这时让他们长传更好。
		*/
		EPP_PASSING,
		/**
		*	罚点球
		*	球员在点球点前（罚球）的能力。属性较高的球员会在罚球时更加自信并能干。
		*	虽然这项属性十分独立（注：不受其它属性影响），我经常发现一个有较高影响力的球员（如球队队长）会在罚点球时出乎意料地成功并拥有将点球罚好的勇气。想想贝克汉姆吧……
		*/
		EPP_PENALTYTAKING,
		/**
		*	抢断
		*	球员不犯规顺利抢断有多成功。拥有较高抢断属性的球员会稳定延续地干净地抢球并成为更能干的防守球员。
		*	如果一个球员在拥有这项属性之余还有高水平的强壮、盯人，尤其是侵略性、勇敢，他将是一个杰出的防守者。这属性对于后卫和抢截性后腰是万分重要的。
		*/
		EPP_TACKLING,
		/**
		*	技术
		*	技术是球员比赛中在技巧方面给人的审美享受—球在他们脚下有多精致/多服帖（注：这句实在不好翻，原句是”TECHNIQUE IS THE AESTHETIC QUALITY OF A PLAYER’S TECHNICAL GAME - HOW REFINED THEY APPEAR TO BE WITH THE BALL”）。一个有高技术属性的球员比技术差的球员会更可能轻易地传出妙传或穿越全场的传球。这项属性会依次影响一系列的技术性属性—较差的技术属性会让球员表现上不了档次。
		*	技术或许是比较重要的属性之一。它在很大程度上涉及到自然的技巧，而不是在特定的区域或位置的专项技术。如果你想给对手留下深刻印象（注：大概指将对手打得很惨），寻找更多具有较好技术的进攻球员。
		*/
		EPP_TECHNIQUE,

		//------------- 身体类属性(PHYSICAL ATTRIBUTES) ---------
		/**
		*	爆发力
		*	爆发力是球员从静止到达最高速度（即身体属性中的速度—PACE）有多快。因此它与速度这一属性关系十分密切。
		*	作为球员到达最高速度的量度，爆发力是边路球员和速度型前锋必备的属性。当你面对试图进行快速反击的球队，你可能也会考虑使用爆发力好的后卫。好的体能(STAMINA)是必要的，一点工作投入也会对此有帮助。
		*/
		EPP_ACCELERATION,
		/**
		*	灵活
		*	灵活反映了球员启动、停止和变速（速度属性—PACE）、变向移动的能力。在比赛引擎中，它与速度、爆发力和平衡属性紧密结合，尤其是当一个球员带球跑时。
		*	灵活属性在一流水平的环境中最为重要。你可以在低水平联赛中轻易地摆脱笨重的球员，但是顶级联赛中甚至中后卫都有一定的灵敏性。如果与爆发力和盘带结合，较高的灵活属性可以造就一个杰出的进攻球员。
		*/
		EPP_AGILITY,
		/**
		*	平衡
		*	平衡反映球员在有球和无球状态下保持平衡的能力。有球时，它反映球员带球跑和躲避对手时有多平衡；无球时，它反映球员面对向他袭来的对手时的平衡，或是他转身和弹跳时的稳定性。
		*	虽然凭着职业基础，所有的足球运动员都具备一定的平衡能力，最需要该项属性的人是作为铲断和踢击的攻击目标的球员。对手会很难从结合了平衡、灵活、盘带或强壮的球员脚下断球。
		*/
		EPP_BALANCE,
		/**
		*	弹跳
		*	这项数值涉及的是球员从初始状态可以跳多高。
		*	这属性很好理解。你需要将它与较高的头球(HEADING)属性结合。如果你想打长传球战术或频繁传中的战术，你必须确保你的球员善于弹跳。如果有高弹跳值的球员勇敢和侵略性也很高，让他们进行凶狠的铲断以真正统治对手。
		*/
		EPP_JUMPING,
		/**
		*	体质
		*	球员在一个基础水平上有多健康。（HOW FIT A PLAYER IS AS STANDARD - HIS BASE LEVEL OF FITNESS.）它影响球员在变得显著疲劳和易受伤前能够以身体的巅峰状态打多少场比赛。
		*	体质应该和身体的疲劳累积速度有关，也就间接地影响了体能的恢复。如果让体质差的球员连续打高强度的比赛，那么他就易体力不支，进入疲劳状态并容易受伤，教练就需要让他轮休。反之，像特里、兰帕德，本德兄弟，库伊特这种铁人就可以一直首发上场从不间断。某些人理解的是“保持职业生涯巅峰期”的能力显然是不对的。职业生涯巅峰的保持和很多因素都相关，如球员的比赛水平、训练（职业道德）、伤病等等，而体质其实和这关系不大。
		*/
		EPP_NATURALFITNESS,
		/**
		*	速度
		*	“速度”即球员的最高速度。爆发力(ACCELERATION)反映球员到达最高速度有多快，而速度(PACE)就是这里面的“最高速度”。结合考量耐力和体质可以得出球员在短距离冲刺和整场比赛进程中能够保持这一最高速度多久。一个球员会在无球时会自然比有球时快一点。
		*	其实“PACE（速度）”这一词可以说是有一点用词不当，所以请小心了。你的球员可能会像闪电般地快，但如果他拿着球却不能做任何事，他很快就会成为一定的负担。注意把速度和才华、盘带、灵活和—当然—爆发力结合考量。让你跑得快的球员从纵深发动进攻以真正地给对方防守造成恐慌。
		*/
		EPP_PACE,
		/**
		*	耐力
		*	耐力是球员长时间忍耐高强度的身体活动的能力。承受着九个月的漫长赛季，有较高耐力的球员能够以最高水平发挥更久。它直接与体质相关。
		*	耐力的重要性不应被忽视—尤其当你使用及其耗力的打法，如紧逼打法，集体逼抢或让某些球员经常前插时。如果你的球队整体上耐力较差，你很可能在比赛某段丢球。你已经被警告了……
		*/
		EPP_STAMINA,
		/**
		*	强壮
		*	耐力是球员长时间忍耐高强度的身体活动的能力。承受着九个月的漫长赛季，有较高耐力的球员能够以最高水平发挥更久。它直接与体质相关。强壮是球员施加他的身体力量于对方球员从而使自己获益的能力。一个较强壮的球员会能够凭借它对较弱的对手占据优势。
		*	强壮是在抢球是很重要的因素，所以你需要拥有一定的能够在情况变得艰巨（、粗暴？）（ROUGH）时利用强壮的球员。抢断（TACKLING）、弹跳和盯人和强壮相得益彰。而且你会发现强壮的球员不会过于经常地犯规，因为他们通常可以用力气使对方丢球而不一定要滑铲。
		*/
		EPP_STRENGTH,

		//------------- 守门员属性(GOALKEEPER ATTRIBUTES) ---------
		/**
		*	制空能力
		*	这是守门员对付在高空中的球的能力—拳击球和抓球（注：从十分高处而来的）。具有较高制空能力的守门员会可以能干地对付这些可能棘手的问题。较高的守门员在这方面也具有优势，但这并不意味着较矮的守门员在这方面就会较为艰难。
		*	这是从高空中摘球的能力。一个出击却只是将球拍出的守门员会在防守队员间造成惊慌。较好的制空能力对付喜欢传中或打长传的球队是很有用的。
		*/
		EPP_AERIALABILITY,
		/**
		*	指挥防守
		*	这是守门员对付在高空中的球的能力—拳击球和抓球（注：从十分高处而来的）。具有较高制空能力的守门员会可以能干地对付这些可能棘手的问题。较高的守门员在这方面也具有优势，但这并不意味着较矮的守门员在这方面就会较为艰难。它影响守门员负责他的禁区并与后防线协作的能力。一个能够支配整个禁区（也就是有较高此属性）的守门员会有一种（注：支配的）本能并试着负责局势（即自己得球），尤其是对于传中球（因此这属性与制空能力有关）。然而注意，较高的该属性只增加他对于摘下传中球的倾向而不等同于摘下它们的技术能力。
		*	一个具有较高该属性的守门员会十分机动并常常在禁区内移动。他会在对付定位球时最好地展示该项属性—知道何时要扑救并确保他这样做时能够得到球。
		*/
		EPP_COMMANDOFAREA,
		/**
		*	交流
		*	守门员与后防线交流并组织球队的防守有多好。较高的属性反映该门将是更好的交流者，会使你的后防5人（或更多）一起合作得更好，确保更好的防守稳定性。
		*	如果你想拥有组织良好的防守，一个交流能力较好的门将十分必要。想象彼得·舒梅切尔吧……
		*/
		EPP_COMMUNICATION,
		/**
		*	激情
		*	这项属性代表守门员完全不像一个门将一样，作出意外的、有特色的动作的可能性。如果激情属性高，像将球盘带出禁区一类的事情会变得司空见惯。
		*	一个富有激情的门将是一把双刃剑。他可能作出瞬间的天才动作，但同样地，你可能发现他在完全不可能比对方前锋先得球时冲出禁区。如果你喜欢一个有一些个性的球员，较低的激情属性—在我看来—不见得是好东西。
		*/
		EPP_ECCENTRICITY,
		/**
		*	手控球
		*	守门员扑救或拿住失去控制的球有多安全（拿得有多稳）。较好的手控球属性会在不理想的天气情况下更为有利，但总体上来说一个不经常脱手的门将也是很有用的。
		*	这真正是一项你需要在守门员中留心寻找的属性。抓不住球=不利。
		*/
		EPP_HANDLING,
		/**
		*	大脚球
		*	守门员身体上的踢球能力—这纯粹定义球能够达到的距离。他的传球和技术属性会定义他的开球有多精准。
		*	如果你使用长传战术，确保你的守门员大脚球属性较好。他将能够把球从小禁区开到进攻核心的头上。如果守门员大脚球属性较差，让他将球直接给到后卫脚下。
		*/
		EPP_KICKING,
		/**
		*	一对一
		*	守门员在一对一情况下做得好的能力。较高的一对一属性会使守门员尝试（注：正面）影响自己，并自信地扑救成功。
		*/
		EPP_ONEONONES,
		/**
		*	反应
		*	守门员作出本能的反应进行扑救有多好。如果他的反应属性较好，他将能够对那不可预知（注：的各种需要扑救的情况）更成功地进行反应并能够作出连串精彩扑救。
		*	这是门将需要拥有的绝佳属性，它指示他作出本能的扑救有多好—尤其是扑救近距离射门。它与好的手控球和灵活结合以保证球队失球达到最小。
		*/
		EPP_REFLEXES,
		/**
		*	出击
		*	守门员作出本能的反应进行扑救有多好。如果他的反应属性较好，他将能够对那不可预知（注：的各种需要扑救的情况）更成功地进行反应并能够作出连串精彩扑救。守门员从球门线区域出来对直塞球和类似情况的反应有多好。爆发力和速度会对出击有辅助作用。
		*	如果球队使用造越位战术或对手有极快的前锋，这是很有用的属性。你的守门员会在你开始叫喊“快出击呀！”之前出来对付对手……呃……
		*/
		EPP_RUSHINGOUT,
		/**
		*	击球倾向
		*	它决定守门员在能够抓住球的情况下是主动抓球，还是用拳击球。较高的属性反应守门员（在甚至可能抓球时也）会更倾向于击球。
		*	在近几年的英超中我们可以看见更多球队开始聘用欧洲大陆门将。是否参考这项属性纯粹是个人选择—击球可以立即清除危险，但情况仍可能有一定风险。不推荐较高的该属性与弱且不可靠的防守搭配。
		*/
		EPP_TENDENCYTOPUNCH,
		/**
		*	手抛球
		*	守门员用他的双臂分球有多好。较高的属性会提高手抛球的准确性，尽管强壮决定手抛球的距离。
		*	如果你喜欢让球队打快速反击，手抛球较准的门将是必要的。一旦控球，他会立即把球交给在半场的前锋……
		*/
		EPP_THROWING,

		EPP_MAX,
	};
}