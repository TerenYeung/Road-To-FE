PLIST LICreate()
{
  PLIST p = new LIST;
  p->cout = 0;
  p->head = NULL;
  P->tail = NULL;
  return p;
}

void LIDestory(PLIST list)
{
  if(list)
  {
    LICLear(list);
    delete list;
  }
}

void LICLear(PLIST list)
{
  if (!list)
  {
    cout << "LIClear: Parameter illegal." << endl;
    exit(1);
  }
  while(list->head)
  {
    PNODE t = list->head;
    list->head = t->next;
    PtDestroy(t->data);
    delete t;
    list->count--;
  }
  list->tail = NULL;
}
// 结点的追加
void LIAppend(PLIST, PPOINT point)
{
  PNODE t = new NODE;
  if(!list || !point)
  {
    cout << "LIAppend: Parameter illegal." << endl;
    exit(1);
  }
  t->data = point;
  t->next = NULL;
  if(!list->head)
  {
    list->head = t;
    list->tail = t;
  }
  else
  {
    list->tail->next = t;
    list->tail = t;
  }
  list->count++;
}

// 结点的插入
void LIInsert(PLIST list, PPOINT point, unsigned int pos)
{
  if(!list || !point)
  {
    cout << "LIInsert: Parameter illegal." <<endl;
    exit(1);
  }
  if(pos < list->count)
  {
    PNODE t = new NODE;
    t->data = point;
    t->next = NULL;
    if(pos == 0)
    {
      t->next = list->head;
      list->head = t;
    }
    else
    {
      unsigned int i;
      PNODE u = list->head;
      for(i=0; i<pos-1; ++i)
        u = u->next;
      t->next = u->next;
      u->next = t;
    }
    list->count++;
  }
  else
  {
    LIAppend(list, point)
  }
}

// 结点的删除
void LIDelete(PLIST list, unsigned int pos)
{
  if(!list)
  {
    cout << "LIDelete: Parameter illegal." << endl;
    exit(1);
  }
  if(list->count == 0)
    return;
  if(pos==0)
  {
    PNODE t = list->head;
    list->head = t->next;
    if(!t->next)
      list->tail = NULL;
    PtDestroy(t->data);
    delete t;
    list->count--
  }
}

// 链表的遍历
void LITraverse(PLIST list)
{
  PNODE t = list->head;
  if(!list)
  {
    cout << "LITraverse:Parameter illegal." << endl;
    exit(1);
  }
  while(t)
  {
    cout << PtTransformIntoString(t->data) << "->";
    t = t->next;
  }
  cout << "NULL\n";
}

// 链表的查找
bool LISearch(PLIST list, PPOINT point)
{
  PNODE t = list->head;
  if(!list || !point)
  {
    cout << "LISearch:Parameter illegal." <<endl;
    exit(1);
  }
  while(t)
  {
    if(PtCompare(t->data, point))
      return true;
    t = t->next;
  }
  return false;
}
