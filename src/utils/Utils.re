module Dom = UtilsDom;

let optionFromRef = ref => ref->React.Ref.current->Js.Nullable.toOption;