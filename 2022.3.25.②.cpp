#include"Seqlist.h"

int main(int argc, char* argv[])
{
	Seqlist mylist;
	SeqlistInit(&mylist, 8);
	ElemType item;
	int pos;
	int select = 1;
	while(select)
	{
		printf("******************************************\n");
		printf("* [1]push_back         [2]push_front     *\n");
		printf("* [3]show_list         [0]quit_system    *\n");
		printf("* [4]pop_back          [5]pop_front      *\n");
		printf("* [6]insert_pos        [7]insert_val     *\n");
		printf("* [8] erase_pos        [9] erase_val     *\n");
		printf("* [10] find_pos        [11] find_val     *\n");
		printf("* [12] sort            [13] reverse      *\n");
		printf("* [14] length          [15] capacity     *\n");
		printf("* [16] clear           [*17] destroy     *\n");
		printf("******************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		if(select==0)
			break;

		switch (select)
		{
		case 1:
			printf("请输入要插入的数,以-1结尾.\n");
			while (scanf("%d", &item), item != -1) 
			{
				SeqlistPushBack(&mylist,item);
			}
			break;

		case 2:
			printf("请输入要插入的数,以-1结尾.\n");
			while(scanf("%d",&item),item!=-1)
			{
				SeqlistPushFront(&mylist, item);
			}
			break;

		case 3:
			SeqlistShowList(&mylist);
			break;

		case 4:
			SeqlistPopBack(&mylist);
			break;
		case 5:
			SeqlistPopFront(&mylist);
			break;
		case 6:
			printf("请输入要插入的数:\n");
			scanf("%d", &item);
			printf("请输入要插入的位置:\n");
			scanf("%d", &pos);
			SeqlistInsertPos(&mylist, pos, item);
			break;
		case 14:
			printf("顺序表的长度为:%d", SeqlistLength(&mylist));
			printf("\n");
			break;
		default:
			break;
		}
		
	}

}